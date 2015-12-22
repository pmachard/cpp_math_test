/ cpp_math_test.cpp : main project file.
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include "../../cpp_unit_test/UnitTest.h"
#include "../../cpp_math_lib/IntVector2D.h"

using namespace prj::math;
using namespace prj::unit_test;

class TestIntVector2D : public UnitTest
{
public :
	TestIntVector2D() : UnitTest("TestIntVector2D")
	{
	}

	void TestConstructors(void)
	{
		BEGIN_UNIT_TEST("TestConstructors")
		IntVector2D * pv3;
		IntVector2D v1;
		IntVector2D v2(1, 2);
		pv3 = new IntVector2D(v2);

		Check(v1.GetX() == 0 && v1.GetY() == 0,"Error in the default constuctor");
		Check(v2.GetX() == 1 && v2.GetY() == 2, "Error in the constructor with 2 parameter");
		Check(pv3->GetX() == 1 && pv3->GetY() == 2, "Error in the constuctor with copy parameter");
		END_UNIT_TEST("TestConstructors")
	}

	void TestOperatorAffectation(void)
	{
		BEGIN_UNIT_TEST("TestOperatorAffectation")
		IntVector2D v1(1.0, 2.0);
		IntVector2D v2,v3;
		v3 = v2 = v1;

		Check(v2.GetX() == v1.GetX() && v2.GetY() == v1.GetY(), "Error in affection operator");
		Check(v3.GetX() == v1.GetX() && v3.GetY() == v1.GetY(), "Error in affection operator");
		END_UNIT_TEST("TestOperatorAffectation")
	}

	void TestAbs(void)
	{
		BEGIN_UNIT_TEST("TestABs")
		IntVector2D v1(-1.0, -2.0);
		IntVector2D v2 = v1.abs();

		Check(v2.GetX() == -v1.GetX(), "Error in affection Abs function");
		Check(v2.GetY() == -v1.GetY(), "Error in affection Abs function");
		END_UNIT_TEST("TestABs")
	}

	void TestOperatorAdd(void)
	{
		BEGIN_UNIT_TEST("TestOperatorAdd")
		IntVector2D v1(1, -2);
		IntVector2D v2(5, 1);
		IntVector2D v3 = v1 + v2;
		IntVector2D v4 = v1;
		v4+=v2;

		Check(v3.GetX() == (v1.GetX() + v2.GetX()) , "Error in additional operator");
		Check(v3.GetY() == (v1.GetY() + v2.GetY()) , "Error in additional operator");
		Check(v4.GetX() == (v1.GetX() + v2.GetX()) , "Error in additional operator");
		Check(v4.GetY() == (v1.GetY() + v2.GetY()) , "Error in additional operator");
		END_UNIT_TEST("TestOperatorAdd")
	}

	void TestOperatorSupp(void)
	{
		BEGIN_UNIT_TEST("TestOperatorSupp")
		IntVector2D v1(1, -2);
		IntVector2D v2(5, 1);
		IntVector2D v3 = v1 - v2;
		IntVector2D v4 = v1;
		v4-=v2;

		Check(v3.GetX() == (v1.GetX() - v2.GetX()) , "Error in diff operator");
		Check(v3.GetY() == (v1.GetY() - v2.GetY()) , "Error in diff operator");
		Check(v4.GetX() == (v1.GetX() - v2.GetX()) , "Error in diff operator");
		Check(v4.GetY() == (v1.GetY() - v2.GetY()) , "Error in diff operator");
		END_UNIT_TEST("TestOperatorSupp")
	}

	void TestOperatorMult(void)
	{
		BEGIN_UNIT_TEST("TestOperatorMult")
		IntVector2D v1(1, -2);
		IntVector2D v2 = v1 * 10;
		IntVector2D v3 = v1;
		v3*=10;

		Check(v2.GetX() == v1.GetX() * 10 , "Error in multiplication operator");
		Check(v2.GetY() == v1.GetY() * 10 , "Error in multiplication operator");
		Check(v3.GetX() == v1.GetX() * 10 , "Error in multiplication operator");
		Check(v3.GetY() == v1.GetY() * 10 , "Error in multiplication operator");
		END_UNIT_TEST("TestOperatorMult")
	}
	
	void TestOperatorMultBis(void)
	{
		BEGIN_UNIT_TEST("TestOperatorMultBis")
		IntVector2D v1(1.5, -2.3);
		IntVector2D v2(2, -9);
		IntVector2D v3 = v1 * v2;
		IntVector2D v4 = v1;
		v4*=v2;

		Check(v3.GetX() == v1.GetX() * v2.GetX() , "Error in multiplication operator");
		Check(v3.GetY() == v1.GetY() * v2.GetY() , "Error in multiplication operator");
		Check(v4.GetX() == v1.GetX() * v2.GetX() , "Error in multiplication operator");
		Check(v4.GetY() == v1.GetY() * v2.GetY() , "Error in multiplication operator");
		END_UNIT_TEST("TestOperatorMultBis")
	}	

	void TestOperatorDiv(void)
	{
		BEGIN_UNIT_TEST("TestOperatorDiv")
		IntVector2D v1(9, 30);
		IntVector2D v2 = v1 / 3;
		IntVector2D v3 = v1;
		v3/=3;

		Check(v2.GetX() == v1.GetX() / 0.75 , "Error in division operator");
		Check(v2.GetY() == v1.GetY() / 0.75 , "Error in division operator");
		Check(v3.GetX() == v1.GetX() / 0.75 , "Error in division operator");
		Check(v3.GetY() == v1.GetY() / 0.75 , "Error in division operator");
		END_UNIT_TEST("TestOperatorDiv")
	}
	
	void TestOperatorEqualDiff(void)
	{
		BEGIN_UNIT_TEST("TestOperatorEqualDiff")
		IntVector2D v1(1, -2);
		IntVector2D v2(5, -5);
		IntVector2D v3(1, -5);
		
		Check(v1 == v2 , "Error in division operator");
		Check(v1 != v3 , "Error in division operator");
		END_UNIT_TEST("TestOperatorEqualDiff")
	}	
	
	void TestOperatorEqualProdScal(void)
	{
		BEGIN_UNIT_TEST("TestOperatorEqualProdScal")
		IntVector2D v1(1, -2);
		IntVector2D v2(5, 3);
		
		int result = v1^v2;

		Check(result == (v1.m_x * v2.m_y) - (v1.m_y * v2.m_x) , "Error in product scalar");
		END_UNIT_TEST("TestOperatorEqualProdScal")
	}	

	void TestMakeVector(void)
	{
		BEGIN_UNIT_TEST("TestMakeVector")
		IntVector2D v1(1.0, -2.0);
		IntVector2D v2 = v1.MakeXY();
		Check(result == (v1.m_x == v2.m_x) && (v2.m_y == v1.m_y) , "Error in method MakeXY");
		
		v2 = v1.MakeXX();
		Check(result == (v2.m_x == v1.m_x) && (v2.m_y == v1.m_x) , "Error in method MakeXX");
		
		v2 = v1.MakeYX();
		Check(result == (v2.m_x == v1.m_y) && (v2.m_y == v1.m_x) , "Error in method MakeYX");
		
		v2 = v1.MakeYX();
		Check(result == (v2.m_x == v1.m_y) && (v2.m_y == v1.m_y) , "Error in method MakeYY");
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
		TestMakeVector();
		
		TestOperatorEqualDiff();

		PrintStat();

	}
};

int main(void)
{
	TestIntVector2D T1;
	T1.Run();
    return 0;
}
Status 
