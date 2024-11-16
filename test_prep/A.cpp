struct Foo
{
    void say() const { std::cout << "Foo says: " << msg << "\n"; }

protected:
    Foo(const std::string &msg) : msg(msg) {}

private:
    const std::string &msg;
};

void foo_says(const Foo &foo)
{
    foo.say();
}

class FooDer : public Foo
{
public:
    FooDer(const std::string &msg) : Foo{msg} {}
};

Foo get_foo(std::string const &msg) // Using ref is a way to memleak
{
    FooDer slave(msg);
    return (Foo)slave;
}
