# Сетки значений.

В библиотеке для работы с физическим моделями существует шаблон класса `Grid`, который моделирует двумерную сетку из произвольных объектов, допускающих конструирование копированием(`copy-constructible`) и копирующее присваивание (`copy-assignable`):

```cpp
template<typename T>
class Grid final
{
public:
    using value_type = T;
    using size_type = unsigned;
private:
    T* const data;
    size_type const y_size, x_size;
public:
    Grid(T *data , size_type y_size , size_type x_size)
    : data(data)
    , y_size(y_size)
    , x_size(x_size)
    {
    }

    Grid(Grid<T> const&) = delete;
    Grid(Grid<T>&&) = delete;
    Grid<T>& operator=(Grid<T>&) = delete;
    Grid<T>& operator=(Grid<T>&&) = delete;

    T operator()(size_type y_idx , size_type x_idx) const
    {
        return data[y_idx * x_size + x_idx];
    }

    T& operator()(size_type y_idx, size_type x_idx)
    {
        return data [y_idx * x_size + x_idx];
    }

    Grid<T>& operator=(T const& t)
    {
        for (auto it = data, end = data + x_size * y_size; it != end; ++it) *it = t;
        return *this;
    }

    size_type get_y_size() const { return y_size; }
    size_type get_x_size() const { return x_size; }
} ;
```

В существующем виде класс не управляет ресурсом памяти самостоятельно. Память выделяется внешним кодом и освобождена должна быть внешним кодом. Это создаёт неудобства при использовании класса.

# RAII

Модифицируйте класс `Grid` таким образом, чтобы он мог самостоятельно управлять собственным ресурсом памяти. Корректно реализуйте необходимые методы согласно "правилу пяти". Дополните его следующими конструкторами:
- конструктор `Grid(T const &t)` с одним параметром для неявного преобразования типов (из `T` в `Grid<T>`) создаёт новую сетку размером `1 × 1` с единственным элементом - копией `t`;
- конструктор с двумя параметрами `Grid(size_type y_size, size_type x_size)` создаёт сетку размером `y_size x x_size`, заполненную элементами типа `T`, созданными конструктором по молчанию (`default initialized`);
- конструктор с тремя параметрами `Grid(size_type y_size, size_type x_size, T const &t)` создаёт сетку размером `x_size × y_size`, заполненную копиями объекта `t`;

# Оператор индексирования

Добавьте в класс сетки оператор индексирования таким образом, чтобы при обращении к сетке с помощью двойного применения оператора квадратных скобок мы могли получить элемент, хранящийся в сетке. Причём следующий код должен успешно выполняться:

```cpp
#include<cassert>

int main()
{
    Grid<float> g(3, 2, 0.0f);
    assert(3 == g.get_y_size());
    assert(2 == g.get_x_size());

    using gsize_t = Grid<int>::size_type;

    for(gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
    for(gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
        assert(0.0f == g[y_idx][x_idx]);

    for(gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
    for(gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
        g[y_idx][x_idx] = 1.0f;

    for(gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
    for(gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
        assert(1.0f == g(y_idx , x_idx));
    return 0;
}
```
# Многомерные сетки

С развитием системы понадобилось оперировать не только двумерными, но и трёхмерными сетками, и сетками более высоких размерностей. Реализуйте шаблон класс для работы с сетками произвольных размерностей. Шаблон класса должен зависеть от двух параметров: типа хранящихся элементов и размерности сетки. Хранящиеся элементы являются `copy-constructible` и `copy-assignable`. Следующий пример кода должен успешно срабатывать:

```cpp
Grid<float, 3> const g3(2, 3, 4, 1.0f);
assert(1.0f == g3(1, 1, 1));

Grid<float, 2> g2(2, 5, 2.0f);
assert(2.0f == g2(1, 1));

g2 = g3[1];
assert(1.0f == g2(1, 1));
```