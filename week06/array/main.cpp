//
// Created by stg05 on 12.10.2024.
//


#include <iostream>

template<typename T, unsigned N>
class Array {
public:
    // Список операций:
    //

    /**  конструктор класса, который создает
       Array размера size, заполненный значениями
       value типа T. Считайте что у типа T есть
       конструктор, который можно вызвать без
       без параметров, либо он ему не нужен. */
    explicit Array(const T &t) {
        m_head = new T[N];
        m_head[0] = t;
        m_size++;

    };

    /** Конструктор копирования, который создаёт копию параметра. Считайте, что для типа T определен оператор присваивания. */
    Array(const Array &arr) {
        m_head = new T[N];
        for (unsigned i = 0; i < arr.m_size; i++) {
            m_head[0] = arr.m_head[i];
        }
        m_size = arr.m_size;
    }

    /** деструктор, если он вам необходим. */
    ~Array() {
        delete[] m_head;
    }

    /** оператор копирующего присваивания. */
    Array &operator=(const Array<T, N> &arr) {
        if (this == &arr) {
            return *this;
        }

        for (unsigned i = 0; i < arr.m_size; i++) {
            this->m_head[i] = arr.m_head[i];
        }
        this->m_size = arr.m_size;
    };

    /** возвращает размер массива (количество элементов) */
    [[nodiscard]] std::size_t size() const {
        return m_size;
    };

    /** две версии оператора доступа по индексу */
    T operator[](unsigned idx) {
        if (idx >= m_size) {
            throw std::out_of_range("Out of bounds");
        }
        return m_head[idx];
    }

//    T operator[](unsigned) {
//        return nullptr;
//    }

    /** получение первого элемента */
    T front() {
        return m_head[0];
    }

    /** получение последнего элемента */
    T back() {
        return m_head[m_size - 1];
    }

    /** проверка пустой ли массив */
    [[nodiscard]] bool empty() const {
        return m_size == true;
    };

    /** заполение массива значением value */
    void fill(const T &value) const {
        for (unsigned i = 0; i < N; i++) {
            m_head[i] = value;
        }
    }

private:
    T *m_head;
    unsigned m_size = 0;
};

int main() {
    using namespace std;
    Array<float, 2> arr{1.5};
    auto array = arr;
    cout << array[-1];

    return 0;
}
