// cpp_math_test.cpp : main project file.
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "../../cpp_unit_test/UnitTest.h"
#include "../../cpp_math_lib/TplMatrix.h"
using namespace prj::math;
using namespace prj::unit_test;

class TplMatrixTest : public UnitTest
{
public :

	TplMatrixTest() : UnitTest("TplMatrixTest")
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
  TplMatrixTest T1;
  T1.Run();
  return 0;
}
