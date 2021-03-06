// PolynomTemplate_lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Complex.h"
#include "PolynomTemplate_Header.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "");

	Complex wowarr1[3];
	Complex wow1(10, 5);
	Complex wow2(20, 10);
	Complex wow3(15, 7);
	Complex wow4(4, 3);
	Complex wow5(5, 0);
	double arr1[4] = { 5,3, -2, 17 };
	Polynom<double> TEST1(3, arr1);
	cout << endl << "Значение полинома с коэф. double  "; TEST1.show(); cout << endl;
	cout << "Значение при х = 5            " << TEST1.value<double>(5) << endl;
	cout << "Значение при х = 4 + 3i    " << TEST1.value(wow4) << endl;
	wowarr1[0] = wow1; wowarr1[1] = wow2; wowarr1[2] = wow3;
	Polynom<Complex> TEST2(2, wowarr1);
	cout << endl << "Значение полинома с коэф. Complex  "; TEST2.show(); cout << endl;
	cout << "Значение при х = 10 + 5i   "  << TEST2.value(wow1) << endl;
	cout << "Значение при х = 5            " << TEST2.value(5) << endl;

	cout << endl << "===============================" << endl;
	if (5 != wow4)
		cout << "Modul 1 ne raven modulu 2" << endl;
	else
		cout << "Moduli ravni" << endl;

	cout << endl << "===============================" << endl;

	Complex wow22 = wow2;
	if (wow22 >= wow2)
		cout << ">=" << endl;
	else
		cout << "Меньше" << endl;

	Polynom<Complex> TEST3 = TEST2 + TEST2;
	TEST3.show();


    return 0;
}

