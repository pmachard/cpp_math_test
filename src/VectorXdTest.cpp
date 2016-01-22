#include "stdafx.h"
#include <iostream>
#include <cassert>

#include "VectorXd.h"

using namespace pma::math;
using namespace std;

void main()
{
	const double ESPILON = 10e-10;

	double data[3] = { 0.0, 1.0, 2.0 };

	std::cout << "\nCheck default constructeur : ";
	VectorXd<double, 3> a1;
	assert(a1[_X_] == (double)0.0);
	assert(a1[_Y_] == (double)0.0);
	assert(a1[_Z_] == (double)0.0);
	std::cout << "OK";


	std::cout << "\nCheck constructeur with tab : ";
	VectorXd<double, 3> b1(data);
	assert(b1[_X_] == (double)0.0);
	assert(b1[_Y_] == (double)1.0);
	assert(b1[_Z_] == (double)2.0);
	std::cout << "OK";

	std::cout << "\nCheck constructeur with copie : ";
	VectorXd<double, 3> c1(b1);
	assert(c1[_X_] == (double)0.0);
	assert(c1[_Y_] == (double)1.0);
	assert(c1[_Z_] == (double)2.0);
	std::cout << "OK";

	std::cout << "\nCheck operator = : ";
	VectorXd<double, 3> d1;
	d1 = c1;
	assert(d1[_X_] == (double)0.0);
	assert(d1[_Y_] == (double)1.0);
	assert(d1[_Z_] == (double)2.0);
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
	assert(f1[_X_] == abs(e1[_X_]));
	assert(f1[_Y_] == abs(e1[_Y_]));
	assert(f1[_Z_] == abs(e1[_Z_]));
	std::cout << "OK";

	std::cout << "\nCheck operator == :";
	assert(b1 == b1);
	assert(b1 == c1);
	std::cout << "OK";

	std::cout << "\nCheck operator != :";
	assert(f1 != e1);
	std::cout << "OK";

	std::cout << "\nCheck operator += ";
	VectorXd<double, 3> g1(de);
	g1 += b1;
	assert(g1[_X_] == e1[_X_] + b1[_X_]);
	assert(g1[_Y_] == e1[_Y_] + b1[_Y_]);
	assert(g1[_Z_] == e1[_Z_] + b1[_Z_]);
	std::cout << "OK";

	std::cout << "\nCheck operator + ";
	VectorXd<double, 3> h1 = d1 + b1;
	assert(h1[_X_] == d1[_X_] + b1[_X_]);
	assert(h1[_Y_] == d1[_Y_] + b1[_Y_]);
	assert(h1[_Z_] == d1[_Z_] + b1[_Z_]);
	std::cout << "OK";

	std::cout << "\nCheck operator -= ";
	VectorXd<double, 3> i1(de);
	i1 -= b1;
	assert(i1[_X_] == e1[_X_] - b1[_X_]);
	assert(i1[_Y_] == e1[_Y_] - b1[_Y_]);
	assert(i1[_Z_] == e1[_Z_] - b1[_Z_]);
	std::cout << "OK";

	std::cout << "\nCheck operator - ";
	VectorXd<double, 3> j1 = d1 - b1;
	assert(j1[_X_] == d1[_X_] - b1[_X_]);
	assert(j1[_Y_] == d1[_Y_] - b1[_Y_]);
	assert(j1[_Z_] == d1[_Z_] - b1[_Z_]);
	std::cout << "OK";

	std::cout << "\nCheck operator *= ";
	VectorXd<double, 3> k1(d1);
	k1 *= 3.5;
	assert(k1[_X_] == d1[_X_] * 3.5);
	assert(k1[_Y_] == d1[_Y_] * 3.5);
	assert(k1[_Z_] == d1[_Z_] * 3.5);
	std::cout << "OK";

	std::cout << "\nCheck operator * ";
	VectorXd<double, 3> l1 = d1 * 3.5;
	assert(l1[_X_] == d1[_X_] * 3.5);
	assert(l1[_Y_] == d1[_Y_] * 3.5);
	assert(l1[_Z_] == d1[_Z_] * 3.5);
	std::cout << "OK";

	std::cout << "\nCheck operator /= ";
	VectorXd<double, 3> m1(d1);
	m1 /= 3.5;
	assert(m1[_X_] == d1[_X_] / 3.5);
	assert(m1[_Y_] == d1[_Y_] / 3.5);
	assert(m1[_Z_] == d1[_Z_] / 3.5);
	std::cout << "OK";

	std::cout << "\nCheck operator / ";
	VectorXd<double, 3> n1 = d1 / 3.5;
	assert(n1[_X_] == d1[_X_] / 3.5);
	assert(n1[_Y_] == d1[_Y_] / 3.5);
	assert(n1[_Z_] == d1[_Z_] / 3.5);
	std::cout << "OK";

	std::cout << "\nCheck ... ";
	std::cout << "OK";

	std::cout << "\n---------------------------------------------------------------------";
	std::cout << "\nVector1d";
	std::cout << "\nCheck Vector1d constructeur with value : ";
	Vector1d<double> v00(0.1);
	assert(v00[_X_] == 0.1);
	assert(v00.getX() == 0.1);
	std::cout << "OK";

	std::cout << "\n---------------------------------------------------------------------";
	std::cout << "\nVector2d";
	std::cout << "\nCheck Vector2d constructeur with value : ";
	Vector2d<double> v01(0.1, 0.2);
	assert(v01[_X_] == 0.1);
	assert(v01[_Y_] == 0.2);
	assert(v01.getX() == 0.1);
	assert(v01.getY() == 0.2);
	std::cout << "OK";

	std::cout << "\nCheck Vector2d operator ^ : ";
	Vector2d<double> v01a(0.1, 0.2);
	Vector2d<double> v01b(0.3, 0.4);
	assert((v01a ^ v01b) == ((0.1*0.4) - (0.2*0.3)));
	std::cout << "OK";

	std::cout << "\nCheck Vector2d LengthSquared : ";
	assert(v01.SquaredLength() == (0.1*0.1 + 0.2*0.2));
	std::cout << "OK";

	std::cout << "\nCheck Vector2d Length : ";
	assert(v01.Length() == sqrt(0.1*0.1 + 0.2*0.2));
	std::cout << "OK";

	std::cout << "\nCheck Vector2d Normalize : ";
	Vector2d<double> v01c(v01);
	v01c.Normalize();
	assert(abs(v01c.Length()- 1.0) < ESPILON);
	std::cout << "OK";

	std::cout << "\nCheck Vector2d static Normalize : ";
	Vector2d<double> v01d = Vector2d<double>::Normalize(v01);
	assert(abs(v01d.Length() - 1.0) < ESPILON);
	std::cout << "OK";

	std::cout << "\nCheck Vector2d static Distance : ";
	assert(Vector2d<double>::Distance(Vector2d<double>(.0, .0), Vector2d<double>(.0, .0)) == 0);
	assert(Vector2d<double>::Distance(Vector2d<double>(1.0, .0), Vector2d<double>(.0, .0)) == 1.0);
	assert(Vector2d<double>::Distance(Vector2d<double>(0.0, 1.0), Vector2d<double>(.0, .0)) == 1.0);
	assert(Vector2d<double>::Distance(Vector2d<double>(5, 10), Vector2d<double>(9, 7)) == 5.0);
	std::cout << "OK";

	std::cout << "\n---------------------------------------------------------------------";
	std::cout << "\nVector3d";
	std::cout << "\nCheck Vector3d constructeur with value ";
	Vector3d<double> v02(0.1, 0.2,0.3);
	assert(v02[_X_] == 0.1);
	assert(v02[_Y_] == 0.2);
	assert(v02[_Z_] == 0.3);
	assert(v02.getX() == 0.1);
	assert(v02.getY() == 0.2);
	assert(v02.getZ() == 0.3);
	std::cout << "OK";

	std::cout << "\nCheck Vector3d operator ^ : ";
	Vector3d<double> v02a(0.1, 0.2,0.3);
	Vector3d<double> v02b(0.4, 0.5,0.6);
	assert((v02a ^ v02b) == ((0.1*0.4) + (0.2*0.5) + (0.3*0.6)));
	std::cout << "OK";

	std::cout << "\nCheck Vector3d LengthSquared : ";
	assert(v02.SquaredLength() == (0.1*0.1 + 0.2*0.2 + 0.3 * 0.3));
	std::cout << "OK";

	std::cout << "\nCheck Vector3d Length : ";
	assert(v02.Length() == sqrt(0.1*0.1 + 0.2*0.2 + 0.3*0.3));
	std::cout << "OK";

	std::cout << "\nCheck Vector3d Normalize : ";
	Vector3d<double> v02c(v02);
	v02c.Normalize();
	assert(abs(v02c.Length() - 1.0) < ESPILON);
	std::cout << "OK";

	std::cout << "\nCheck Vector3d static Normalize : ";
	Vector3d<double> v02d = Vector3d<double>::Normalize(v02);
	assert(abs(v02d.Length() - 1.0) < ESPILON);
	std::cout << "OK";

	std::cout << "\nCheck Vector3d static Distance : ";
	assert(Vector3d<double>::Distance(Vector3d<double>(.0, .0, .0), Vector3d<double>(.0, .0, .0)) == 0);
	assert(Vector3d<double>::Distance(Vector3d<double>(1.0, .0, .0), Vector3d<double>(.0, .0, .0)) == 1.0);
	assert(Vector3d<double>::Distance(Vector3d<double>(0.0, 1.0, .0), Vector3d<double>(.0, .0, .0)) == 1.0);
	assert(Vector3d<double>::Distance(Vector3d<double>(5, 10, .0), Vector3d<double>(9, 7, .0)) == 5.0);
	assert(Vector3d<double>::Distance(Vector3d<double>(5, .0, 10), Vector3d<double>(9, .0, 7)) == 5.0);
	std::cout << "OK";


	std::cout << "\n---------------------------------------------------------------------";
	std::cout << "\nVector4d";
	std::cout << "\nCheck Vector4d constructeur with value ";
	Vector4d<double> v03(0.1, 0.2, 0.3, 0.4);
	assert(v03[_X_] == 0.1);
	assert(v03[_Y_] == 0.2);
	assert(v03[_Z_] == 0.3);
	assert(v03[_T_] == 0.4);
	assert(v03.getX() == 0.1);
	assert(v03.getY() == 0.2);
	assert(v03.getZ() == 0.3);
	assert(v03.getT() == 0.4);
	std::cout << "OK";

	std::cout << "\n\n";

}

