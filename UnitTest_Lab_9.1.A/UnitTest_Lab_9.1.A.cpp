﻿#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_9.1.A/LAB.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab91A
{
	TEST_CLASS(UnitTestLab91A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int N = 3;
			Student students[N] =
			{
				{"joe", 1, KN, 5, 5, 4},
				{"doe", 1, IT, 4, 5, 5},
				{"rob", 2, KN, 5, 4, 4}
			};

		
			std::stringstream buffer;
			std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

		
			Student_Who_have_5(students, N);

	
			std::cout.rdbuf(oldCout);

			
			Assert::AreEqual("joe\nrob\n", buffer.str().c_str());
             
		}
	};
}
