#include "pch.h"
#include "CppUnitTest.h"
#include "../Project27/Header.h" // Вкажіть правильний відносний шлях до вашого Header.h

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(LogicTests)
	{
	public:

		// Тест сортування за зростанням
		TEST_METHOD(TestAscSort)
		{
			vector<int> v = { 5, 1, 4, 2 };
			vector<int> expected = { 1, 2, 4, 5 };
			AscSort(v);

			for (size_t i = 0; i < v.size(); i++) {
				Assert::AreEqual(expected[i], v[i], L"Елементи не збігаються після AscSort");
			}
		}

		// Тест сортування за спаданням
		TEST_METHOD(TestDescSort)
		{
			vector<int> v = { 1, 2, 3 };
			vector<int> expected = { 3, 2, 1 };
			DescSort(v);

			for (size_t i = 0; i < v.size(); i++) {
				Assert::AreEqual(expected[i], v[i], L"Елементи не збігаються після DescSort");
			}
		}

		// Тест суми елементів
		TEST_METHOD(TestSumElements)
		{
			vector<int> v = { 10, 20, 30 };
			int result = SumElements(v);
			Assert::AreEqual(60, result, L"Сума розрахована неправильно");
		}

		// Тест видалення дублікатів
		TEST_METHOD(TestRemoveDuplicates)
		{
			vector<int> v = { 1, 2, 2, 3, 1 };
			vector<int> unique;
			vector<int> expected = { 1, 2, 3 };

			RemoveDuplicates(v, unique);

			Assert::AreEqual(expected.size(), unique.size(), L"Розмір вектора унікальних значень неправильний");
			for (size_t i = 0; i < unique.size(); i++) {
				Assert::AreEqual(expected[i], unique[i], L"Елементи унікального вектора не збігаються");
			}
		}

		// Тест логіки різниці сум (S3 - S2)
		TEST_METHOD(TestDifferenceLogic)
		{
			vector<int> v1 = { 1, 2, 2 }; // Сума S2 = 5
			vector<int> v2 = { 1, 2 };    // Сума S3 = 3 (унікальні)

			int s2 = SumElements(v1);
			int s3 = SumElements(v2);
			int diff = s3 - s2;

			Assert::AreEqual(-2, diff, L"Різниця сум S3 - S2 розрахована невірно");
		}
	};
}