#include "pch.h"
#include "CppUnitTest.h"
#include "../L1/L1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(push_back)
		{
			List L;
			L.push_back(1);
			L.push_back(2);
			Assert::AreEqual(L.at(0), 1);
			Assert::AreEqual(L.at(1), 2);
		}
		TEST_METHOD(push_front)
		{
			List L;
			L.push_front(1);
			L.push_front(2);
			Assert::AreEqual(L.at(0), 2);
			Assert::AreEqual(L.at(1), 1);
		}
		TEST_METHOD(pop_back)
		{
			List L;
			L.push_back(1);
			L.push_back(2);
			L.pop_back();
			Assert::AreEqual(L.at(0), 1);
			L.pop_back();
			Assert::IsTrue(L.isEmpty());
			try
			{
				L.pop_back();
				Assert::IsTrue(0);
			}
			catch(exception&exception){}
		}
		TEST_METHOD(pop_front)
		{
			List L;
			L.push_back(1);
			L.push_back(2);
			L.pop_front();
			Assert::AreEqual(L.at(0), 2);
			L.pop_front();
			Assert::IsTrue(L.isEmpty());
			try
			{
				L.pop_front();
				Assert::IsTrue(0);
			}
			catch (exception& exception) {}
		}
		TEST_METHOD(insert)
		{
			List L;
			L.push_back(1);
			L.push_back(3);
			L.insert(1, 2);
			L.insert(0, 0);
			L.insert(4, 4);
			Assert::AreEqual(L.at(0), 0);
			Assert::AreEqual(L.at(1), 1);
			Assert::AreEqual(L.at(2), 2);
			Assert::AreEqual(L.at(3), 3);
			Assert::AreEqual(L.at(4), 4);
			try
			{
				L.insert(10, 10);
				Assert::IsTrue(0);
			}
			catch (exception& exception) {}
		}
		TEST_METHOD(remove)
		{
			List L;
			L.push_back(1);
			L.push_back(2);
			L.push_back(3);
			L.remove(1);
			Assert::AreEqual(L.at(0), 1);
			Assert::AreEqual(L.at(1), 3);
			try
			{
				L.remove(10);
				Assert::IsTrue(0);
			}
			catch (exception& exception) {}
		}
		TEST_METHOD(clear)
		{
			List L;
			L.push_back(1);
			L.push_back(2);
			L.push_back(3);
			L.push_back(4);
			L.clear();
			Assert::IsTrue(L.isEmpty());
		}
		TEST_METHOD(set)
		{
			List L;
			L.push_back(1);
			L.push_back(3);
			L.insert(1, 2);
			L.set(1, 4);
			Assert::AreEqual(L.at(0), 1);
			Assert::AreEqual(L.at(1), 4);
			Assert::AreEqual(L.at(2), 3);
			try
			{
				L.insert(10, 10);
				Assert::IsTrue(0);
			}
			catch (exception& exception) {}
		}
		TEST_METHOD(swap)
		{
			List L;
			L.push_back(1);
			L.push_back(2);
			L.push_back(3);
			L.push_back(4);
			L.swap(1, 3);
			Assert::AreEqual(L.at(0), 1);
			Assert::AreEqual(L.at(1), 4);
			Assert::AreEqual(L.at(2), 3);
			Assert::AreEqual(L.at(3), 2);
			try
			{
				L.swap(10, 11);
				Assert::IsTrue(0);
			}
			catch (exception& exception) {}
		}
	};
}
