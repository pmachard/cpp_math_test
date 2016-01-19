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

	std::cout << "\n\n";

	std::cout << "A1 =" << a1 << "\n";
	std::cout << "B1 =" << b1 << "\n";
	std::cout << "C1 =" << c1 << "\n";

}

