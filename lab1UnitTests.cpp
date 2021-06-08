#include "pch.h"
#include "CppUnitTest.h"
#include "../4sem 1L Algh/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab1UnitTests
{
	TEST_CLASS(lab1UnitTests)
	{
	public:
		
		TEST_METHOD(insert)
		{
			string expected;
			RBTree Tree;

			Tree.insert(6, 'G');
			expected = "G ";
			Assert::AreEqual(expected, Tree.get_values());

			Tree.insert(7, 'F');
			expected = "G F ";
			Assert::AreEqual(expected, Tree.get_values());

			Tree.insert(8, 'H');
			expected = "F G H ";
			Assert::AreEqual(expected, Tree.get_values());

			Tree.insert(3, 'B');
			expected = "F G B H ";
			Assert::AreEqual(expected, Tree.get_values());

			Tree.insert(5, 'A');
			expected = "F A B G H ";
			Assert::AreEqual(expected, Tree.get_values());

			Tree.insert(2, 'C');
			expected = "F A B C G H ";
			Assert::AreEqual(expected, Tree.get_values());

			Tree.insert(4, 'E');
			expected = "F A B C E G H ";
			Assert::AreEqual(expected, Tree.get_values());

			Tree.insert(1, 'D');
			expected = "A B C D E F G H ";
			Assert::AreEqual(expected, Tree.get_values());
		}

		TEST_METHOD(insert_exception)
		{
			RBTree Tree;
			bool b = 0;
			Tree.insert(1, 'A');
			try
			{
				Tree.insert(1, 'B');
				Assert::IsTrue(0);
			}
			catch (exception& invalid_argument)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}

		TEST_METHOD(remove)
		{
			string expected;
			RBTree Tree;
			Tree.insert(6, 'G');
			Tree.insert(7, 'F');
			Tree.insert(8, 'H');
			Tree.insert(3, 'B');
			Tree.insert(5, 'A');
			Tree.insert(2, 'C');
			Tree.insert(4, 'E');
			Tree.insert(1, 'D');

			Tree.remove(1);
			expected = "A B C E F G H ";
			Assert::AreEqual(expected, Tree.get_values());

			Tree.insert(1, 'D');
			Tree.remove(2);
			expected = "A B D E F G H ";
			Assert::AreEqual(expected, Tree.get_values());

			Tree.remove(1);
			expected = "A B E F G H ";
			Assert::AreEqual(expected, Tree.get_values());

			Tree.remove(4);
			Tree.remove(3);
			expected = "F A G H ";
			Assert::AreEqual(expected, Tree.get_values());

			Tree.remove(6);
			Tree.remove(5);
			expected = "F H ";
			Assert::AreEqual(expected, Tree.get_values());
		}

		TEST_METHOD(remove_exception1)
		{
			RBTree Tree;
			bool b = 0;
			try
			{
				Tree.remove(1);
				Assert::IsTrue(0);
			}
			catch (exception& runtime_error)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}

		TEST_METHOD(remove_exception2)
		{
			RBTree Tree;
			bool b = 0;
			Tree.insert(1, 'A');
			try
			{
				Tree.remove(2);
				Assert::IsTrue(0);
			}
			catch (exception& runtime_error)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}

		TEST_METHOD(find)
		{
			RBTree Tree;
			char expected = 'H';

			Tree.insert(6, 'G');
			Tree.insert(7, 'F');
			Tree.insert(8, 'H');

			Assert::AreEqual(expected, Tree.find(8));
		}

		TEST_METHOD(find_exception1)
		{
			RBTree Tree;
			bool b = 0;
			try
			{
				Tree.find(1);
				Assert::IsTrue(0);
			}
			catch (exception& runtime_error)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}

		TEST_METHOD(find_exception2)
		{
			RBTree Tree;
			bool b = 0;
			Tree.insert(1, 'A');
			try
			{
				Tree.find(0);
				Assert::IsTrue(0);
			}
			catch (exception& runtime_error)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}

		TEST_METHOD(get_keys_exception)
		{
			RBTree Tree;
			bool b = 0;
			try
			{
				Tree.get_keys();
				Assert::IsTrue(0);
			}
			catch (exception& runtime_error)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}

		TEST_METHOD(get_values_exception)
		{
			RBTree Tree;
			bool b = 0;
			try
			{
				Tree.get_values();
				Assert::IsTrue(0);
			}
			catch (exception& runtime_error)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}

		TEST_METHOD(print_exception)
		{
			RBTree Tree;
			bool b = 0;
			try
			{
				Tree.print();
				Assert::IsTrue(0);
			}
			catch (exception& runtime_error)
			{
				b = 1;
			}
			Assert::IsTrue(b);
		}
	};
}
