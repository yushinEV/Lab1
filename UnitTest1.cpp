#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab2Aistrd_Ushin/Func.h"
using namespace
Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		TEST_METHOD(CountingSort_test)
		{
			char_arr Ch(10);
			Ch.CountingSort();
			Assert::IsTrue(Ch.sorted());
			Ch.CountingSort();
			Assert::IsTrue(Ch.sorted());
		}
		TEST_METHOD(QuickSort_test)
		{
			Array Int(10);
			Int.QuickSort();
			Assert::IsTrue(Int.sorted());
			Int.QuickSort();
			Assert::IsTrue(Int.sorted());
		}
		TEST_METHOD(InsertionSort_test)
		{
			Array Int(10);
			Int.InsertionSort();
			Assert::IsTrue(Int.sorted());
			Int.InsertionSort();
			Assert::IsTrue(Int.sorted());
		}
		TEST_METHOD(BogoSort_test)
		{
			Array Int(5);
			Int.BogoSort();
			Assert::IsTrue(Int.sorted());
			Int.BogoSort();
			Assert::IsTrue(Int.sorted());
		}
		TEST_METHOD(BiniarySearch_test)
		{
			Array Int(10);
			int elem = Int.getelem(4);
			Int.InsertionSort();
			size_t index = Int.BiniarySearch(elem);
			Assert::AreEqual(elem, Int.getelem(index));
		}
	};
}
