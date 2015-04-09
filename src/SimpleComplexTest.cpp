#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "../../cpp_unit_test/UnitTest.h"
#include "../../cpp_math_lib/SimpleComplex.h"

using namespace prj::math;
using namespace prj::unit_test;
class TestSimpleComplex : public UnitTest
{
public :
	TestSimpleComplex() : UnitTest("TestSimpleComplex")
	{
	}
	void TestConstructors(void)
	{
		BEGIN_UNIT_TEST("TestConstructors")
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
TestSimpleVector2D T1;
T1.Run();
return 0;
}
