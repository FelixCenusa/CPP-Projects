#include <iostream>
#include <string>
#include "Product.h"
#include "Juice.h"
#include "Egg.h"
#include "Shop.h"

using namespace std;
bool testOfPoductsDesciption()
{
	cout << "Test toString of products" << endl;

	Egg anEgg(43, 12);
	Juice aJuice(23, 0.75f, "orange");

	string descr = anEgg.toString();
	if (descr.find("Egg") != 0 && descr.find("egg") != 0)
	{
		cout << "NOT CORRECT: expected Egg at beginning of toString" << endl;
		return false;
	}
	if (descr.find("43") == string::npos)
	{
		cout << "NOT CORRECT: expected 43 in toString" << endl;
		return false;
	}
	if (descr.find("12") == string::npos)
	{
		cout << "NOT CORRECT: expected 12 in toString" << endl;
		return false;
	}
	descr = aJuice.toString();
	if (descr.find("Juice") != 0 && descr.find("juice") != 0)
	{
		cout << "NOT CORRECT: expected Juice at beginning of toString" << endl;
		return false;
	}
	if (descr.find("23") == string::npos)
	{
		cout << "NOT CORRECT: expected 23 in toString" << endl;
		return false;
	}
	if (descr.find("0.7") == string::npos)
	{
		cout << "NOT CORRECT: expected 0.7 in toString" << endl;
		return false;
	}
	if (descr.find("orange") == string::npos)
	{
		cout << "NOT CORRECT: expected orange in toString" << endl;
		return false;
	}
	cout << "OK: Test toString of products" << endl << endl;
	return true;
}
bool testAddingProducts()
{
	cout << "Test adding products" << endl;
	Shop aShop(2);

	if (aShop.getNrOfProducts() != 0)
	{
		cout << "NOT CORRECT 1: expected 0 but got " << aShop.getNrOfProducts() << endl;
		return false;
	}

	aShop.addJuice(23, 0.75f, "orange");
	if (aShop.getNrOfProducts() != 1)
	{
		cout << "NOT CORRECT 2: expected 1 but got " << aShop.getNrOfProducts() << endl;
		return false;
	}

	aShop.addEgg(43, 12);
	if (aShop.getNrOfProducts() != 2)
	{
		cout << "NOT CORRECT 3: expected 2 but got " << aShop.getNrOfProducts() << endl;
		return false;
	}

	aShop.addEgg(25, 6);
	if (aShop.getNrOfProducts() != 3)
	{
		cout << "NOT CORRECT 4: expected 3 but got " << aShop.getNrOfProducts() << endl;
		return false;
	}
	cout << "OK Test adding products" << endl<<endl;
	return true;
}
bool testTotalNrOfEggs()
{
	cout << "Test total number of eggs" << endl;
	Shop aShop(7);

	aShop.addJuice(23, 0.75f, "orange");
	aShop.addEgg(45, 12);
	aShop.addEgg(22, 6);
	aShop.addJuice(34, 1.5f, "apple");
	aShop.addEgg(98, 36);
	aShop.addJuice(30, 1.5f, "peach");

	if (aShop.totalNrOfEggs() != 54)
	{
		cout << "NOT CORRECT 1: expected 54 but got " << aShop.totalNrOfEggs() << endl;
		return false;
	}
	cout << "OK Test number of eggs" << endl << endl;
	return true;
}
bool testTotalLitresOfJuice()
{
	cout << "Test total litres of juice" << endl;
	Shop aShop(7);

	aShop.addJuice(23, 0.75f, "orange");
	aShop.addEgg(45, 12);
	aShop.addEgg(22, 6);
	aShop.addJuice(34, 1.5f, "apple");
	aShop.addEgg(98, 36);
	aShop.addJuice(30, 1.5f, "peach");

	// should be 3.75, check intervall 3.74 - 3.76
	if (aShop.totalLitresOfJuice() <= 3.74 || aShop.totalLitresOfJuice() >= 3.76)
	{
		cout << "NOT CORRECT 1: expected 3.75 but got " << aShop.totalLitresOfJuice() << endl;
		return false;
	}

	cout << "OK Test total litres of juice" << endl << endl;
	return true;
}
bool testingCopyConstructor()
{
	cout << "Test copy constructor" << endl;
	{
		Shop aShop;
		Shop bShop = aShop;
		if (bShop.getNrOfProducts() != 0)
		{
			cout << "NOT CORRECT 1: expected 0 but got " <<bShop.getNrOfProducts() << endl;
			return false;

		}
		if (aShop.getAccessToArray() == bShop.getAccessToArray())
		{
			cout << "NOT CORRECT 2: expected different adresses but got same adress " << endl;
			return false;
		}
	}
	{
		Shop aShop;
		aShop.addJuice(23, 0.75f, "orange");
		Shop bShop = aShop;
		
		if (bShop.getNrOfProducts() != 1)
		{
			cout << "NOT CORRECT 3: expected 1 but got " << bShop.getNrOfProducts()<< endl;
			return false;

		}
		if (aShop.getAccessToArray() == bShop.getAccessToArray())
		{
			cout << "NOT CORRECT 4: expected different adresses but got same adress " << endl;
			return false;
		}
		if (aShop.getAccessToProductAt(0) == bShop.getAccessToProductAt(0))
		{
			cout << "NOT CORRECT 5: expected different adresses but got same adress " << endl;
			return false;
		}
	}
	{
		Shop aShop(7);
		aShop.addJuice(23, 0.75f, "orange");
		aShop.addEgg(54, 24);
		
		Shop bShop = aShop;

		if (bShop.getNrOfProducts() != 2)
		{
			cout << "NOT CORRECT 6: expected 2 but got " << bShop.getNrOfProducts() << endl;
			return false;

		}
		if (aShop.getAccessToArray() == bShop.getAccessToArray())
		{
			cout << "NOT CORRECT 7: expected different adresses but got same adress " << endl;
			return false;
		}
		
		if (aShop.getAccessToProductAt(0) == bShop.getAccessToProductAt(0) || 
			aShop.getAccessToProductAt(0) == bShop.getAccessToProductAt(1) || 
			aShop.getAccessToProductAt(1) == bShop.getAccessToProductAt(1) || 
			aShop.getAccessToProductAt(1) == bShop.getAccessToProductAt(0))
		{
			cout << "NOT CORRECT 8: expected different adresses but got same adress " << endl;
			return false;
		}

		if (aShop.getAccessToProductAt(0)->toString() != bShop.getAccessToProductAt(0)->toString() ||
			aShop.getAccessToProductAt(1)->toString() != bShop.getAccessToProductAt(1)->toString())
		{
			cout << "NOT CORRECT 9: expected same toString but got different " << endl;
			return false;
		}
	}
	cout << "OK Test copy constructor" << endl<<endl;
	return true;
}

