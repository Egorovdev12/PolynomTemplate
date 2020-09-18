#pragma once
#include "Complex.h"
#include <iostream>

using namespace std;

template <typename TCoef>
struct meow
{
	TCoef koef;
	int SDeg;
};

template <typename TCoef>
class Polynom
{
private:
	unsigned int Degree;
	TCoef *Coef;

public:
	Polynom();
	Polynom(unsigned int, TCoef*);
	Polynom(const Polynom<TCoef> &object);
	~Polynom();
	void show();
	template <typename T> TCoef value(T);
	Complex value(Complex x);
	Polynom<TCoef> operator=(const Polynom<TCoef> &);
	Polynom<TCoef> operator+(const Polynom<TCoef> &);
	Polynom<TCoef> operator*(const Polynom<TCoef> &);
	Polynom<TCoef> operator-(const Polynom<TCoef> &);
	Polynom<TCoef> operator/(const Polynom<TCoef> &);
	Polynom<TCoef> operator-() const;
	bool operator==(const Polynom<TCoef> &);

	friend void LACHX(const Polynom<TCoef> &Ob, TCoef arr[], int size);
};


// ================================================================================================



template<typename TCoef>
Polynom<TCoef>::Polynom()             // Конструктор по умолчанию                     
{
	Coef = NULL;
}

template<typename TCoef>
Polynom<TCoef>::~Polynom()                                   // Деструктор
{
	delete[] Coef;
}

template<typename TCoef>
Polynom<TCoef>::Polynom(unsigned int deg, TCoef *kf)          // явный конструктор
{
	Coef = new TCoef[deg + 1];
	Degree = deg;
	for (int i = 0; i < deg + 1; i++)
	{
		Coef[i] = kf[i];
	}
}

template<typename TCoef>
Polynom<TCoef>::Polynom(const Polynom<TCoef> &object)               // конструктор копирования 
{
	Degree = object.Degree;
	Coef = new TCoef[object.Degree + 1];
	for (int i = 0; i < object.Degree + 1; i++)
	{
		Coef[i] = object.Coef[i];
	}
}

template<typename TCoef>
void Polynom<TCoef>::show()
{
	for (int i = 0; i < Degree; i++)
	{
		if (Coef[i] != 0)
		{
			cout << Coef[i] << "x^" << Degree - i << " ";
		}
		if (Coef[i + 1] > 0)
		{
			cout << "+ ";
		}
	}
	cout << Coef[Degree];
	cout << endl;
}


template<typename TCoef>    // Показатель того, что фукция принадлежит шаблонному классу
	template <typename T>    // Показатель того, что это шаблонная функция, принадлежащая шаблонному классу
TCoef Polynom<TCoef>::value(T x)
{
	TCoef sum;
	sum = 0;
	for (int i = 0; i < Degree; i++)
	{
		if (Coef[i] != 0)
		{
			sum = sum + Coef[i] * pow(x, (Degree - i));
		}
	}
	sum = sum + Coef[Degree];
	return sum;
}

template<typename TCoef>
Complex Polynom<TCoef>::value(Complex x)
{
	Complex sum;
	sum = 0;
	for (int i = 0; i < Degree; i++)
	{
		if (Coef[i] != 0)
		{
			sum = sum + Coef[i] * pow(x, (Degree - i));
		}
	}
	sum = sum + Coef[Degree];
	return sum;
}


template<typename TCoef>
Polynom<TCoef> Polynom<TCoef>::operator=(const Polynom<TCoef> &Ob)
{
	if (this != &Ob)
	{
		delete[] Coef;
		Degree = Ob.Degree;
		Coef = new TCoef[Degree + 1];
		for (int i = 0; i < Degree + 1; i++)
		{
			Coef[i] = Ob.Coef[i];
		}
	}
	return *this;
}

template<typename TCoef>
Polynom<TCoef> Polynom<TCoef>::operator+(const Polynom<TCoef> &Ob)
{
	if (Degree > Ob.Degree)
	{
		Polynom<TCoef> harr = *this;
		int Dif = Degree - Ob.Degree;

		for (int e = 0; e < Dif; e++)
		{
			harr.Coef[e] = Coef[e];
		}
		int y = 0;
		for (int u = Dif; u < Degree + 1; u++)
		{
			harr.Coef[u] = Coef[u] + Ob.Coef[y];
			y++;
		}
		return harr;
	}
	else if (Degree < Ob.Degree)
	{
		Polynom<TCoef> harr = Ob;
		int Dif = Ob.Degree - Degree;

		for (int e = 0; e < Dif; e++)
		{
			harr.Coef[e] = Ob.Coef[e];
		}
		int y = 0;
		for (int u = Dif; u < Ob.Degree + 1; u++)
		{
			harr.Coef[u] = Coef[y] + Ob.Coef[u];
			y++;
		}
		return harr;
	}
	else if (Degree == Ob.Degree)
	{
		Polynom<TCoef> harr = *this;
		for (int i = 0; i < Degree + 1; i++)
		{
			harr.Coef[i] = Coef[i] + Ob.Coef[i];
		}
		return harr;
	}
}

