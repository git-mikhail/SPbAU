/*Даны целые числа 1≤n≤10^18 и 2≤m≤10^5, необходимо найти остаток от деления n-го числа Фибоначчи на m.
(c) Mikhail Mitrofanov, 2015, AU SE*/

#include <iostream>

typedef unsigned long long ulonglong;
struct Matrix
{
    ulonglong a, b, c, d;
    void set(ulonglong a_, ulonglong b_, ulonglong c_, ulonglong d_)
    {
        a = a_;
        b = b_;
        c = c_;
        d = d_;
    }
    Matrix& operator= (const Matrix &mat)
    {
        a = mat.a;
        b = mat.b;
        c = mat.c;
        d = mat.d;
        return *this;
    }
    void print() const
    {
        std::cout << a << " " << b << std::endl << c << " " << d << std::endl;
    }
};

struct Vector
{
    ulonglong a, b;
    void set(ulonglong a_, ulonglong b_)
    {
        a = a_;
        b = b_;
    }
    Vector& operator= (const Vector &v)
    {
        a = v.a;
        b = v.b;
        return *this;
    }
    void print() const
    {
        std::cout << a << std::endl << b << std::endl;
    }
};

Matrix multMatrix(const Matrix &x, const Matrix &y, const int m)
{
    Matrix a;
    a.set(x.a * y.a + x.b * y.c, x.a * y.b + x.b * y.d,
          x.c * y.a + x.d * y.c, x.c * y.b + x.d * y.d);
    a.a %= m;
    a.b %= m;
    a.c %= m;
    a.d %= m;
    return a;
}

Vector multVector(const Matrix &x, const Vector &v)
{
    Vector a;
    a.set(x.a * v.a + x.b * v.b, x.c * v.a + x.d * v.b);
    return a;
}

ulonglong fibo(unsigned long long n, const int m)
{
    Vector v;
    v.set(0, 1);
    Matrix mat;
    mat.set(0, 1, 1, 1);
    Matrix result;
    result = mat;
    
    for(--n; n > 0; n >>= 1)
    {
        if (n % 2 == 1)
            result = multMatrix(result, mat, m);
        mat = multMatrix(mat, mat, m);
    }
    v = multVector(result, v);
    return v.a % m;
}

int main()
{
    unsigned long long n;
    int m;
    std::cin >> n >> m;
    std::cout << fibo(n, m) << std::endl;
    return 0;
}    