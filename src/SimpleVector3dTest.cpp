// cpp_math_test.cpp : main project file.
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "../../cpp_unit_test/UnitTest.h"
#include "../../cpp_math_lib/SimpleVector3D.h"
using namespace prj::math;
using namespace prj::unit_test;

class TestSimpleVector3D : public UnitTest
{
public :

	TestSimpleVector3D() : UnitTest("TestSimpleVector3D")
	{
	}
	
	void TestConstructors(void)
	{
		BEGIN_UNIT_TEST("TestConstructors")
		
		SimpleVector3D * pv3;
		SimpleVector3D v1;
		SimpleVector3D v2(1.0, 2.0,3.0);
		pv3 = new SimpleVector3D(v2);
		
		Check(v1.GetX() == 0.0 && v1.GetY() == 0.0 && v1.GetZ() == 0.0,"Error in the default constuctor");
		Check(v2.GetY() == 1.0 && v2.GetY() == 2.0 && v2.GetZ() == 3.0, "Error in the constructor with 2 parameter");
		Check(pv3->GetX() == 1.0 && pv3->GetY() == 2.0 && pv3->GetZ() == 3.0, "Error in the constuctor with copy parameter");
		END_UNIT_TEST("TestConstructors")
	}
	
	void TestOperatorAffectation(void)
	{
		BEGIN_UNIT_TEST("TestOperatorAffectation")
		
		SimpleVector3D v1(1.0, 2.0, 3.0);
		SimpleVector3D v2,v3;
		v3 = v2 = v1;
		
		Check(v2.GetX() == v1.GetX() && v2.GetY() == v1.GetY() && v2.GetZ() == v1.GetZ(), "Error in affection operator");
		Check(v3.GetX() == v1.GetX() && v3.GetY() == v1.GetY() && v3.GetZ() == v1.GetZ(), "Error in affection operator");
		
		END_UNIT_TEST("TestOperatorAffectation")
	}
	
	void TestAbs(void)
	{
		BEGIN_UNIT_TEST("TestABs")
		
		SimpleVector3D v1(-1.0, -2.0,-3.0);
		SimpleVector3D v2 = v1.abs();
		
		CheckEqual(v2.GetX(),-v1.GetX(), "Error in affection Abs function");
		CheckEqual(v2.GetY(),-v1.GetY(), "Error in affection Abs function");
		CheckEqual(v2.GetZ(),-v1.GetZ(), "Error in affection Abs function");
		
		END_UNIT_TEST("TestABs")
	}
	
	void TestOperatorAdd(void)
	{
		BEGIN_UNIT_TEST("TestOperatorAdd")
		
		SimpleVector3D v1(1.5, -2.3, 0.25);
		SimpleVector3D v2(0.7, 0.33, 0.15);
		SimpleVector3D v3 = v1 + v2;
		SimpleVector3D v4 = v1;
		v4+=v2;
		
		CheckEqual(v3.GetX(), v1.GetX() + v2.GetX() , "Error in additional operator");
		CheckEqual(v3.GetY(), v1.GetY() + v2.GetY() , "Error in additional operator");
		CheckEqual(v3.GetZ(), v1.GetZ() + v2.GetZ() , "Error in additional operator");
		CheckEqual(v4.GetX(), v1.GetX() + v2.GetX() , "Error in additional operator");
		CheckEqual(v4.GetY(), v1.GetY() + v2.GetY() , "Error in additional operator");
		CheckEqual(v4.GetZ(), v1.GetZ() + v2.GetZ() , "Error in additional operator");
		
		END_UNIT_TEST("TestOperatorAdd")
	}
	
	void TestOperatorSupp(void)
	{
		BEGIN_UNIT_TEST("TestOperatorSupp")
		
		SimpleVector3D v1(1.5, -2.3, 0.25);
		SimpleVector3D v2(0.7, 0.33, 0.15);
		SimpleVector3D v3 = v1 - v2;
		SimpleVector3D v4 = v1;
		v4-=v2;
		
		CheckEqual(v3.GetX(), v1.GetX() - v2.GetX() , "Error in diff operator");
		CheckEqual(v3.GetY(), v1.GetY() - v2.GetY() , "Error in diff operator");
		CheckEqual(v3.GetZ(), v1.GetZ() - v2.GetZ() , "Error in diff operator");
		CheckEqual(v4.GetX(), v1.GetX() - v2.GetX() , "Error in diff operator");
		CheckEqual(v4.GetY(), v1.GetY() - v2.GetY() , "Error in diff operator");
		CheckEqual(v4.GetZ(), v1.GetZ() - v2.GetZ() , "Error in diff operator");
		
		END_UNIT_TEST("TestOperatorSupp")
	}
	
	void TestOperatorMult(void)
	{
		BEGIN_UNIT_TEST("TestOperatorMult")
		
		SimpleVector3D v1(1.5, -2.3, 0.25);
		SimpleVector3D v2 = v1 * 0.75;
		SimpleVector3D v3 = v1;
		v3*=0.75;
		
		CheckEqual(v2.GetX(), v1.GetX() * 0.75 , "Error in multiplication operator");
		CheckEqual(v2.GetY(), v1.GetY() * 0.75 , "Error in multiplication operator");
		CheckEqual(v2.GetZ(), v1.GetZ() * 0.75 , "Error in multiplication operator");
		CheckEqual(v3.GetX(), v1.GetX() * 0.75 , "Error in multiplication operator");
		CheckEqual(v3.GetY(), v1.GetY() * 0.75 , "Error in multiplication operator");
		CheckEqual(v3.GetZ(), v1.GetZ() * 0.75 , "Error in multiplication operator");
		
		END_UNIT_TEST("TestOperatorMult")
	}
	
