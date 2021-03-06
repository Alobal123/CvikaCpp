#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Complex {
	float re, im;
public:
	Complex(float re, float im) : re{ re }, im{ im } {}

	void print()
	{
		cout << re << "+" << im << "i" << endl;
	}

	Complex conjugate() {
		return Complex(this->re, -1 * this->im);
	}

	Complex& operator+ (const Complex& rhs)
	{
		Complex n = Complex(this->re + rhs.re, this->im + rhs.re);
		return n;
	}


};

class A
{
public:
	A() { cout << "Calling default constructor" << endl; };
	A(const A &b) { cout << "Calling copy constructor" << endl; };
	A &operator=(A &a) { cout << "Calling = operator" << endl;  return *this; };
	~A() { cout << "Calling destructor" << endl; }

};

class C
{

public:
	static bool should_print;

	C() {
		cout << " 2 3 4";
	}

	C(const C &c) { cout << " 6 7 8 9"; }

	~C()
	{
		if (should_print)
		{
			cout << " 11 12 13 14 15 16 17 18 19 20";
		}
		should_print = true;
	}
};

bool C::should_print = false;

void fn_copy(C c)
{

}



int main(int argc, char** argv)
{
	C::should_print = false;
	cout << "1";
	C c;
	cout << " 5";
	fn_copy(c);
	cout << " 10";

	/*
	Complex n(1, 2);
	n.print();

	cout << "Starting" << endl;

	A a;
	A b(a);
	for (int i = 0; i < 5; i++)
	{
	A c(b);
	c = a;
	}

	cout << "Ending" << endl;*/
	/*Complex a = Complex(1, 1);
	Complex b = Complex(1, 1);
	Complex v = a + b;
	v.print();*/

	return 0;
}