template<typename TCoef>
Polynom<TCoef> Polynom<TCoef>::operator-(const Polynom<TCoef> &Ob)
{
	if (Degree > Ob.Degree)
	{
		Polynom<TCoef> harr = *this;
		int Dif = Degree - Ob.Degree;

		for (int e = 0; e < Dif; e++)
		{
			harr.Coef[e] = Coef[e];
		}
		int y = 0;
		for (int u = Dif; u < Degree + 1; u++)
		{
			harr.Coef[u] = Coef[u] - Ob.Coef[y];
			y++;
		}
		return harr;
	}
	else if (Degree < Ob.Degree)
	{
		Polynom<TCoef> harr = Ob;
		int Dif = Ob.Degree - Degree;

		for (int e = 0; e < Dif; e++)
		{
			harr.Coef[e] = Ob.Coef[e] * (-1);
		}
		int y = 0;
		for (int u = Dif; u < Ob.Degree + 1; u++)
		{
			harr.Coef[u] = Coef[y] - Ob.Coef[u];
			y++;
		}
		return harr;
	}
	else if (Degree == Ob.Degree)
	{
		Polynom<TCoef> harr = *this;
		for (int i = 0; i < Degree + 1; i++)
		{
			harr.Coef[i] = Coef[i] - Ob.Coef[i];
		}
		return harr;
	}
}

template<typename TCoef>
Polynom<TCoef> Polynom<TCoef>::operator/(const Polynom<TCoef> &)
{

	return Polynom<TCoef>();
}

template<typename TCoef>
Polynom<TCoef> Polynom<TCoef>::operator*(const Polynom<TCoef> &Ob)
{
	int MaxDeg = Degree + Ob.Degree;
	int opened = (Degree + 1) * (Ob.Degree + 1);
	meow<TCoef> *piter = new meow<TCoef>[opened];
	int c = 0;

	for (int a = 0; a < Degree + 1; a++)
	{
		for (int b = 0; b < Ob.Degree + 1; b++)
		{
			piter[c].koef = Coef[a] * Ob.Coef[b];
			piter[c].SDeg = (Degree - a) + (Ob.Degree - b);
			c++;
		}
	}

	Polynom<TCoef> harr;
	harr.Coef = new TCoef[MaxDeg + 1];
	harr.Degree = MaxDeg;
	int t; TCoef sum;
	for (int u = 0; u < MaxDeg + 1; u++)
	{
		t = 0;
		while (piter[t].SDeg != (MaxDeg - u))
		{
			t++;
		}
		sum = piter[t].koef;
		for (int g = t + 1; g < opened; g++)
		{
			if (piter[t].SDeg == piter[g].SDeg)
			{
				sum = sum + piter[g].koef;
			}
		}
		harr.Coef[u] = sum;
	}
	delete[] piter;
	return harr;
}

template<typename TCoef>
Polynom<TCoef> Polynom<TCoef>::operator-() const
{
	Polynom<TCoef> Current = *this;
	for (int i = 0; i < Degree + 1; i++)
	{
		Current.Coef[i] = (-1)*Coef[i];
	}
	return Current;
}

template<typename TCoef>
bool Polynom<TCoef>::operator==(const Polynom<TCoef> &Ob)
{
	TCoef count = 0;
	for (int i = 0; i < Degree + 1; i++)
	{
		if (Coef[i] == Ob.Coef[i])
		{
			count = count + 1;
		}
	}
	if (count == Degree + 1)
		return true;
	else
		return false;
}

template<typename TCoef>
void LACHX(const Polynom<TCoef> &Ob, TCoef arr[], int size)
{
	TCoef *ValueSum = new TCoef[size];
	for (int u = 0; u < size; u++)
	{
		ValueSum[u] = 0;
		for (int i = 0; i < Ob.Degree; i++)
		{
			if (Ob.Coef[i] != 0)
			{
				ValueSum[u] = ValueSum[u] + Ob.Coef[i] * pow(arr[u], (Ob.Degree - i));
			}
		}
		ValueSum[u] = ValueSum[u] + Ob.Coef[Ob.Degree];
	}

	cout << endl;
	for (int e = 0; e < size; e++)
	{
		cout << "with x = " << arr[e] << "      " << ValueSum[e] << endl;
	}
	delete[] ValueSum;
}
