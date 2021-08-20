#ifndef _LXH_
#define _LXH_
class complex
{
private:
    double re, im;
    friend complex &_doapl(complex *, const complex &);

public:
    complex(double a = 0, double b = 0) : re(a), im(b) {}
    complex &operator+=(const complex &);
    double real() const { return re; } //����û��Ҫ�ı������ݵĻ��ǵ��ں������ź����const;
    double imag() const { return im; }
};
inline complex &complex::operator+=(const complex &r)
{
    return _doapl(this, r);
}
inline complex &_doapl(complex *ths, const complex &r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}
inline complex operator+(const complex &x, const complex &y)
{
    return complex(real(x) + real(y), imag(x) + imag(y)); //�����Ǹ���ʱ����;
}
inline complex operator+(const complex &x, double y)
{
    return complex(real(x) + y, imag(x));
}
inline complex operator+(double x, const complex &y)
{
    return complex(x + real(y), imag(y));
}
#include <iostream>
ostream& operator<<(ostream &os, const complex &x)
{ //("<<")��������ı���ֵ
    return os << '(' << real(x) << ',' << imag(x) << ')';
}
#endif