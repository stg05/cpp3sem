#include <iostream>

template <typename T>
class Grid final
{
public:
    using value_type = T;
    using size_type = unsigned;

private:
    T *data;
    size_type const m_y_size, m_x_size;

public:

    Grid<T>(size_type y_size, size_type x_size) : m_y_size(y_size), m_x_size(x_size), data(new T[x_size*y_size])
    {
        
    }

    // Copy constructor
    Grid(Grid<T> const &) = delete;

    // Move constructor
    Grid(Grid<T> &&) = delete;

    // Copy assginment
    Grid<T> &operator=(Grid<T> &) = delete;

    // Move assignment
    Grid<T> &operator=(Grid<T> &&) = delete;

    T operator()(size_type y_idx, size_type x_idx) const
    {
        return data[y_idx * m_x_size + x_idx];
    }

    T &operator()(size_type y_idx, size_type x_idx)
    {
        return data[y_idx * m_x_size + x_idx];
    }

    Grid<T> &operator=(T const &t)
    {
        for (auto it = data, end = data + m_x_size * m_y_size; it != end; ++it)
            *it = t;
        return *this;
    }

    size_type get_y_size() const { return m_y_size; }
    size_type get_x_size() const { return m_x_size; }

    ~Grid()
    {
        delete[] data;
    }
};

int main()
{
    Grid<int> g(10, 10);
    std::cout << "HII" << std::endl;

    return 0;
}