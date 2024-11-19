#include <iostream>
#include <cassert>
#include <type_traits>

template <typename T, unsigned Dimension>
class Grid;

template <typename T, unsigned Dimension> // Todo operator skobochki
class Grid
{
public:
    static_assert(Dimension > 0, "Zero-dimensional array");
    using value_type = T;
    using size_type = unsigned;

private:
    Grid<T, Dimension - 1> *m_subgrids;
    size_type dim_size;

    /** Allocating a buffer of a specific size for subgrids of inferior dimensions */
    void mem_allocate(size_type size)
    {
        m_subgrids = static_cast<Grid<T, Dimension - 1> *>(::operator new(sizeof(Grid<T, Dimension - 1>) * size));
    }

    /** Deleting the buffer: firstly recursively remove objects placed into the buffer via
     * placement news (by manually calling destructors), then freeing the buffer itself. */
    void mem_free()
    {
        for (size_type i = 0; i < dim_size; i++)
        {
            (m_subgrids + i)->~Grid<T, Dimension - 1>();
        }

        ::operator delete(m_subgrids);
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

    /** Copy constructor (does not mutate the argument as may be seen from the signature) */
    Grid(Grid<T, Dimension> const &other)
    {
        dim_size = other.dim_size;
        mem_allocate(dim_size);

        for (size_type i = 0; i < dim_size; i++)
        {
            m_subgrids[i] = Grid<T, Dimension - 1>(other.m_subgrids[i]);
        }
    }

    /** Move constructor (possibly takes rvalue as an argument) */
    Grid(Grid<T, Dimension> &&other)
    {
        dim_size = other.dim_size;
        mem_allocate(dim_size);

        for (size_type i = 0; i < dim_size; i++)
        {
            std::swap(m_subgrids[i], other.m_subgrids[i]);
        }
    }

    /** Copy assignment */
    Grid<T, Dimension> &operator=(const Grid<T, Dimension> &rhs)
    {
        // Self-assignment check
        if (this == &rhs)
        {
            return *this;
        }
        // Reallocating the buffer if only dim-sizes do not correspond
        if (this->dim_size != rhs.dim_size)
        {
            this->mem_free();
            this->dim_size = rhs.dim_size;
            this->mem_allocate(this->dim_size);
        }
        // Utilizing copy-construction [recursively]
        for (size_type i = 0; i < this->dim_size; i++)
        {
            new (m_subgrids + i) Grid<T, Dimension - 1>(rhs.m_subgrids[i]);
        }
        return *this;
    }

    /** Move assignment */
    Grid<T, Dimension> &operator=(Grid<T, Dimension> &&rhs)
    {
        // Self-assignment check
        if (this == &rhs)
            return *this;
        // Reallocating the buffer if only dim-sizes do not correspond
        if (this->dim_size != rhs.dim_size)
        {
            this->mem_free();
            this->dim_size = rhs.dim_size;
            this->mem_allocate(this->dim_size);
        }
        // Merely swapping the contents
        std::swap(this->m_subgrids, rhs.m_subgrids);
        return *this;
    }

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

    /** Template for functor op.: returning one of recursively obtained subgrids */
    template <typename First, typename... Rest>
    typename std::enable_if<(Dimension == sizeof...(Rest) + 1), T &>::type
    operator()(First first, Rest... rest)
    {
        return this->m_subgrids[(size_type)first](rest...);
    }

    /** Template for functor op.: returning value of the lowest-level subgrid */
    template <typename First, typename... Rest>
    typename std::enable_if<(Dimension > sizeof...(Rest) + 1), Grid<T, Dimension - sizeof...(Rest) - 1> &>::type
    operator()(First first, Rest... rest)
    {
        return this->m_subgrids[(size_type)first](rest...);
    }

    /** Template for functor op.: finalizing the recursion for subgrid returning */
    template <typename First>
    typename std::enable_if<(Dimension > 1), Grid<T, Dimension - 1> &>::type
    operator()(First first)
    {
        return this->m_subgrids[(size_type)first];
    }

    /** Template for functor op.: returning one of recursively obtained subgrids */
    template <typename First, typename... Rest>
    typename std::enable_if<(Dimension == sizeof...(Rest) + 1), const T &>::type
    operator()(First first, Rest... rest) const
    {
        return this->m_subgrids[(size_type)first](rest...);
    }

    /** Template for functor op.: returning value of the lowest-level subgrid */
    template <typename First, typename... Rest>
    typename std::enable_if<(Dimension > sizeof...(Rest) + 1), const Grid<T, Dimension - sizeof...(Rest) - 1> &>::type
    operator()(First first, Rest... rest) const
    {
        return this->m_subgrids[(size_type)first](rest...);
    }

    /** Template for functor op.: finalizing the recursion for subgrid returning */
    template <typename First>
    typename std::enable_if<(Dimension > 1), const Grid<T, Dimension - 1> &>::type
    operator()(First first) const
    {
        return this->m_subgrids[(size_type)first];
    }

    ~Grid()
    {
        mem_free(); // #TODO почему не delete[]? (тогда в valgrind будет mismatch)
    }
};

/** Specialization for 1-dim array */
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

    /** Template for functor op.: finalizing the recursion for value returning */
    template <typename First>
    const T &operator()(First first) const
    {
        return this->data[(size_type)first];
    }

    /** Template for functor op.: finalizing the recursion for value returning */
    template <typename First>
    T &operator()(First first)
    {
        return this->data[(size_type)first];
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
    Grid<float, 3> const g3(10, 10, 10, 1.00f);
    assert(1.0f == g3[1][1][1]);

    Grid<float, 2> g2(2, 5, 2.0f);
    assert(2.0f == g2[1][1]);

    std::cout << g3(1, 1, 1) << std::endl;

    g2(1, 1) = 2.5;
    assert(g2(1, 1) == g2[1][1]);   // Operator skokbochka (_, _, ... _) working same as [][] ... []
    assert(g2(1, 1) != g2(1, 0));   // [g2(1,1)=__2.5f__] != [g2(1,0)=__2.0f__] 
    g2 = g3[1];
    assert(1.0f == g2[1][1]);       // g2(1,1) rewritten

    assert(&g3[1] != &g2);          // g2 was copied properly

    auto g1 = Grid<unsigned, 1>(1u);
    return 0;
}