bool testingAssignmentOperator()
{
	cout << "Test assignment operator" << endl;
	{
		Shop aShop;
		Shop bShop;
		
		bShop = aShop;
		if (bShop.getNrOfProducts() != 0)
		{
			cout << "NOT CORRECT 1: expected 0 but got " << bShop.getNrOfProducts() << endl;
			return false;

		}
		if (aShop.getAccessToArray() == bShop.getAccessToArray())
		{
			cout << "NOT CORRECT 2: expected different adresses but got same adress " << endl;
			return false;
		}
	}
	{
		Shop aShop;
		aShop.addJuice(23, 0.75f, "orange");
		Shop bShop;
		bShop = aShop;

		if (bShop.getNrOfProducts() != 1)
		{
			cout << "NOT CORRECT 3: expected 1 but got " << bShop.getNrOfProducts() << endl;
			return false;

		}
		if (aShop.getAccessToArray() == bShop.getAccessToArray())
		{
			cout << "NOT CORRECT 4: expected different adresses but got same adress " << endl;
			return false;
		}
		if (aShop.getAccessToProductAt(0) == bShop.getAccessToProductAt(0))
		{
			cout << "NOT CORRECT 5: expected different adresses but got same adress " << endl;
			return false;
		}
	}
	{
		Shop aShop(7);
		aShop.addJuice(23, 0.75f, "orange");
		aShop.addEgg(54,24);

		Shop bShop;
		bShop = aShop;

		if (bShop.getNrOfProducts() != 2)
		{
			cout << "NOT CORRECT 6: expected 2 but got " << bShop.getNrOfProducts() << endl;
			return false;

		}
		if (aShop.getAccessToArray() == bShop.getAccessToArray())
		{
			cout << "NOT CORRECT 7: expected different adresses but got same adress " << endl;
			return false;
		}

		if (aShop.getAccessToProductAt(0) == bShop.getAccessToProductAt(0) ||
			aShop.getAccessToProductAt(0) == bShop.getAccessToProductAt(1) ||
			aShop.getAccessToProductAt(1) == bShop.getAccessToProductAt(1) ||
			aShop.getAccessToProductAt(1) == bShop.getAccessToProductAt(0))
		{
			cout << "NOT CORRECT 8: expected different adresses but got same adress " << endl;
			return false;
		}

		if (aShop.getAccessToProductAt(0)->toString() != bShop.getAccessToProductAt(0)->toString() ||
			aShop.getAccessToProductAt(1)->toString() != bShop.getAccessToProductAt(1)->toString())
		{
			cout << "NOT CORRECT 9: expected same toString but got different " << endl;
			return false;
		}
	}
	{
		Shop aShop(7);
		aShop.addJuice(23, 0.75f, "orange");
		aShop.addEgg(54, 24);
		Shop bShop;

		aShop = bShop;

		if (aShop.getNrOfProducts() != 0)
		{
			cout << "NOT CORRECT 10: expected 0 but got " << bShop.getNrOfProducts() << endl;
			return false;

		}
		if (aShop.getAccessToArray() == bShop.getAccessToArray())
		{
			cout << "NOT CORRECT 11: expected different adresses but got same adress " << endl;
			return false;
		}
	}
	{
		Shop aShop(2);
		aShop.addJuice(23, 0.75f, "orange");
		aShop.addEgg(54, 24);
		Shop bShop(5);
		bShop.addEgg(22, 6);
		bShop.addJuice(34, 1.5f, "apple");
		bShop.addEgg(88, 36);
		bShop.addJuice(30, 1.5f, "peach");

		aShop = bShop;

		if (aShop.getNrOfProducts() != 4)
		{
			cout << "NOT CORRECT 12: expected 4 but got " << bShop.getNrOfProducts() << endl;
			return false;

		}
		if (aShop.getAccessToArray() == bShop.getAccessToArray())
		{
			cout << "NOT CORRECT 13: expected different adresses but got same adress " << endl;
			return false;
		}
		if (aShop.getAccessToProductAt(2)->toString() != bShop.getAccessToProductAt(2)->toString() ||
			aShop.getAccessToProductAt(3)->toString() != bShop.getAccessToProductAt(3)->toString())
		{
			cout << "NOT CORRECT 14: expected same toString but got different " << endl;
			return false;
		}
	}
	{

		Shop aShop(2);
		aShop.addJuice(23, 0.75f, "orange");
		aShop.addEgg(54, 24);
		Product** prodBeforePtr = aShop.getAccessToArray();
		aShop = aShop;
		Product** prodAfterPtr = aShop.getAccessToArray();
		if (prodBeforePtr != prodAfterPtr)
		{
			cout << "NOT CORRECT 15: expected same address to array but got different " << endl;
			return false;
		}
	}

	cout << "OK Test assignment operator" << endl;
	return true;
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	if (!testOfPoductsDesciption())
	{
		cout << "NOT OK TEST OF DESCRIOTION" << endl;
		return 1;
	}
	if (!testAddingProducts())
	{
		cout << "NOT OK TEST OF ADDING PRODUCTS" << endl;
		return 2;
	}
	if (!testTotalNrOfEggs())
	{
		cout << "NOT OK TEST OF TOTAL NUMBER OF EGGS" << endl;
		return 3;
	}
	if (!testTotalLitresOfJuice())
	{
		cout << "NOT OK TEST OF TOTAL LITRES OF JUICE" << endl;
		return 4;
	}

	if (!testingCopyConstructor())
	{
		cout << "NOT OK TEST OF COPY CONSTRUCTOR" << endl;
		return 5;
	}
	if (!testingAssignmentOperator())
	{
		cout << "NOT OK TEST OF ASSIGNMENT OPERATOR" << endl;
		return 6;
	}
	return 0;
}