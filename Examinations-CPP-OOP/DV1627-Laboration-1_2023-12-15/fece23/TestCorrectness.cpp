#include "catch_amalgamated.hpp"
#include "ToDo.h"

using namespace std;

TEST_CASE("Testing: exchange")
{
	int nrOne = 11;
	int nrTwo = 22;
	exchange(nrOne, nrTwo);
	REQUIRE(nrOne == 22);
	REQUIRE(nrTwo == 11);
}

TEST_CASE("Testing: readStringsFromFile")
{
	SECTION("Read 3 strings from file containing 3 strings")
	{
		const int cap = 3;
		string strs[cap];
		bool ok = readStringsFromFile("threeStrings.txt", strs, cap);
		REQUIRE(ok);
		REQUIRE(strs[0] == "line one");
		REQUIRE(strs[1] == "line two");
		REQUIRE(strs[2] == "line three");
	}
	SECTION("Read 5 strings from file containing 10 strings")
	{
		const int cap = 10;
		string strs[cap];
		bool ok = readStringsFromFile("tenStrings.txt", strs);
		REQUIRE(ok);
		REQUIRE(strs[0] == "one");
		REQUIRE(strs[1] == "two");
		REQUIRE(strs[2] == "three");
		REQUIRE(strs[3] == "four");
		REQUIRE(strs[4] == "five");
		for (int i = 5; i < cap; i++)
		{
			REQUIRE(strs[i] == "");
		}
	}
	SECTION("Try to read from a file that does not exits")
	{
		const int cap = 3;
		string strs[cap];
		bool ok = readStringsFromFile("test.txt", strs, cap);
		REQUIRE(!ok);
		REQUIRE(strs[0] == "");
		REQUIRE(strs[1] == "");
		REQUIRE(strs[2] == "");
	}
}

TEST_CASE("Testing: findBiggest")
{
	SECTION("Array with 1 integer")
	{
		const int cap = 1;
		int arr[cap]{11};
		int index = findBiggest(arr, cap);
		REQUIRE(index == 0);
	}
	SECTION("Array with 3 integers and biggest value first")
	{
		const int cap = 3;
		int arr[cap]{ 11, 5, 8 };
		int index = findBiggest(arr, cap);
		REQUIRE(index == 0);
	}
	SECTION("Array with 3 integers and biggest value last")
	{
		const int cap = 3;
		int arr[cap]{ 11, 5, 88 };
		int index = findBiggest(arr, cap);
		REQUIRE(index == 2);
	}
	SECTION("Array with 3 integers and biggest value in middle")
	{
		const int cap = 3;
		int arr[cap]{ 11, 55, 8 };
		int index = findBiggest(arr, cap);
		REQUIRE(index == 1);
	}
	SECTION("Array with 5 integers and biggest value more than one occurence")
	{
		const int cap = 5;
		int arr[cap]{ 11, 88, 88, 66, 88 };
		int index = findBiggest(arr, cap);
		REQUIRE(index == 1);
	}
	
}

