#include "stdafx.h"
#include <iostream>
#include <cassert>

#include "VectorXd.h"

using namespace pma::math;
using namespace std;

void main()
{

	double data[3] = { 0.0, 1.0, 2.0 };

	std::cout << "\nCheck default constructeur : ";
	VectorXd<double, 3> a1;
	assert(a1[X] == (double)0.0);
	assert(a1[Y] == (double)0.0);
	assert(a1[Z] == (double)0.0);
	std::cout << "OK";


	std::cout << "\nCheck constructeur with tab : ";
	VectorXd<double, 3> b1(data);
	assert(b1[X] == (double)0.0);
	assert(b1[Y] == (double)1.0);
	assert(b1[Z] == (double)2.0);
	std::cout << "OK";

	std::cout << "\nCheck constructeur with copie : ";
	VectorXd<double, 3> c1(b1);
	assert(c1[X] == (double)0.0);
	assert(c1[Y] == (double)1.0);
	assert(c1[Z] == (double)2.0);
	std::cout << "OK";

	std::cout << "\nCheck operator = : ";
	VectorXd<double, 3> d1;
	d1 = c1;
	assert(d1[X] == (double)0.0);
	assert(d1[Y] == (double)1.0);
	assert(d1[Z] == (double)2.0);
	std::cout << "OK";

	std::cout << "\nCheck operator [] out of limit : ";
	try
	{
		double f0 = d1[3];
		assert(false);
	}
	catch (...)
	{
		std::cout << "OK";
	}

	std::cout << "\n\n";

	std::cout << "\nCheck operator << : ";
	std::cout << "A1 =" << a1 << "\n";
	std::cout << "B1 =" << b1 << "\n";
	std::cout << "C1 =" << c1 << "\n";
	std::cout << "OK";

	std::cout << "\nCheck abs :";
	double de[3] = { 1.0, -1.0, -3.333 };
	VectorXd<double, 3> e1(de);
	VectorXd<double, 3> f1 = e1.abs();
	assert(f1[X] == abs(f1[X]));
	assert(f1[Y] == abs(f1[Y]));
	assert(f1[Z] == abs(f1[Z]));
	std::cout << "OK";

	std::cout << "\nCheck operator += ";
	VectorXd<double, 3> g1(de);
	g1 += b1;
	assert(g1[X] == e1[X] + b1[X]);
	assert(g1[Y] == e1[Y] + b1[Y]);
	assert(g1[Z] == e1[Z] + b1[Z]);
	std::cout << "OK";

	std::cout << "\nCheck operator + ";
	VectorXd<double, 3> h1 = d1 + b1;
	assert(h1[X] == d1[X] + b1[X]);
	assert(h1[Y] == d1[Y] + b1[Y]);
	assert(h1[Z] == d1[Z] + b1[Z]);
	std::cout << "OK";

	std::cout << "\nCheck operator -= ";
	VectorXd<double, 3> i1(de);
	i1 -= b1;
	assert(i1[X] == e1[X] - b1[X]);
	assert(i1[Y] == e1[Y] - b1[Y]);
	assert(i1[Z] == e1[Z] - b1[Z]);
	std::cout << "OK";

	std::cout << "\nCheck operator - ";
	VectorXd<double, 3> j1 = d1 - b1;
	assert(j1[X] == d1[X] - b1[X]);
	assert(j1[Y] == d1[Y] - b1[Y]);
	assert(j1[Z] == d1[Z] - b1[Z]);
	std::cout << "OK";

	std::cout << "\nCheck operator *= ";
	VectorXd<double, 3> k1(d1);
	k1 *= 3.5;
	assert(k1[X] == d1[X] * 3.5);
	assert(k1[Y] == d1[Y] * 3.5);
	assert(k1[Z] == d1[Z] * 3.5);
	std::cout << "OK";

	std::cout << "\nCheck operator * ";
	VectorXd<double, 3> l1 = d1 * 3.5;
	assert(l1[X] == d1[X] * 3.5);
	assert(l1[Y] == d1[Y] * 3.5);
	assert(l1[Z] == d1[Z] * 3.5);
	std::cout << "OK";

	std::cout << "\nCheck operator /= ";
	VectorXd<double, 3> m1(d1);
	m1 /= 3.5;
	assert(m1[X] == d1[X] / 3.5);
	assert(m1[Y] == d1[Y] / 3.5);
	assert(m1[Z] == d1[Z] / 3.5);
	std::cout << "OK";

	std::cout << "\nCheck operator / ";
	VectorXd<double, 3> n1 = d1 / 3.5;
	assert(n1[X] == d1[X] / 3.5);
	assert(n1[Y] == d1[Y] / 3.5);
	assert(n1[Z] == d1[Z] / 3.5);
	std::cout << "OK";

	std::cout << "\nCheck ... ";
	std::cout << "OK";

	std::cout << "\n\n";


}

