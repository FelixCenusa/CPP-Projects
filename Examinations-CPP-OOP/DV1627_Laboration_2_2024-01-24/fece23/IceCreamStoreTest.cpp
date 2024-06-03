#include "IceCreamStore.h"
#include "IceCream.h"
#include <iostream>
using namespace std; 

// used for testing
const int NR_OF = 4;
const string iceCreamNames[NR_OF]{ "Magnum mandel", "Nogger", "Igloo", "Solero"};
const float iceCreamPrices[NR_OF]{ 25.5f, 23.5f, 27.f, 22.5f };

void prepareIceCreamStoreObject(IceCreamStore& iceCreamStore)
{
	for (int i = 0; i < NR_OF; i++)
	{
		iceCreamStore.addIceCream(iceCreamNames[i], iceCreamPrices[i]);
	}
}

bool testingBasics()
{
	cout << "Testing basics" << endl;
	IceCreamStore aStore("Best store");

	if (aStore.getStoreName() != "Best store")
	{
		cout << "NOT CORRECT 1: Store name is not correct, expected Best store" << endl;
		return false;
	}
	if (aStore.getCurrentNrOfCandies() != 0)
	{
		cout << "NOT CORRECT 2: Amount of iceCreams, expected 0" << endl;
		return false;
	}
	cout << "OK: Testing basics" << endl;
	return true;
}

bool testingAddIceCream()
{
	cout<<endl <<"Testing add iceCream"<<endl;
	IceCreamStore aStore;

	prepareIceCreamStoreObject(aStore);
	
	if (aStore.getCurrentNrOfCandies() != NR_OF)
	{
		cout << "NOT CORRECT 1: Amount of iceCreams, expected 3" << endl;
		return false;
	}
	for (int i = 0; i < aStore.getCurrentNrOfCandies(); i++)
	{
		if (aStore.iceCreamAt(i)->getName() != iceCreamNames[i])
		{
			cout << "NOT CORRECT 2: Not correct name returned " << endl;
			return false;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		if (!aStore.addIceCream("??", 66.6f))
		{
			cout << "NOT CORRECT 3: Expected true when adding up to 10 iceCreams" << endl;
			return false;
		}
	}
	if (aStore.addIceCream("no iceCream", 77.7f))
	{
		cout << "NOT CORRECT 4: Expected false when trying to add 11:th iceCream" << endl;
		return false;
	}
	if (!aStore.addIceCream("no iceCream", 77.7f) && aStore.getCurrentNrOfCandies() != 10)
	{
		cout << "NOT CORRECT 5: When trying to add 11:th iceCream, expected nr of iceCreams 10" << endl;
		return false;
	}

	cout << "OK: Testing add IceCream" << endl;
	return true;
}


bool testingRemoveIceCream()
{
	cout <<endl << "Testing remove IceCream" << endl;
	{
		// creating a new IceCreamStore-object
		IceCreamStore aStore;

		prepareIceCreamStoreObject(aStore);
		int nrOf = aStore.getCurrentNrOfCandies();

		bool ok = aStore.removeIceCream(iceCreamNames[0], iceCreamPrices[0]);
		if (!ok)
		{
			cout << "NOT CORRECT 1: When removing IceCream at index 0, expecting return true" << endl;
			return false;
		}
		if (ok && aStore.getCurrentNrOfCandies() != nrOf - 1)
		{
			cout << "NOT CORRECT 2: When removing IceCream at index 0, expecting nr of iceCreams 2"<< endl;
			return false;
		}
	}
	{
		// creating a new IceCreamStore-object
		IceCreamStore aStore;
		
		prepareIceCreamStoreObject(aStore);
		
		int nrOf = aStore.getCurrentNrOfCandies();
		bool ok = aStore.removeIceCream(iceCreamNames[NR_OF - 1], iceCreamPrices[NR_OF - 1]);
		if (!ok)
		{
			cout << "NOT CORRECT 3: When removing IceCream at last index, expecting return true" << endl;
			return false;
		}
		if (ok && aStore.getCurrentNrOfCandies() != nrOf - 1)
		{
			cout << "NOT CORRECT 4: When removing IceCream at last index, expecting nr of iceCreams 2" << endl;
			return false;
		}
	}

	{
		// creating a new IceCreamStore-object
		IceCreamStore aStore;

		prepareIceCreamStoreObject(aStore);
		int nrOf = aStore.getCurrentNrOfCandies();
		bool ok = aStore.removeIceCream(iceCreamNames[1], iceCreamPrices[1]);
		if (!ok)
		{
			cout << "NOT CORRECT 5: When removing IceCream in middle, expecting return true" << endl;
			return false;
		}
		if (ok && aStore.getCurrentNrOfCandies() != nrOf - 1)
		{
			cout << "NOT CORRECT 6: When removing IceCream at last index, expecting nr of iceCreams 2" << endl;
			return false;
		}
	}

	{
		// creating a new IceCreamStore-object
		IceCreamStore aStore;

		aStore.addIceCream("Solero", 15.f);
		bool ok = aStore.removeIceCream("Solero", 15.f);
		if (!ok)
		{
			cout << "NOT CORRECT 7: When removing the last IceCream in the IceCream store, expecting return true" << endl;
			return false;
		}
		if (ok && aStore.getCurrentNrOfCandies() != 0)
		{
			cout << "NOT CORRECT 8: When removing the last IceCream in the IceCream store, expecting nr of iceCreams 0" << endl;
			return false;
		}
	}

	{
		// creating a new IceCreamStore-object
		IceCreamStore aStore;

		prepareIceCreamStoreObject(aStore);
		int nrOf = aStore.getCurrentNrOfCandies();
		bool ok = true;

		for (int i = 0; i < nrOf; i++)
		{
			ok = ok && aStore.removeIceCream(iceCreamNames[i], iceCreamPrices[i]);
		}

		if (!ok)
		{
			cout << "NOT CORRECT 9: When removing IceCream in middle, expecting return true" << endl;
			return false;
		}
	}

	cout << "OK: Testing remove IceCream" << endl;
	return true;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	bool ok = true;
	ok = testingBasics();
	if (!ok)
	{
		cout << "NOT OK : testingBasics" << endl;
		return 1;
	}

	ok = testingAddIceCream();
	if (!ok)
	{
		cout << "NOT OK : testingAddIceCream" << endl;
		return 2;
	}
	
	ok = testingRemoveIceCream();
	if (!ok)
	{
		cout << "NOT OK : testingRemoveIceCream" << endl;
		return 3;
	}
	
	return 0;
}