	void TestOperatorMultBis(void)
	{
		BEGIN_UNIT_TEST("TestOperatorMultBis")
		
		SimpleVector3D v1(1.5, -2.3, 0.25);
		SimpleVector3D v2(0.7, 0.33, 0.15);
		SimpleVector3D v3 = v1 * v2;
		SimpleVector3D v4 = v1;
		v4*=v2;
		
		CheckEqual(v3.GetX(), v1.GetX() * v2.GetX() , "Error in multiplication operator");
		CheckEqual(v3.GetY(), v1.GetY() * v2.GetY() , "Error in multiplication operator");
		CheckEqual(v3.GetZ(), v1.GetZ() * v2.GetZ() , "Error in multiplication operator");
		CheckEqual(v4.GetX(), v1.GetX() * v2.GetX() , "Error in multiplication operator");
		CheckEqual(v4.GetY(), v1.GetY() * v2.GetY() , "Error in multiplication operator");
		CheckEqual(v4.GetZ(), v1.GetZ() * v2.GetZ() , "Error in multiplication operator");
		
		END_UNIT_TEST("TestOperatorMultBis")
	}
	
	void TestOperatorDiv(void)
	{
		BEGIN_UNIT_TEST("TestOperatorDiv")
		
		SimpleVector3D v1(1.5, -2.3, 0.25);
		SimpleVector2D v2 = v1 / 0.75;
		SimpleVector2D v3 = v1;
		v3/=0.75;
		
		CheckEqual(v2.GetX(), v1.GetX() / 0.75 , "Error in division operator");
		CheckEqual(v2.GetY(), v1.GetY() / 0.75 , "Error in division operator");
		CheckEqual(v2.GetZ(), v1.GetZ() / 0.75 , "Error in division operator");
		CheckEqual(v3.GetX(), v1.GetX() / 0.75 , "Error in division operator");
		CheckEqual(v3.GetY(), v1.GetY() / 0.75 , "Error in division operator");
		CheckEqual(v3.GetZ(), v1.GetZ() / 0.75 , "Error in division operator");
		
		END_UNIT_TEST("TestOperatorDiv")
	}
	
	void TestOperatorEqualDiff(void)
	{
		BEGIN_UNIT_TEST("TestOperatorEqualDiff")
		
		SimpleVector3D v1(1.5, -2.3,0.15);
		SimpleVector3D v2(1.5, -2.3,0.15);
		SimpleVector3D v3(1.0, 2.3,0.15);
		
		Check(v1 == v2 , "Error in division operator");
		Check(v1 != v3 , "Error in division operator");
		
		END_UNIT_TEST("TestOperatorEqualDiff")
	}
	
	void TestOperatorEqualProdScal(void)
	{
		BEGIN_UNIT_TEST("TestOperatorEqualProdScal")
		
		SimpleVector3D v1(1.5, -2.3,0.15);
		SimpleVector3D v2(1.0, 2.3,0.15);
		
		double result = v1^v2;
		
		CheckEqual(result,(v1.m_x * v2.m_y) - (v1.m_y * v2.m_x) , "Error in product scalar");
		
		END_UNIT_TEST("TestOperatorEqualProdScal")
	}
	
	void TestMakeVector(void)
	{
		BEGIN_UNIT_TEST("TestMakeVector")
		SimpleVector3D v1(1.0, -2.0, 3.0);
		SimpleVector3D v2 = v1.MakeXYZ();
		Check(result == (v1.m_x == v2.m_x) && (v1.m_y == v2.m_y) && (v1.m_z == v2.m_z) , "Error in method MakeXYZ");
		
		v2 = v1.MakeXXX();
		Check(result == (v2.m_x == v1.m_x) && (v2.m_y == v1.m_x) && (v2.m_z == v1.m_x) , "Error in method MakeXXX");
		
		v2 = v1.MakeYYY();
		Check(result == (v2.m_x == v1.m_y) && (v2.m_y == v1.m_y) && (v2.m_z == v1.m_y) , "Error in method MakeYYY");
		
		v2 = v1.MakeZZZ();
		Check(result == (v2.m_x == v1.m_z) && (v2.m_y == v1.m_z) && (v2.m_z == v1.m_z) , "Error in method MakeZZZ");
		
		v2 = v1.MakeYZX();
		Check(result == (v2.m_x == v1.m_y) && (v2.m_y == v1.m_z) && (v2.m_z == v1.m_x) , "Error in method MakeYZX");
		
		v2 = v1.MakeZXY();
		Check(result == (v2.m_x == v1.m_z) && (v2.m_y == v1.m_x) && (v2.m_z == v1.m_y) , "Error in method MakeZXY");
		
		v2 = v1.MakeZYX();
		Check(result == (v2.m_x == v1.m_z) && (v2.m_y == v1.m_y) && (v2.m_z == v1.m_x) , "Error in method MakeZYX");
		
		END_UNIT_TEST("TestMakeVector")
	}	
	
	void Run()
	{
		TestConstructors();
		TestOperatorAffectation();
		TestAbs();
		TestOperatorAdd();
		TestOperatorSupp();
		TestOperatorMult();
		TestOperatorMultBis();
		TestOperatorDiv();
		TestOperatorEqualProdScal();
		
		TestOperatorEqualDiff();
		
		PrintStat();
	}
};


int main(void)
{
  TestSimpleVector3D T1;
  T1.Run();
  return 0;
}
