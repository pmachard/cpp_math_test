#include "stdafx.h"
#include <list>
#include <vector>
#include <iostream>
#include <cassert>

#include "VectorXd.h"

using namespace pma::math;
using namespace std;

void main()
{
	const double ESPILON = 10e-10;

	double data[3] = { 0.0, 1.0, 2.0 };

	std::cout << "\nCheck VectorXd default constructeur : ";
	VectorXd<double, 3> a1;
	assert(a1[_X_] == (double)0.0);
	assert(a1[_Y_] == (double)0.0);
	assert(a1[_Z_] == (double)0.0);
	std::cout << "OK";


	std::cout << "\nCheck VectorXd constructeur with tab : ";
	VectorXd<double, 3> b1(data);
	assert(b1[_X_] == (double)0.0);
	assert(b1[_Y_] == (double)1.0);
	assert(b1[_Z_] == (double)2.0);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd constructeur with copie : ";
	VectorXd<double, 3> c1(b1);
	assert(c1[_X_] == (double)0.0);
	assert(c1[_Y_] == (double)1.0);
	assert(c1[_Z_] == (double)2.0);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd operator = : ";
	VectorXd<double, 3> d1;
	d1 = c1;
	assert(d1[_X_] == (double)0.0);
	assert(d1[_Y_] == (double)1.0);
	assert(d1[_Z_] == (double)2.0);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd operator [] out of limit : ";
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

	std::cout << "\nCheck VectorXd operator << : ";
	std::cout << "A1 =" << a1 << "\n";
	std::cout << "B1 =" << b1 << "\n";
	std::cout << "C1 =" << c1 << "\n";
	std::cout << "OK";

	std::cout << "\nCheck VectorXd abs :";
	double de[3] = { 1.0, -1.0, -3.333 };
	VectorXd<double, 3> e1(de);
	VectorXd<double, 3> f1 = e1.abs();
	assert(f1[_X_] == abs(e1[_X_]));
	assert(f1[_Y_] == abs(e1[_Y_]));
	assert(f1[_Z_] == abs(e1[_Z_]));
	std::cout << "OK";

	std::cout << "\nCheck VectorXd operator == :";
	assert(b1 == b1);
	assert(b1 == c1);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd operator != :";
	assert(f1 != e1);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd operator += ";
	VectorXd<double, 3> g1(de);
	g1 += b1;
	assert(g1[_X_] == e1[_X_] + b1[_X_]);
	assert(g1[_Y_] == e1[_Y_] + b1[_Y_]);
	assert(g1[_Z_] == e1[_Z_] + b1[_Z_]);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd operator + ";
	VectorXd<double, 3> h1 = d1 + b1;
	assert(h1[_X_] == d1[_X_] + b1[_X_]);
	assert(h1[_Y_] == d1[_Y_] + b1[_Y_]);
	assert(h1[_Z_] == d1[_Z_] + b1[_Z_]);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd operator -= ";
	VectorXd<double, 3> i1(de);
	i1 -= b1;
	assert(i1[_X_] == e1[_X_] - b1[_X_]);
	assert(i1[_Y_] == e1[_Y_] - b1[_Y_]);
	assert(i1[_Z_] == e1[_Z_] - b1[_Z_]);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd operator - ";
	VectorXd<double, 3> j1 = d1 - b1;
	assert(j1[_X_] == d1[_X_] - b1[_X_]);
	assert(j1[_Y_] == d1[_Y_] - b1[_Y_]);
	assert(j1[_Z_] == d1[_Z_] - b1[_Z_]);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd operator - ";
	double dj1a[3] = { 1.0, -2.0, -3.0 };
	VectorXd<double, 3> j1a(dj1a);
	VectorXd<double, 3> j1b = j1a.operator-();
	assert(dj1a[_X_] == -j1a[_X_]);
	assert(dj1a[_Y_] == -j1b[_Y_]);
	assert(dj1a[_Z_] == -j1b[_Z_]);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd operator *= ";
	VectorXd<double, 3> k1(d1);
	k1 *= 3.5;
	assert(k1[_X_] == d1[_X_] * 3.5);
	assert(k1[_Y_] == d1[_Y_] * 3.5);
	assert(k1[_Z_] == d1[_Z_] * 3.5);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd operator * : ";
	VectorXd<double, 3> l1 = d1 * 3.5;
	assert(l1[_X_] == d1[_X_] * 3.5);
	assert(l1[_Y_] == d1[_Y_] * 3.5);
	assert(l1[_Z_] == d1[_Z_] * 3.5);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd operator /= : ";
	VectorXd<double, 3> m1(d1);
	m1 /= 3.5;
	assert(m1[_X_] == d1[_X_] / 3.5);
	assert(m1[_Y_] == d1[_Y_] / 3.5);
	assert(m1[_Z_] == d1[_Z_] / 3.5);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd operator / : ";
	VectorXd<double, 3> n1 = d1 / 3.5;
	assert(n1[_X_] == d1[_X_] / 3.5);
	assert(n1[_Y_] == d1[_Y_] / 3.5);
	assert(n1[_Z_] == d1[_Z_] / 3.5);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd Min : ";
	double d3[5] = { 0.0, -1.0, 32.0 , 0.5, 25.0};
	VectorXd<double, 5> n5(d3);
	assert(n5.Min() == -1.0);
	std::cout << "OK";

	std::cout << "\nCheck VectorXd Max : ";
	assert(n5.Max() == 32.0);
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

	std::cout << "\nCheck Vector1d Zero : ";
	assert(Vector1d<double>::Zero().getX() == 0.0);
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

	std::cout << "\nCheck Vector2d Zero : ";
	assert(Vector2d<double>::Zero().getX() == 0.0);
	assert(Vector2d<double>::Zero().getY() == 0.0);
	std::cout << "OK";

	std::cout << "\nCheck Vector2d Axe X : ";
	assert(Vector2d<double>::AxisX().getX() == 1.0);
	assert(Vector2d<double>::AxisX().getY() == 0.0);
	std::cout << "OK";

	std::cout << "\nCheck Vector2d Axe Y : ";
	assert(Vector2d<double>::AxisY().getX() == 0.0);
	assert(Vector2d<double>::AxisY().getY() == 1.0);
	std::cout << "OK";

	std::cout << "\nCheck Vector2d operator * : ";
	Vector2d<double> v01a(0.1, 0.2);
	Vector2d<double> v01b(0.3, 0.4);
	assert((v01a * v01b) == ((0.1*0.4) - (0.2*0.3)));
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

	std::cout << "\nCheck Vector2d SetX et SetY : ";
	Vector2d<double> v01e(0.1, 0.2);
	v01e.setX(1.0);
	v01e.setY(2.0);
	assert(v01e.getX() == 1.0);
	assert(v01e.getY() == 2.0);
	std::cout << "OK";

	
	std::cout << "\nCheck Vector2d IsNormalized : ";
	Vector2d<double> v01f(0.1, 0.2);
	assert(v01f.IsNormalized() == false);
	v01f.setX(1.0);
	v01f.setY(0.0);
	assert(v01f.IsNormalized() == true);
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

	std::cout << "\nCheck Vector3d Zero : ";
	assert(Vector3d<double>::Zero().getX() == 0.0);
	assert(Vector3d<double>::Zero().getY() == 0.0);
	assert(Vector3d<double>::Zero().getZ() == 0.0);
	std::cout << "OK";

	std::cout << "\nCheck Vector3d Axe X : ";
	assert(Vector3d<double>::AxisX().getX() == 1.0);
	assert(Vector3d<double>::AxisX().getY() == 0.0);
	assert(Vector3d<double>::AxisX().getZ() == 0.0);
	std::cout << "OK";

	std::cout << "\nCheck Vector3d Axe Y : ";
	assert(Vector3d<double>::AxisY().getX() == 0.0);
	assert(Vector3d<double>::AxisY().getY() == 1.0);
	assert(Vector3d<double>::AxisY().getZ() == 0.0);
	std::cout << "OK";

	std::cout << "\nCheck Vector3d Axe Z : ";
	assert(Vector3d<double>::AxisZ().getX() == 0.0);
	assert(Vector3d<double>::AxisZ().getY() == 0.0);
	assert(Vector3d<double>::AxisZ().getZ() == 1.0);
	std::cout << "OK";

	std::cout << "\nCheck Vector3d operator ^ : ";
	Vector3d<double> v02a(0.1, 0.2,0.3);
	Vector3d<double> v02b(0.4, 0.5,0.6);
	assert((v02a * v02b) == ((0.1*0.4) + (0.2*0.5) + (0.3*0.6)));
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

	std::cout << "\nCheck Vector3d operator  : ";
	
	Vector3d<double> v02e(1, 0, 3);
	Vector3d<double> v02f(-2, 7, 8);
	Vector3d<double> v02g(	v02e.getY() * v02f.getZ() - v02e.getZ() * v02f.getY(),
							v02e.getZ() * v02f.getX() - v02e.getX() * v02f.getZ(),
							v02e.getX() * v02f.getY() - v02e.getY() * v02f.getX());
	Vector3d<double> v02h = v02e^v02f;
	assert(v02h == v02g);
	std::cout << "OK";

	std::cout << "\nCheck Vector3d SetX et SetY et SetZ : ";
	Vector3d<double> v02i(0.1, 0.2, 0.3);
	v02i.setX(1.0);
	v02i.setY(2.0);
	v02i.setZ(3.0);
	assert(v02i.getX() == 1.0);
	assert(v02i.getY() == 2.0);
	assert(v02i.getZ() == 3.0);
	std::cout << "OK";

	std::cout << "\nCheck Vector3d IsNormalized : ";
	Vector3d<double> v02j(0.1, 0.2,0.3);
	assert(v02j.IsNormalized() == false);
	v02j.setX(1.0);
	v02j.setY(0.0);
	v02j.setZ(0.0);
	assert(v02j.IsNormalized() == true);
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

	std::cout << "\nCheck Vector4d SetX et SetY et SetZ et SetT : ";
	Vector4d<double> v03a(0.1, 0.2, 0.3, 0.4);
	v03a.setX(1.0);
	v03a.setY(2.0);
	v03a.setZ(3.0);
	v03a.setT(4.0);
	assert(v03a.getX() == 1.0);
	assert(v03a.getY() == 2.0);
	assert(v03a.getZ() == 3.0);
	assert(v03a.getT() == 4.0);
	std::cout << "OK";

	std::cout << "\n---------------------------------------------------------------------";
	double dataExp2[2][3] = { { 0.0, 1.0, 2.0 }, { 3.0, 4.0, 5.0 } };

	std::cout << "\nCheck double[][] to list of Vector3d  : ";
	list<Vector3d<double>> lPoint = Vector3d<double>::ToList((double*)dataExp2, 2);
	std::cout << "OK";
	std::cout << "\nCheck double[][] to vector of Vector3d  : ";
	vector<Vector3d<double>> vPoint = Vector3d<double>::ToVector((double*)dataExp2, 2);
	std::cout << "OK";


	std::cout << "\n---------------------------------------------------------------------";
	std::cout << "\n---------------------------------------------------------------------";

	std::cout << "\n\n";
}

