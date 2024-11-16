#include <iostream>

template <typename T, unsigned Dimension>
class Grid;

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

public:
    Grid<T, 1>(T &&value)
    {
        data = new T[1];
        dim_size = 1;
        data[0] = value;
    }

    Grid(size_type size, T const &fill_value) : dim_size{size}
    {
        data = new T[size];
        for (size_type i = 0; i < size; i++)
        {
            data[i] = fill_value;
        }
    }

    // Copy constructor
    Grid(Grid<T, 1> const &other)
    {
        size_type other_size = other.dim_size;
        data = new T[other_size];
        dim_size = other_size;
        for (size_type i = 0; i < other_size; i++)
        {
            data[i] = other.data[i];
        }
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
        delete[] data;
        // std::cout << "del data (Dim=1), size = " << dim_size << std::endl;
    }
};

template <typename T, unsigned Dimension>
class Grid
{
public:
    static_assert(Dimension > 0, "Zero-dimensional array");
    using value_type = T;
    using size_type = unsigned;

private:
    Grid<T, Dimension - 1> **m_subgrids;
    size_type dim_size;

public:
    template <typename First, typename... Rest>
    Grid(First first, Rest... rest) : dim_size{first}
    {
        m_subgrids = static_cast<Grid<T, Dimension - 1> **>(::operator new(sizeof(Grid<T, Dimension - 1>) * first));
        for (size_type i = 0; i < first; i++)
        {
            m_subgrids[i] = new Grid<T, Dimension - 1>(rest...);
        }
    }

    // Copy constructor
    Grid(Grid<T, Dimension> const &other)
    {
        size_type other_size = other.dim_size;
        dim_size = other_size;
        m_subgrids = static_cast<Grid<T, Dimension - 1> **>(::operator new(sizeof(Grid<T, Dimension - 1>) * other_size));

        for (size_type i = 0; i < other_size; i++)
        {
            m_subgrids[i] = new Grid<T, Dimension - 1>(*(other.m_subgrids[i]));
        }
    }

    // Move constructor
    Grid(Grid<T, Dimension> &&other)
    {
        size_type other_size = other.dim_size;
        dim_size = other_size;
        m_subgrids = static_cast<Grid<T, Dimension - 1> **>(::operator new(sizeof(Grid<T, Dimension - 1>) * other_size));

        for (size_type i = 0; i < other_size; i++)
        {
            m_subgrids[i] = new Grid<T, Dimension - 1>(*(other.m_subgrids[i]));
        }
    }

    Grid<T, Dimension> &operator=(Grid<T, Dimension> &rhs)
    {
            
    }
    Grid<T, Dimension> &operator=(Grid<T, Dimension> &&rhs)
    {
    }

    // Copying operator

    Grid<T, Dimension - 1> &operator[](size_type rhs)
    {
        if ((rhs < 0) || (rhs >= dim_size))
            throw std::out_of_range("Out of bounds");
        return *m_subgrids[rhs];
    }

    ~Grid()
    {
        for (size_type i = 0; i < dim_size; i++)
        {
            delete m_subgrids[i];
        }
        // std::cout << "Subgrids of dim " << Dimension - 1 << " del'd, proceeding to this of dim "
        //           << Dimension << " with " << dim_size << " subgrids." << std::endl;

        delete m_subgrids; // #TODO почему не delete[]? (тогда в valgrind будет mismatch)
    }
};

// template <typename T>
// class Grid final
// {
// public:
//     using value_type = T;
//     using size_type = unsigned;

// private:
//     T *data;
//     size_type const m_y_size, m_x_size;

// public:
//     Grid<T>(size_type y_size, size_type x_size) : m_y_size(y_size), m_x_size(x_size), data(new T[x_size * y_size])
//     {
//     }

//     Grid(T const &t)
//     {
//         data = new T[1];
//         data[0] = t;
//     }

//     // Copy constructor
//     Grid(Grid<T> const &) = delete;

//     // Move constructor
//     Grid(Grid<T> &&) = delete;

//     // Copy assginment
//     Grid<T> &operator=(Grid<T> &) = delete;

//     // Move assignment
//     Grid<T> &operator=(Grid<T> &&) = delete;

int main()
{
    Grid<int, 3> g(2u, 1U, 2U, 200);
    int i = 0;
    Grid<int, 1> g2(100);
    // auto g2(g);
    std::cout << "HII" << " " << g2[0] << std::endl;
    return 0;
}