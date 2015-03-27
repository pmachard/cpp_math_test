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
		try
		{
			SimpleVector2D * pv3;
			SimpleVector2D v1;
			SimpleVector2D v2(1.0, 2.0);
			pv3 = new SimpleVector2D(v2);

			Check(v1.GetX() == 0.0 && v1.GetY() == 0.0,"Error in the default constuctor");
			Check(v2.GetX() == 1.0 && v2.GetY() == 2.0, "Error in the constructor with 2 parameter");
			Check(pv3->GetX() == 1.0 && pv3->GetY() == 2.0, "Error in the constuctor with copy parameter");
		}
		catch (...)
		{
			std::cout << "Error when run TestSimpleVector2D_TestConstructor\n";
		}
	}

	void TestOperatorAffectation(void)
	{
		try
		{
			SimpleVector2D v1(1.0, 2.0);
			SimpleVector2D v2 = v1;

			Check(v2.GetX() == 1.0 && v2.GetY() == 2.0, "Error in affection operator");
		}
		catch (...)
		{
			std::cout << "<Error>when run TestSimpleVector2D_TestOperatorAffectation</Error>\n";
		}
	}

	void Run()
	{
		TestConstructors();
		TestOperatorAffectation();

		char aux[250];
		sprintf(aux,"%d",GetNbrOk());
		std::cout << "<Checks Ok>"+std::string(aux)+"</Checks Ok>\n";
		sprintf(aux,"%d",GetNbrKo());
		std::cout << "<Checks Ko>"+std::string(aux)+"</Checks Ko>\n";
		sprintf(aux,"%d",GetNbrOk()+GetNbrKo());
		std::cout << "<Checks>"+std::string(aux)+"</Checks>\n";

	}
};

int main(void)
{
	TestSimpleVector2D T1;
	T1.Run();
    return 0;
}
