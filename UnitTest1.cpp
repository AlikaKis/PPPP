#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "C:\\Users\\8181049\\source\\repos\\pppp_2\\pppp_2\\Source.cpp"

using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Main_test_TEST1)
		{
			Assert::IsTrue(Program(0, 0, 0, 0, 0, 0) == "5", L"Assert");
		}

		TEST_METHOD(Main_test_TEST2)
		{
			Assert::IsTrue(Program(0, 1, 0, 0, 1, 0) == "4 " + to_string(1.0) , L"Assert");
		}

		TEST_METHOD(Main_test_TEST3)
		{
			Assert::IsTrue(Program(0, 0, 0, 1, 0, 1) == "4 " + to_string(1.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST4)
		{
			Assert::IsTrue(Program(0, 1, 0, 0, 1, 0) == "4 " + to_string(1.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST5)
		{
			Assert::IsTrue(Program(0, 0, 0, 1, 0, 0) == "4 " + to_string(0.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST6)
		{
			Assert::IsTrue(Program(0, 0, 1, 0, 0, 0) == "3 " + to_string(0.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST7)
		{
			Assert::IsTrue(Program(1, 0, 0, 0, 5, 0) == "3 " + to_string(5.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST8)
		{
			Assert::IsTrue(Program(1, 0, 1, 0, 0, 0) == "3 " + to_string(0.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST9)
		{
			Assert::IsTrue(Program(0, 0, 0, 0, 1, 1) == "0", L"Assert");
		}

		TEST_METHOD(Main_test_TEST10)
		{
			Assert::IsTrue(Program(0, 0, 0, 1, 0, 1) == "4 " + to_string(1.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST11)
		{
			Assert::IsTrue(Program(3, 5, 4, 5, 3, 4) == "2 " + to_string(1.0) + to_string(0.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST12)
		{
			Assert::IsTrue(Program(5, 3, 5, 4, 3, 4) == "2 " + to_string(0.0) + to_string(1.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST13)
		{
			Assert::IsTrue(Program(0, 0, 1, 0, 0, 11) == "3 " + to_string(11.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST14)
		{
			Assert::IsTrue(Program(11, 0, 0, 0, 121, 0) == "3 " + to_string(11.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST15)
		{
			Assert::IsTrue(Program(8, 0, 4, 0, 4, 2) == "3 " + to_string(0.5), L"Assert");
		}

		TEST_METHOD(Main_test_TEST16)
		{
			Assert::IsTrue(Program(1, 0, 1, 1, 0, 0) == "1 " + to_string(-1.0) + " " + to_string(0.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST17)
		{
			Assert::IsTrue(Program(1, 1, 1, 0, 0, 0) == "1 " + to_string(-1.0) + " " + to_string(0.0), L"Assert");
		}
		TEST_METHOD(Main_test_TEST18)
		{
			Assert::IsTrue(Program(0, 2, 20, 1, 0, 0) == "1 " + to_string(-0.05) + " " + to_string(0.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST19)
		{
			Assert::IsTrue(Program(10, 10, 0, 2, 0, 0) == "1 " + to_string(-1.0) + " " + to_string(0.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST20)
		{
			Assert::IsTrue(Program(20, 20, 10, 10, 0, 0) == "1 " + to_string(-1.0) + " " + to_string(0.0), L"Assert");
		}

		TEST_METHOD(Main_test_TEST21)
		{
			Assert::IsTrue(Program(20, 20, 10, 9, 0, 0) == "Are you kidding me?");
		}

	};
}
