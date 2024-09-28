//
// Created by stg05 on 21.09.2024.
//

#include <random>
#include <iostream>

class RandomVariable {
public:
    RandomVariable() = default;

    virtual unsigned roll() = 0;

    virtual ~RandomVariable() = default;
};

class Dice : public RandomVariable {
public:
    Dice(unsigned max, unsigned seed) :
            dstr_1(1, max), reng_1(seed) {}

    unsigned roll() override {
        return dstr_1(reng_1);
    }

protected:
    std::uniform_int_distribution<unsigned> dstr_1;
    std::default_random_engine reng_1;
};

class ThreeDicePool : public RandomVariable {
public:
    ThreeDicePool(RandomVariable *r1, RandomVariable *r2, RandomVariable *r3) :
            m_r1{r1}, m_r2{r2}, m_r3{r3} {};

    unsigned roll() override {
        return m_r1->roll() + m_r2->roll() + m_r3->roll();
    }

protected:
    RandomVariable *m_r1, *m_r2, *m_r3;
};

class PenaltyDice : public virtual RandomVariable {
public:
    explicit PenaltyDice(RandomVariable *r) :
            m_r{r} {};

    unsigned roll() override {
        return std::min(m_r->roll(), m_r->roll());
    }

private:
    RandomVariable *m_r;
};

class BonusDice : public virtual RandomVariable {
public:
    explicit BonusDice(RandomVariable *r) :
            m_r{r} {};

    unsigned roll() override {
        return std::max(m_r->roll(), m_r->roll());
    }

private:
    RandomVariable *m_r;
};

class DoubleDice : public BonusDice, public PenaltyDice {
public:
    explicit DoubleDice(Dice &d) : BonusDice(&d), PenaltyDice(&d) {};
    unsigned roll() override{
        return BonusDice::roll() + PenaltyDice::roll();
    }
};

double expected_value(RandomVariable &d, unsigned number_of_rolls = 1) {
    auto accum = 0llu;
    for (unsigned cnt = 0; cnt != number_of_rolls; ++cnt)
        accum += d.roll();
    return static_cast<double>(accum) / static_cast<double>(number_of_rolls);
}

struct probability {
    double value;
    unsigned multiplier;
};

probability
value_probability(unsigned value, RandomVariable &d, unsigned number_of_rolls = 1, unsigned multiplier = 20) {
    unsigned counter = 0;
    for (unsigned cnt = 0; cnt < number_of_rolls; cnt++) {
        if (value == d.roll()) {
            counter++;
        }
    }
    return probability{static_cast<double>(counter) / static_cast<double>(number_of_rolls), multiplier};
}

std::ostream &operator<<(std::ostream &os, probability pr) {
    int asterisks = (int) (pr.value * pr.multiplier);
    for (int i = 0; i < asterisks; i++) {
        os << '*';
    }
    return os;
}

int main() {
    Dice dice1{100, 42932};
    Dice dice2{6, 32215};
    Dice dice3{6, 74352};
    DoubleDice d{dice1};

    for (int i = 1; i <= 210; i++) {
        std::cout.width(3);
        std::cout << i << " : " << value_probability(i, d, 50000, 5000) << "\n";
    }
    return 0;
}
