class ClsD
{
public:
    char &return_c()
    {
        return (this->m_c);
    }

    double &return_d()
    {
        return (this->m_d);
    }

    std::int32_t &return_i()
    {
        return this->m_i;
    }

private:
    char m_c;
    double m_d;
    std::int32_t m_i;
};

// Эта функция должна предоставить доступ к полю m_c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т.е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls)
{
    ClsD *d = reinterpret_cast<ClsD *>(&cls);
    return d->return_c();
}

// Эта функция должна предоставить доступ к полю m_d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т.е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls)
{
    ClsD *d = reinterpret_cast<ClsD *>(&cls);
    return d->return_d();
}

// Эта функция должна предоставить доступ к полю m_i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т.е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls)
{
    ClsD *d = reinterpret_cast<ClsD *>(&cls);
    return d->return_i();
}
