// cpp_math_test.cpp : main project file.
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include "../../cpp_unit_test/UnitTest.h"
#include "../../cpp_math_lib/SimpleVector2D.h"

using namespace prj::math;
using namespace prj::unit_test;

class TestSimpleVector2D : public UnitTest
{
public :

	TestSimpleVector2D() : UnitTest("TestSimpleVector2D")
	{
	}

	void TestConstructors(void)
	{
		BEGIN_UNIT_TEST("TestConstructors")

			SimpleVector2D * pv3;
			SimpleVector2D v1;
			SimpleVector2D v2(1.0, 2.0);
			pv3 = new SimpleVector2D(v2);

			Check(v1.GetX() == 0.0 && v1.GetY() == 0.0,"Error in the default constuctor");
			Check(v2.GetX() == 1.0 && v2.GetY() == 2.0, "Error in the constructor with 2 parameter");
			Check(pv3->GetX() == 1.0 && pv3->GetY() == 2.0, "Error in the constuctor with copy parameter");
		END_UNIT_TEST("TestConstructors")
	}

	void TestOperatorAffectation(void)
	{
		BEGIN_UNIT_TEST("TestOperatorAffectation")

			SimpleVector2D v1(1.0, 2.0);
			SimpleVector2D v2,v3;
			v3 = v2 = v1;

			Check(v2.GetX() == v1.GetX() && v2.GetY() == v1.GetY(), "Error in affection operator");
			Check(v3.GetX() == v1.GetX() && v3.GetY() == v1.GetY(), "Error in affection operator");

		END_UNIT_TEST("TestOperatorAffectation")
	}

	void TestAbs(void)
	{
		BEGIN_UNIT_TEST("TestABs")

			SimpleVector2D v1(-1.0, -2.0);
			SimpleVector2D v2 = v1.abs();

			CheckEqual(v2.GetX(),-v1.GetX(), "Error in affection Abs function");
			CheckEqual(v2.GetY(),-v1.GetY(), "Error in affection Abs function");

		END_UNIT_TEST("TestABs")
	}

	void TestOperatorAdd(void)
	{
		BEGIN_UNIT_TEST("TestOperatorAdd")

			SimpleVector2D v1(1.5, -2.3);
			SimpleVector2D v2(0.7, 0.33);
			SimpleVector2D v3 = v1 + v2;
			SimpleVector2D v4 = v1;
			v4+=v2;

			CheckEqual(v3.GetX(), v1.GetX() + v2.GetX() , "Error in additional operator");
			CheckEqual(v3.GetY(), v1.GetY() + v2.GetY() , "Error in additional operator");
			CheckEqual(v4.GetX(), v1.GetX() + v2.GetX() , "Error in additional operator");
			CheckEqual(v4.GetY(), v1.GetY() + v2.GetY() , "Error in additional operator");

		END_UNIT_TEST("TestOperatorAdd")
	}

	void TestOperatorSupp(void)
	{
		BEGIN_UNIT_TEST("TestOperatorSupp")

			SimpleVector2D v1(1.5, -2.3);
			SimpleVector2D v2(0.7, 0.33);
			SimpleVector2D v3 = v1 - v2;
			SimpleVector2D v4 = v1;
			v4-=v2;

			CheckEqual(v3.GetX(), v1.GetX() - v2.GetX() , "Error in diff operator");
			CheckEqual(v3.GetY(), v1.GetY() - v2.GetY() , "Error in diff operator");
			CheckEqual(v4.GetX(), v1.GetX() - v2.GetX() , "Error in diff operator");
			CheckEqual(v4.GetY(), v1.GetY() - v2.GetY() , "Error in diff operator");

		END_UNIT_TEST("TestOperatorSupp")
	}

	void TestOperatorMult(void)
	{
		BEGIN_UNIT_TEST("TestOperatorMult")

			SimpleVector2D v1(1.5, -2.3);
			SimpleVector2D v2 = v1 * 0.75;
			SimpleVector2D v3 = v1;
			v3*=0.75;

			CheckEqual(v2.GetX(), v1.GetX() * 0.75 , "Error in multiplication operator");
			CheckEqual(v2.GetY(), v1.GetY() * 0.75 , "Error in multiplication operator");
			CheckEqual(v3.GetX(), v1.GetX() * 0.75 , "Error in multiplication operator");
			CheckEqual(v3.GetY(), v1.GetY() * 0.75 , "Error in multiplication operator");

		END_UNIT_TEST("TestOperatorMult")
	}
	
	void TestOperatorMultBis(void)
	{
		BEGIN_UNIT_TEST("TestOperatorMultBis")

			SimpleVector2D v1(1.5, -2.3);
			SimpleVector2D v2(0.5, -2);
			SimpleVector2D v3 = v1 * v2;
			SimpleVector2D v4 = v1;
			v4*=v2;

			CheckEqual(v3.GetX(), v1.GetX() * v2.GetX() , "Error in multiplication operator");
			CheckEqual(v3.GetY(), v1.GetY() * v2.GetY() , "Error in multiplication operator");
			CheckEqual(v4.GetX(), v1.GetX() * v2.GetX() , "Error in multiplication operator");
			CheckEqual(v4.GetY(), v1.GetY() * v2.GetY() , "Error in multiplication operator");

		END_UNIT_TEST("TestOperatorMultBis")
	}	

	void TestOperatorDiv(void)
	{
		BEGIN_UNIT_TEST("TestOperatorDiv")

			SimpleVector2D v1(1.5, -2.3);
			SimpleVector2D v2 = v1 / 0.75;
			SimpleVector2D v3 = v1;
			v3/=0.75;

			CheckEqual(v2.GetX(), v1.GetX() / 0.75 , "Error in division operator");
			CheckEqual(v2.GetY(), v1.GetY() / 0.75 , "Error in division operator");
			CheckEqual(v3.GetX(), v1.GetX() / 0.75 , "Error in division operator");
			CheckEqual(v3.GetY(), v1.GetY() / 0.75 , "Error in division operator");

		END_UNIT_TEST("TestOperatorDiv")
	}
	
	void TestOperatorEqualDiff(void)
	{
		BEGIN_UNIT_TEST("TestOperatorEqualDiff")

			SimpleVector2D v1(1.5, -2.3);
			SimpleVector2D v2(1.5, -2.3);
			SimpleVector2D v3(1.0, 2.3);
			
			CheckEqual(v1 == v2 , "Error in division operator");
			CheckEqual(v1 != v3 , "Error in division operator");

		END_UNIT_TEST("TestOperatorEqualDiff")
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
		
		TestOperatorEqualDiff();

		PrintStat();

	}
};

int main(void)
{
	TestSimpleVector2D T1;
	T1.Run();
    return 0;
}
