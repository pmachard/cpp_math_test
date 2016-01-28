#include "stdafx.h"
#include <list>
#include <vector>
#include <iostream>
#include <cassert>

#include "VectorXd.h"
#include "matrix.h"

using namespace pma::math;
using namespace std;

void main()
{
	const double ESPILON = 10e-10;

	std::cout << "\n*********************************************************************";
	std::cout << "\nCheck Matrix2x3 default constructor  : ";
	Matrix2x3<double> m01a;
	assert(m01a.get(0, 0) == 0.0);		assert(m01a.get(0, 1) == 0.0);		assert(m01a.get(0, 2) == 0.0);
	assert(m01a.get(1, 0) == 0.0);		assert(m01a.get(1, 1) == 0.0);		assert(m01a.get(1, 2) == 0.0);
	std::cout << "OK";

	std::cout << "\n---------------------------------------------------------------------";
	std::cout << "\nCheck Matrix2x3 constructor  with init all value: ";
	Matrix2x3<double> m01b(1.0);
	assert(m01b.get(0, 0) == 1.0);		assert(m01b.get(0, 1) == 1.0);		assert(m01b.get(0, 2) == 1.0);
	assert(m01b.get(1, 0) == 1.0);		assert(m01b.get(1, 1) == 1.0);		assert(m01b.get(1, 2) == 1.0);
	std::cout << "OK";

	std::cout << "\n---------------------------------------------------------------------";
	std::cout << "\nCheck Matrix2x3 constructor  with tab : ";
	double dataM01[2][3] = { { 0.0, 1.0, 2.0 }, { 3.0, 4.0, 5.0 } };
	Matrix2x3<double> m01c((double *)dataM01);
	assert(m01c.get(0, 0) == 0.0);		assert(m01c.get(0, 1) == 1.0);		assert(m01c.get(0, 2) == 2.0);
	assert(m01c.get(1, 0) == 3.0);		assert(m01c.get(1, 1) == 4.0);		assert(m01c.get(1, 2) == 5.0);
	std::cout << "OK";

	std::cout << "\n---------------------------------------------------------------------";
	std::cout << "\nCheck Matrix2x3 set value with tab : ";
	double dataM02[2][3] = { { 0.0, 1.0, 2.0 }, { 3.0, 4.0, 5.0 } };
	Matrix2x3<double> m02((double *)dataM02);
	assert(m02.get(0, 0) == 0.0);		assert(m02.get(0, 1) == 1.0);		assert(m02.get(0, 2) == 2.0);
	assert(m02.get(1, 0) == 3.0);		assert(m02.get(1, 1) == 4.0);		assert(m02.get(1, 2) == 5.0);

	m02.set(0, 0, 10.0);
	m02.set(0, 1, 10.1);
	m02.set(0, 2, 10.2);
	m02.set(1, 0, 10.3);
	m02.set(1, 1, 10.4);
	m02.set(1, 2, 10.5);

	assert(m02.get(0, 0) == 10.0);		assert(m02.get(0, 1) == 10.1);		assert(m02.get(0, 2) == 10.2);
	assert(m02.get(1, 0) == 10.3);		assert(m02.get(1, 1) == 10.4);		assert(m02.get(1, 2) == 10.5);
	std::cout << "OK";

	std::cout << "\n*********************************************************************";
	std::cout << "\nCheck Matrix3x3 default constructor  : ";
	Matrix3x3<double> m11a;
	assert(m11a.get(0, 0) == 0.0);		assert(m11a.get(0, 1) == 0.0);		assert(m11a.get(0, 2) == 0.0);
	assert(m11a.get(1, 0) == 0.0);		assert(m11a.get(1, 1) == 0.0);		assert(m11a.get(1, 2) == 0.0);
	assert(m11a.get(2, 0) == 0.0);		assert(m11a.get(2, 1) == 0.0);		assert(m11a.get(2, 2) == 0.0);
	std::cout << "OK";

	std::cout << "\n---------------------------------------------------------------------";
	std::cout << "\nCheck Matrix3x3 constructor  with init all value: ";
	Matrix3x3<double> m11b(1.0);
	assert(m11b.get(0, 0) == 1.0);		assert(m11b.get(0, 1) == 1.0);		assert(m11b.get(0, 2) == 1.0);
	assert(m11b.get(1, 0) == 1.0);		assert(m11b.get(1, 1) == 1.0);		assert(m11b.get(1, 2) == 1.0);
	assert(m11b.get(2, 0) == 1.0);		assert(m11b.get(2, 1) == 1.0);		assert(m11b.get(2, 2) == 1.0);
	std::cout << "OK";

	std::cout << "\n---------------------------------------------------------------------";
	std::cout << "\nCheck Matrix3x3 constructor  with tab : ";
	double dataM11[3][3] = { { 0.0, 1.0, 2.0 }, { 3.0, 4.0, 5.0 }, { 6.0, 7.0, 8.0 } };
	Matrix3x3<double> m11c((double *)dataM11);
	assert(m11c.get(0, 0) == 0.0);		assert(m11c.get(0, 1) == 1.0);		assert(m11c.get(0, 2) == 2.0);
	assert(m11c.get(1, 0) == 3.0);		assert(m11c.get(1, 1) == 4.0);		assert(m11c.get(1, 2) == 5.0);
	assert(m11c.get(2, 0) == 6.0);		assert(m11c.get(2, 1) == 7.0);		assert(m11c.get(2, 2) == 8.0);
	std::cout << "OK";

	std::cout << "\n---------------------------------------------------------------------";
	std::cout << "\nCheck Matrix3x3 set value with tab : ";
	double dataM12[3][3] = { { 0.0, 1.0, 2.0 }, { 3.0, 4.0, 5.0 }, { 6.0, 7.0, 8.0 } };
	Matrix3x3<double> m12((double *)dataM12);
	assert(m12.get(0, 0) == 0.0);		assert(m12.get(0, 1) == 1.0);		assert(m12.get(0, 2) == 2.0);
	assert(m12.get(1, 0) == 3.0);		assert(m12.get(1, 1) == 4.0);		assert(m12.get(1, 2) == 5.0);
	assert(m12.get(2, 0) == 6.0);		assert(m12.get(2, 1) == 7.0);		assert(m12.get(2, 2) == 8.0);

	m12.set(0, 0, 10.0);
	m12.set(0, 1, 10.1);
	m12.set(0, 2, 10.2);
	m12.set(1, 0, 10.3);
	m12.set(1, 1, 10.4);
	m12.set(1, 2, 10.5);
	m12.set(2, 0, 10.6);
	m12.set(2, 1, 10.7);
	m12.set(2, 2, 10.8);

	assert(m12.get(0, 0) == 10.0);		assert(m12.get(0, 1) == 10.1);		assert(m12.get(0, 2) == 10.2);
	assert(m12.get(1, 0) == 10.3);		assert(m12.get(1, 1) == 10.4);		assert(m12.get(1, 2) == 10.5);
	assert(m12.get(2, 0) == 10.6);		assert(m12.get(2, 1) == 10.7);		assert(m12.get(2, 2) == 10.8);
	std::cout << "OK";

	std::cout << "\n*********************************************************************";
	std::cout << "\n\n";
}

