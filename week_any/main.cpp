#include <cstdint>


class CompactSet {
    uint64_t set;
    int const min;
public:
    explicit CompactSet(int min);

    CompactSet();

    bool ensure(int x);

    bool remove(int x);

    bool is_empty() const;

    bool contains(int x) const;
};

CompactSet::CompactSet(int min_p) : set{0}, min{min_p} {}

CompactSet::CompactSet() : CompactSet(0) {}

bool CompactSet::contains(int const x) const {
    if (x < min + 64) {
        if ((set >> (x - min)) == 1) {
            return true;
        }
    }
    return false;
}

bool CompactSet::is_empty() const {
    return set == 0u;
}

bool CompactSet::ensure(int x) {
    bool res = !contains(x);
    if (res) {
        if (x < min + 64) {
            set += (1 << (x - min));
        }
    }
    return res;
}

bool CompactSet::remove(int x) {
    bool res = contains(x);
    if (res) {
        if (x < min + 64) {
            set -= (1 << (x - min));
        }
    }
    return res;
}


#include <iostream>
#include <cassert>

int main() {
    CompactSet set(-1024);
    set.ensure(-1023);
    std::cout << set.contains(-1024) << std::endl;

    return 0;
}

/** Ваш код **/