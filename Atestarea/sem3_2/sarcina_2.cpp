#include <string>
#include <iostream>

template <typename T>
class Patrat
{
private:
    T a;
    T b;
    T c;

public:
    Patrat()
    {
        a = 0;
        b = 0;
        c = 0;
    }

    Patrat(T a, T b, T c)
        : a(a), b(b), c(c) {}

    friend std::ostream &operator<<(std::ostream &out, const Patrat<T> &p)
    {
        std::cout << p.a << "x^2+" << p.b << "x+" << p.c << std::endl;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Patrat<T> &p)
    {
        std::cout << "a: ";
        in >> p.a;
        std::cout << "b: ";
        in >> p.b;
        std::cout << "c: ";
        in >> p.c;
        return in;
    }

    T Get_a()
    {
        return a;
    }

    T Get_b()
    {
        return b;
    }

    T Get_c()
    {
        return c;
    }

    Patrat<T> operator-=(T rhs)
    {
        return Patrat<T>(a - rhs.a, b - rhs.b, c - rhs.c);
    }

    Patrat<T> operator++() // left increment
    {
        c++;
        return *this;
    }

    Patrat<T> operator++(int) // right increment
    {
        Patrat<T> result(a, b, c);
        c++;
        return result;
    }

    Patrat<T> operator=(Patrat<T> &rhs)
    {
        a = rhs.a;
        b = rhs.b;
        c = rhs.c;
        return *this;
    }

    template <typename U>
    friend Patrat<U> operator-(U num, Patrat<U> &rhs);
    template <typename U>
    friend Patrat<U> operator-(Patrat<U> &lhs, U num);
    template <typename U>
    friend bool operator==(Patrat<U> &rhs, Patrat<U> &lhs);
};

template <typename T>
Patrat<T> operator-(T num, Patrat<T> &rhs)
{
    return Patrat<T>(-rhs.a, -rhs.b, -rhs.c + num);
}

template <typename T>
Patrat<T> operator-(Patrat<T> &lhs, T num)
{
    return Patrat<T>(lhs.a, lhs.b, lhs.c - num);
}

template <typename T>
bool operator==(Patrat<T> &rhs, Patrat<T> &lhs)
{
    return lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c;
}

int main()
{
    // Patrat<int> p;
    // std::cout << p;
    return 0;
}