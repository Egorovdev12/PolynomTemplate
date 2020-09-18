#include "stdafx.h"
#include "Complex.h"
#include <cmath>

Complex::Complex()	// Конструктор по умолчанию
{
	re = 0;
	im = 0;
}											

Complex::Complex(double x, double y)        // Явный конструктор
{
	re = x;
	im = y;
}

Complex::Complex(double x)                 // Для инициализации одним числом
{
	re = x;
	im = 0;
}

Complex::~Complex()                         // Деструктор
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

// Сложение (Комплекс +-/* <тип> считается с помощью конструктора)
// Комплекс + Комплекс
Complex Complex::operator+(Complex B)
{
	return Complex(re + B.re, im + B.im);
}

// <тип> + Косплекс
Complex& operator+(double x, Complex& B)
{
	Complex *W = new Complex;
	W->re = x + B.re;
	W->im = B.im;
	return *W;
}


// Вычитание 
Complex Complex::operator-(Complex B)
{
	return Complex(re - B.re, im - B.im);
}

// <тип> - Комплекс
Complex& operator-(double x, Complex& B)
{
	Complex *W = new Complex;
	W->re = x - B.re;
	W->im = -B.im;
	return *W;
}


// Умножение
Complex Complex::operator*(Complex B)
{
	Complex X;
	X.re = (re * B.re - im * B.im);
	X.im = (re * B.im + B.re * im);
	return X;
}

//  <тип> * Комплекс
Complex& operator*(double x, Complex& B)
{
	Complex *W = new Complex;
	W->re = x * B.re;
	W->im = x * B.im;
	return *W;
}


// Деление
Complex Complex::operator/(Complex B)
{
	Complex X;
	X.re = (re * B.re + im * B.im) / (B.re * B.re + B.im * B.im);
	X.im = (im * B.re - re * B.im) / (B.re * B.re + B.im * B.im);
	return X;
}

// <Тип> / Комплекс
Complex& operator/(double x, Complex& B)
{
	Complex *W = new Complex;
	W->re = (x * B.re) / (B.re * B.re + B.im * B.im);
	W->im = (-x * B.im) / (B.re * B.re + B.im * B.im);
	return *W;
}


// Унарный минус
Complex Complex::operator-() const
{
	return Complex(re*(-1), im*(-1));
}

// Унарный плюс
Complex Complex::operator+() const
{
	return *this;
}

// оператор присваивания
Complex Complex::operator=(Complex B)
{
	re = B.re;
	im = B.im;
	return *this;
}

// Условие равенства 
bool Complex::operator==(Complex B)
{
	if ((im == B.im) && (re == B.re))
		return true;
	else
		return false;

}

// Модуль
double Complex::module() const
{
	return sqrt(re * re + im * im);
}

// Оператор неравенства
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

//Операторы сравнения
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

// Возвращает значение арктангенса х (arctg x) в радианах
double Complex::arg() const
{
	return atan(im / re);
}

// Нахождение сопряженного
Complex& Complex::conjugate()
{
	Complex* W = new Complex;
	W->re = this->re;
	W->im = -this->im;
	return *W;
}


// Перегрузка функции возведения в степень
Complex& pow(Complex& z, const double x)
{
	Complex *W = new Complex;
	W->re = pow(z.module(), x)*cos(x*z.arg());
	W->im = pow(z.module(), x)*sin(x*z.arg());
	return *W;
}

// Перугрузка функции log
Complex& log(Complex& z)
{
	Complex* W = new Complex;
	W->re = log(z.module());
	W->im = z.arg();
	return *W;
}

// Перугрузка экспоненты
Complex& exp(Complex& z)
{
	Complex *W = new Complex;
	W->re = exp(z.Re())*cos(z.Im());
	W->im = exp(z.Re())*sin(z.Im());
	return *W;
}

// Тригонометрические функции
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

// Перегрузка вывода
std::ostream & operator << (std::ostream &os, const Complex &B)
{
	os << B.re;
	if (B.im >= 0)
		os << "+";
	os << B.im << "i";
	return os;
}