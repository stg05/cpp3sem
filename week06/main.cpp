#include <iostream>
#include <cassert>
#include <type_traits>

template <typename T, unsigned Dimension>
class Grid;

template <typename T, unsigned Dimension>
class Grid
{
public:
    static_assert(Dimension > 0, "Zero-dimensional array");
    using value_type = T;
    using size_type = unsigned;

private:
    Grid<T, Dimension - 1> *m_subgrids;
    size_type dim_size;
    // todo allocate
    void mem_allocate(size_type size)
    {
        m_subgrids = static_cast<Grid<T, Dimension - 1> *>(::operator new(sizeof(Grid<T, Dimension - 1>) * size));
    }

    void mem_free()
    {
        delete m_subgrids;
    }

public:
    template <typename First, typename... Rest, std::enable_if_t<(sizeof...(Rest) > 0), bool> = true>
    Grid(const First first, const Rest... rest) : dim_size{(size_type)first}
    {
        mem_allocate(dim_size);

        for (size_type i = 0; i < first; i++)
        {
            new (m_subgrids + i) Grid<T, Dimension - 1>(rest...);
        }
    }

    // Copy constructor
    Grid(Grid<T, Dimension> const &other)
    {
        dim_size = other.dim_size;
        mem_allocate(dim_size);

        for (size_type i = 0; i < dim_size; i++)
        {
            m_subgrids[i] = Grid<T, Dimension - 1>(other.m_subgrids[i]);
        }
    }

    // Move constructor
    Grid(Grid<T, Dimension> &&other)
    {
        dim_size = other.dim_size;
        mem_allocate(dim_size);

        for (size_type i = 0; i < dim_size; i++)
        {
            std::swap(m_subgrids[i], other.m_subgrids[i]);
        }
    }

    Grid<T, Dimension> &operator=(const Grid<T, Dimension> &rhs)
    {
        if (this == &rhs)
            return *this;
        // copy and swap

        if (this->dim_size != rhs.dim_size)
        {
            this->mem_free();
            this->dim_size = rhs.dim_size;
            this->mem_allocate(this->dim_size);
        }
        std::copy(rhs.m_subgrids, rhs.m_subgrids + rhs.dim_size, this->m_subgrids);
        return *this;
    }

    Grid<T, Dimension> &operator=(Grid<T, Dimension> &&rhs)
    {
        if (this == &rhs)
            return *this;
        if (this->dim_size != rhs.dim_size)
        {
            this->mem_free();
            this->dim_size = rhs.dim_size;
            this->mem_allocate(this->dim_size);
        }
        std::swap(this->m_subgrids, rhs.m_subgrids);
        return *this;
    }

    // Copying operator
    // non const version
    const Grid<T, Dimension - 1> &operator[](size_type rhs) const
    {
        if ((rhs < 0) || (rhs >= dim_size))
            throw std::out_of_range("Out of bounds");
        return m_subgrids[rhs];
    }

    Grid<T, Dimension - 1> &operator[](size_type rhs)
    {
        if ((rhs < 0) || (rhs >= dim_size))
            throw std::out_of_range("Out of bounds");
        return m_subgrids[rhs];
    }

    ~Grid()
    {
        mem_free(); // #TODO почему не delete[]? (тогда в valgrind будет mismatch)
    }
};

/* Specialization for 1-dim array */
template <typename T>
class Grid<T, 1>
{
public:
    using value_type = T;
    using size_type = unsigned;

private:
    T *data;
    size_type dim_size;
    void mem_allocate(size_type size)
    {
        data = new T[size];
    }

    void mem_free()
    {
        delete[] data;
    }

public:
    Grid(const T value)
    {
        data = new T[1];
        dim_size = 1;
        data[0] = value;
    }

    Grid(size_type size, T const &fill_value) : dim_size{size}
    {
        mem_allocate(size);
        for (size_type i = 0; i < size; i++)
        {
            data[i] = fill_value;
        }
    }

    // Copy constructor
    Grid(Grid<T, 1> const &other)
    {
        dim_size = other.dim_size;
        mem_allocate(dim_size);

        for (size_type i = 0; i < dim_size; i++)
        {
            data[i] = other.data[i];
        }
    }

    const T &operator[](size_type rhs) const
    {
        if ((rhs < 0) || (rhs >= dim_size))
            throw std::out_of_range("Out of bounds");
        return data[rhs];
    }

    T &operator[](size_type rhs)
    {
        if ((rhs < 0) || (rhs >= dim_size))
            throw std::out_of_range("Out of bounds");
        return data[rhs];
    }

    ~Grid()
    {
        // std::cout << "trying" << std::endl;
        mem_free();
        // std::cout << "del data (Dim=1), size = " << dim_size << std::endl;
    }
};

int main()
{
    // Grid<float, 3> const g3(10, 10, 10, 1.00f);
    // assert(1.0f == g3[1][1][1]);

    Grid<float, 2> g2(2, 5, 2.0f);
    assert(2.0f == g2[1][1]);

    // g2 = g3[1];
    // assert(1.0f == g2[1][1]);

    // auto g1 = Grid<unsigned, 1>(1u);
    return 0;
}