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
