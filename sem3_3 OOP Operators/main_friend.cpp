#include <cmath>
#include <iostream>

template <typename T>
struct Complex
{
    T real;
    T imaginary;

    Complex()
    {
        real = 0;
        imaginary = 0;
    }

    Complex(T real, T imaginary)
        : real(real), imaginary(imaginary) {}

    Complex(Complex<T> &&val)
    {
        real = val.real;
        imaginary = val.imaginary;
    }

    Complex(Complex<T> &val)
    {
        real = val.real;
        imaginary = val.imaginary;
    }

    Complex<T> getComplement()
    {
        return Complex<T>(real, -imaginary);
    }

    T getMagnitudeSq()
    {
        return real * real + imaginary * imaginary;
    }

    // equals cannot be global
    Complex<T> operator=(Complex<T> &rhs)
    {
        real = rhs.real;
        imaginary = rhs.imaginary;
        return *this;
    }
};

template <typename T>
Complex<T> operator-(T num, Complex<T> &rhs) // n - A
{
    return Complex<T>(num - rhs.real, -rhs.imaginary);
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Complex<T> &c)
{
    out << c.real;
    if (c.imaginary == 0)
    {
        return out;
    }
    if (c.imaginary == 1)
    {
        out << "+i";
    }
    else if (c.imaginary == -1)
    {
        out << "-i";
    }
    else if (c.imaginary > 0)
    {
        out << "+" << c.imaginary << "i";
    }
    else
    {
        out << c.imaginary << "i";
    }
    return out;
}

template <typename T>
std::istream &operator>>(std::istream &in, Complex<T> &c)
{
    std::cout << "Real part: ";
    in >> c.real;
    std::cout << "Imaginary part: ";
    in >> c.imaginary;
    return in;
}

template <typename T>
Complex<T> operator*=(Complex<T> &lhs, Complex<T> &rhs)
{
    T r = lhs.real;
    T i = lhs.imaginary;
    lhs.real = r * rhs.real - i * rhs.imaginary;
    lhs.imaginary = r * rhs.imaginary + rhs.real * i;
    return lhs;
}

template <typename T>
Complex<T> operator/=(Complex<T> &lhs, Complex<T> &rhs)
{
    Complex<T> rhs_complement = rhs.getComplement();
    T rhs_magn = rhs.getMagnitudeSq();
    lhs *= rhs_complement;
    lhs.real /= rhs_magn;
    lhs.imaginary /= rhs_magn;
    return lhs;
}

template <typename T>
Complex<T> operator-(Complex<T> &lhs, T rhs) // A - n
{
    return Complex<T>(lhs.real - rhs, lhs.imaginary);
}

template <typename T>
Complex<T> operator--(Complex<T> &lhs) // left decrement
{
    lhs.real--;
    return lhs;
}

template <typename T>
Complex<T> operator--(Complex<T> &lhs, int) // right decrement
{
    Complex<T> result(lhs.real, lhs.imaginary);
    lhs.real--;
    return result;
}

template <typename T>
bool operator<=(Complex<T> &lhs, Complex<T> &rhs)
{
    return lhs.getMagnitudeSq() <= rhs.getMagnitudeSq();
}

int main()
{
    Complex<float> a(1.4f, 1.2f);
    std::cout << a << std::endl;
    std::cout << "Enter a complex number" << std::endl;
    std::cin >> a;
    std::cout << a << std::endl;
    std::cout << "Real part of the imput number: " << a.real << std::endl;
    std::cout << "Imaginary part of the imput number: " << a.imaginary << std::endl;
    Complex<float> b;
    std::cout << "Default b: " << b << std::endl;
    std::cout << "Enter another complex number: " << std::endl;
    std::cin >> b;
    std::cout << "a / b = " << (a /= b) << std::endl;
    std::cout << "New value of a (expecting to be the same as the result in the previous message): " << a << std::endl;
    std::cout << "a--: " << (a--) << std::endl;
    std::cout << "a after decrementation: " << a << std::endl;
    std::cout << "--a: " << (--a) << std::endl;
    std::cout << "a after decrementation: " << a << std::endl;
    std::cout << "Current value of b: " << b << std::endl;
    std::cout << "Comparing magnitudes (a <= b): " << (a <= b ? "true" : "false") << std::endl;
    float num;
    std::cout << "Enter a float: " << std::endl;
    std::cin >> num;
    std::cout << "a - num = " << (a - num) << std::endl;
    std::cout << "num - a = " << (num - a) << std::endl;
    std::cout << "a = b: " << (a = b) << std::endl;
    std::cout << "a after assignment: " << a << std::endl;
}