#include "stdafx.h"
#include "Complex.h"
#include <cmath>

Complex::Complex()	// ����������� �� ���������
{
	re = 0;
	im = 0;
}											

Complex::Complex(double x, double y)        // ����� �����������
{
	re = x;
	im = y;
}

Complex::Complex(double x)                 // ��� ������������� ����� ������
{
	re = x;
	im = 0;
}

Complex::~Complex()                         // ����������
{

}

double Complex::Re()
{
	return re;
}

double Complex::Im()
{
	return im;
}     

void Complex::show()
{
	std::cout << re;
	if (im > 0)
		std::cout << "+";
	if (im != 0)
		std::cout << im << "i" << std::endl;
}

// �������� (�������� +-/* <���> ��������� � ������� ������������)
// �������� + ��������
Complex Complex::operator+(Complex B)
{
	return Complex(re + B.re, im + B.im);
}

// <���> + ��������
Complex& operator+(double x, Complex& B)
{
	Complex *W = new Complex;
	W->re = x + B.re;
	W->im = B.im;
	return *W;
}


// ��������� 
Complex Complex::operator-(Complex B)
{
	return Complex(re - B.re, im - B.im);
}

// <���> - ��������
Complex& operator-(double x, Complex& B)
{
	Complex *W = new Complex;
	W->re = x - B.re;
	W->im = -B.im;
	return *W;
}


// ���������
Complex Complex::operator*(Complex B)
{
	Complex X;
	X.re = (re * B.re - im * B.im);
	X.im = (re * B.im + B.re * im);
	return X;
}

//  <���> * ��������
Complex& operator*(double x, Complex& B)
{
	Complex *W = new Complex;
	W->re = x * B.re;
	W->im = x * B.im;
	return *W;
}


// �������
Complex Complex::operator/(Complex B)
{
	Complex X;
	X.re = (re * B.re + im * B.im) / (B.re * B.re + B.im * B.im);
	X.im = (im * B.re - re * B.im) / (B.re * B.re + B.im * B.im);
	return X;
}

// <���> / ��������
Complex& operator/(double x, Complex& B)
{
	Complex *W = new Complex;
	W->re = (x * B.re) / (B.re * B.re + B.im * B.im);
	W->im = (-x * B.im) / (B.re * B.re + B.im * B.im);
	return *W;
}


// ������� �����
Complex Complex::operator-() const
{
	return Complex(re*(-1), im*(-1));
}

// ������� ����
Complex Complex::operator+() const
{
	return *this;
}

// �������� ������������
Complex Complex::operator=(Complex B)
{
	re = B.re;
	im = B.im;
	return *this;
}

// ������� ��������� 
bool Complex::operator==(Complex B)
{
	if ((im == B.im) && (re == B.re))
		return true;
	else
		return false;

}

// ������
double Complex::module() const
{
	return sqrt(re * re + im * im);
}

// �������� �����������
bool Complex::operator!=(Complex B)
{
	if (this->module() == B.module())
		return false;
	else
		return true;
}

bool operator!=(double x, Complex B)
{
	if (x == B.module())
		return false;
	else
		return true;
}

//��������� ���������
bool Complex::operator>(Complex B)
{
	if (this->module() > B.module())
		return true;
	else
		return false;
}

bool operator>(double x, Complex B)
{
	if (x > B.module())
		return true;
	else
		return false;
}

bool Complex::operator<(Complex B)
{
	if (this->module() < B.module())
		return true;
	else
		return false;
}

bool operator<(double x, Complex B)
{
	if (x < B.module())
		return true;
	else
		return false;
}

bool Complex::operator>=(Complex B)
{
	if ((this->module() > B.module()) || (this->module() == B.module()))
		return true;
	else
		return false;
}

bool operator>=(double x, Complex B)
{
	if ((x > B.module()) || (x == B.module()))
		return true;
	else
		return false;
}

bool Complex::operator <=(Complex B)
{
	if ((this->module() < B.module()) || (this->module() == B.module()))
		return true;
	else
		return false;
}

bool operator <=(double x, Complex B)
{
	if ((x < B.module()) || (x == B.module()))
		return true;
	else
		return false;
}

// ���������� �������� ����������� � (arctg x) � ��������
double Complex::arg() const
{
	return atan(im / re);
}

// ���������� ������������
Complex& Complex::conjugate()
{
	Complex* W = new Complex;
	W->re = this->re;
	W->im = -this->im;
	return *W;
}


// ���������� ������� ���������� � �������
Complex& pow(Complex& z, const double x)
{
	Complex *W = new Complex;
	W->re = pow(z.module(), x)*cos(x*z.arg());
	W->im = pow(z.module(), x)*sin(x*z.arg());
	return *W;
}

// ���������� ������� log
Complex& log(Complex& z)
{
	Complex* W = new Complex;
	W->re = log(z.module());
	W->im = z.arg();
	return *W;
}

// ���������� ����������
Complex& exp(Complex& z)
{
	Complex *W = new Complex;
	W->re = exp(z.Re())*cos(z.Im());
	W->im = exp(z.Re())*sin(z.Im());
	return *W;
}

// ������������������ �������
Complex& cos(Complex& z)
{
	Complex *W = new Complex;
	Complex I(0, 1);
	Complex I1 = I * z;
	Complex I2 = -I * z;
	*W = (exp(I1) + exp(I2)) / 2;
	return *W;
}

Complex& sin(Complex& z)
{
	Complex* W = new Complex;
	Complex I(0, 1);
	Complex I1 = I * z;
	Complex I2 = -I * z;
	*W = (exp(I1) - exp(I2)) / 2;
	return *W;
}

Complex& tan(Complex& z)
{
	Complex* W = new Complex;
	*W = sin(z) / cos(z);
	return *W;
}

// ���������� ������
std::ostream & operator << (std::ostream &os, const Complex &B)
{
	os << B.re;
	if (B.im >= 0)
		os << "+";
	os << B.im << "i";
	return os;
}