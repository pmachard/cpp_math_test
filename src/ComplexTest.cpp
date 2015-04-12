#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "../../cpp_unit_test/UnitTest.h"
#include "../../cpp_math_lib/Complex.h"

using namespace prj::math;
using namespace prj::unit_test;
class TestComplex : public UnitTest
{
public :
	TestComplex() : UnitTest("TestComplex")
	{
	}
	void TestConstructors(void)
	{
		BEGIN_UNIT_TEST("TestConstructors")
		Complex c1;
		Check(c1.GetReal() == 0.0 && c1.GetImag() == 0.0,"Error in the default constuctor");
		
		Complex c2(1.0,2.0);
		Check(c2.GetReal() == 1.0 && c2.GetImag() == 2.0,"Error in the param constuctor");
		
		Complex *pc3 = new Complex(c2);
		Check(c2.GetReal() == pc3->GetReal() && c2.GetImag() == pc3->GetImag(),"Error in the copy constuctor");
		END_UNIT_TEST("TestConstructors")
	}
	
	void TestOperatorAffectation(void)
	{
		BEGIN_UNIT_TEST("TestOperatorAffectation")
		Complex v1(1.0, 2.0);
		Complex v2,v3;
		v3 = v2 = v1;
		Check(v2.GetReal() == v1.GetReal() && v2.GetImag() == v1.GetImag(), "Error in affection operator");
		Check(v3.GetReal() == v1.GetReal() && v3.GetImag() == v1.GetImag(), "Error in affection operator");
		END_UNIT_TEST("TestOperatorAffectation")
	}
	
	
	void Run()
	{
		TestConstructors();
		TestOperatorAffectation();
		PrintStat();
	}
};
int main(void)
{
TestComplex T1;
T1.Run();
return 0;
}
