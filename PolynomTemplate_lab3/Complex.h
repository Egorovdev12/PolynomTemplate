#pragma once
#include <iostream>

class Complex
{
private:
	double re;
	double im;
public:
	Complex();
	Complex(double x, double y);
	Complex(double x);
	~Complex();
	Complex operator+(Complex B);
	friend Complex& operator+(double x, Complex& B);
	Complex operator-(Complex B);
	friend Complex& operator-(double x, Complex& B);
	Complex operator*(Complex B);
	friend Complex& operator*(double x, Complex& B);
	Complex operator/(Complex B);
	friend Complex& operator/(double x, Complex& B);
	Complex operator-() const;
	Complex operator+() const;
	Complex operator=(Complex B);
	bool operator==(Complex B);
	bool operator!=(Complex B);
	friend bool operator!=(double x, Complex B);
	bool operator>(Complex B);
	friend bool operator>(double x, Complex B);
	bool operator<(Complex B);
	friend bool operator<(double x, Complex B);
	bool operator>=(Complex B);
	friend bool operator>=(double x, Complex B);
	bool operator <=(Complex B);
	friend bool operator <=(double x, Complex B);

	double Re();
	double Im();
	void show();
	double module() const;
	double arg() const;
	Complex& conjugate();

	friend Complex& pow(Complex& z, const double x);
	friend Complex& log(Complex& z);
	friend Complex& exp(Complex& z);
	friend Complex& cos(Complex& z);
	friend Complex& sin(Complex& z);
	friend Complex& tan(Complex& z);
	friend std::ostream & operator << (std::ostream &os, const Complex &B);
};
