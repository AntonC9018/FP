#include <cmath>
#include <iostream>

template <typename T>
class Complex
{
private:
    T real;
    T imaginary;

public:
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

    template <typename U>
    friend Complex<U> operator-(U num, Complex<U> &rhs);
    template <typename U>
    friend std::ostream &operator<<(std::ostream &out, const Complex<U> &c);
    template <typename U>
    friend std::istream &operator>>(std::istream &in, Complex<U> &c);
    template <typename U>
    friend Complex<U> operator*=(Complex<U> &lhs, Complex<U> &rhs);
    template <typename U>
    friend Complex<U> operator/=(Complex<U> &lhs, Complex<U> &rhs);
    template <typename U>
    friend Complex<U> operator-(Complex<U> &lhs, U rhs);
    template <typename U>
    friend Complex<U> operator--(Complex<U> &lhs);
    template <typename U>
    friend Complex<U> operator--(Complex<U> &lhs, int);
    template <typename U>
    friend bool operator<=(Complex<U> &lhs, Complex<U> &rhs);
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
    if (rhs.imaginary == 0 && rhs.real == 0)
    {
        throw "Division by zero not allowed";
    }
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

template <typename T>
void printType();

template <>
void printType<int>()
{
    std::cout << "int" << std::endl;
}

template <>
void printType<float>()
{
    std::cout << "float" << std::endl;
}

int main()
{
    Complex<int> a(1, 2);
    Complex<int> b(0, 0);
    std::cout << a << ", " << b << std::endl;
    try
    {
        Complex<int> result = a /= b;
        std::cout << "a / b = " << (result) << std::endl;
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }
    std::cout << std::endl;
    printType<int>();
    printType<float>();
}