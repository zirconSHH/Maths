#include "complex.h"

void complex::print_complex() const
{
    cout << "(" << re << "," << im << ")" << endl;
}

double complex::get_re() const
{
    return re;
}

double complex::get_im() const
{
    return im;
}

void complex::change_re(double target)
{
    re = target;
}

void complex::change_im(double target)
{
    im = target;
}

void complex::change_complex(double a, double b)
{
    re = a;
    im = b;
}

complex& complex::operator+=(const complex& c)
{
    this->re += c.re;
    this->im += c.im;
    return *this;
}

complex& complex::operator-=(const complex& c)
{
    this->re -= c.re;
    this->im -= c.im;
    return *this;
}

complex& complex::operator*=(const complex& c)
{
    double tmp = this->re;
    this->re = this->re * c.re - this->im * c.im;
    this->im = this->im * c.re + tmp * c.im;
    return *this;
}

complex& complex::operator/=(const complex& c)
{
    double tmp1 = this->re;
    double tmp2 = c.get_re() * c.get_re() + c.get_im() * c.get_im();
    this->re = (this->re * c.get_re() + this->im * c.get_im()) / tmp2;
    this->im = (this->im * c.get_re() - tmp1 * c.get_im()) / tmp2;
    return *this;
}

complex complex::conjunction()
{
    return complex(this->re, -this->im);
}


double get_re(const complex& c)
{
    return c.get_re();
}

double get_im(const complex& c)
{
    return c.get_im();
}

complex conjunction(const complex& c)
{
    return complex(c.get_re(),-c.get_im());
}

complex operator+(const complex& c)
{
    return c;
}

complex operator+(const complex& c1, const complex& c2)
{
    return complex(c1.get_re() + c2.get_re(), c1.get_im() + c2.get_im());
}

complex operator+(const complex& c, const double& d)
{
    return complex(c.get_re() + d, c.get_im());
}

complex operator+(const double& d, const complex& c)
{
    return complex(c.get_re() + d, c.get_im());
}

complex operator-(const complex& c)
{
    return complex(-c.get_re(), -c.get_im());
}

complex operator-(const complex& c1, const complex& c2)
{
    return complex(c1.get_re() - c2.get_re(), c1.get_im() - c2.get_im());
}

complex operator-(const complex& c, const double& d)
{
    return complex(c.get_re() - d, c.get_im());
}

complex operator-(const double& d, const complex& c)
{
    return complex(c.get_re() - d, c.get_im());
}

bool operator==(const complex& c1, const complex& c2)
{
    return c1.get_re()==c2.get_re()&&c1.get_im()==c2.get_im();
}

bool operator==(const double& d, const complex& c)
{
    return c.get_im() == 0 && c.get_re() == d;
}

bool operator==(const complex& c, const double& d)
{
    return c.get_im() == 0 && c.get_re() == d;
}

complex operator*(const complex& c1, const complex& c2)
{
    double re = c1.get_re() * c2.get_re() - c1.get_im() * c2.get_im();
    double im = c1.get_re() * c2.get_im() + c1.get_im() * c2.get_re();
    return complex(re, im);
}

complex operator*(const complex& c, const double& d)
{
    return complex(c.get_re()*d,c.get_im()*d);
}

complex operator*(const double d, const complex& c)
{
    return complex(c.get_re() * d, c.get_im() * d);
}

complex operator/(const complex& c1, const complex& c2)
{
    double tmp = c2.get_re() * c2.get_re() + c2.get_im() * c2.get_im();
    double re = (c1.get_re() * c2.get_re() + c1.get_im() * c2.get_im()) / tmp;
    double im = (c1.get_im() * c2.get_re() - c1.get_re() * c2.get_im()) / tmp;
    return complex(re, im);
}

complex operator/(const complex& c, const double& d)
{
    return complex(c.get_re() / d, c.get_im() / d);
}

complex operator/(const double& d, const complex& c)
{
    double tmp = c.get_im() * c.get_im();
    double re = c.get_re() * d / tmp;
    double im = -d * c.get_im() / tmp;
    return complex(re, im);
}

ostream& operator<<(ostream& os, const complex& c)
{
    return os << '(' << c.get_re() << ',' << c.get_im() << ')' << ' ';
}

