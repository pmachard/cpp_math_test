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
		Check(c1.GetReal() == 0.0 && C1.GetImag() == 0.0,"Error in the default constuctor");
		
		Complex c2(1.0,2.0);
		Check(c2.GetReal() == 1.0 && C2.GetImag() == 2.0,"Error in the param constuctor");
		
		Complex c3(c2);
		Check(c2.GetReal() == c3.GetReal() && C2.GetImag() == C3.GetImag(),"Error in the copy constuctor");
		END_UNIT_TEST("TestConstructors")
	}
	
	void Run()
	{
		TestConstructors();
		PrintStat();
	}
};
int main(void)
{
TestComplex T1;
T1.Run();
return 0;
}
