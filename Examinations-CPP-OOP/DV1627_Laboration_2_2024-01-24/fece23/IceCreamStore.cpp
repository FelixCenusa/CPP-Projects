#include "IceCreamStore.h"

IceCreamStore::IceCreamStore(string storeName)
{
	//const int CAP = 10;
	this->storeName = storeName;
	this->currentNrOfIceCreams = 0;
	iceCreams = new IceCream[CAP];
}

IceCreamStore::~IceCreamStore()
{
	delete[] iceCreams;
	/*for (int i = 0; i < currentNrOfIceCreams; i++)
	{
		delete iceCreams[i]; Just for DYNAMIC
	}*/
	//delete iceCreams;
}

string IceCreamStore::getStoreName()
{
	return storeName;
}

int IceCreamStore::getCurrentNrOfCandies()
{
	return currentNrOfIceCreams;
}

bool IceCreamStore::addIceCream(string name, float price)
{
	bool worked = false;
	if (currentNrOfIceCreams < CAP)
	{
		iceCreams[currentNrOfIceCreams] = IceCream(name, price);
		currentNrOfIceCreams++;
		worked = true;
	}

	return worked;
}

bool IceCreamStore::removeIceCream(string name, float price)
{
	bool worked = false;
	IceCream Temp(name, price);
	for (int i = 0; i < currentNrOfIceCreams; i++)
	{
		if (Temp == iceCreams[i])
		{
			iceCreams[i] = iceCreams[currentNrOfIceCreams-1];
			//delete &iceCreams[currentNrOfIceCreams-1];
			currentNrOfIceCreams--;
			//delete &Temp;
			worked = true;
		}


	}

	return worked;
}

IceCream* IceCreamStore::iceCreamAt(int index)
{
	IceCream* ptr = nullptr;
	ptr = &iceCreams[index]; //without &  wtf
	return ptr;
}


















//IceCream TempIce(name, price);
//for (int i = 0; i < currentNrOfIceCreams; i++)
//{
//	if (iceCreams[i] == TempIce)
//	{
//		//delete &iceCreams[i]; // wtf why &
//		iceCreams[i] = iceCreams[currentNrOfIceCreams - 1];
//		currentNrOfIceCreams--;
//		worked = true;
//		delete& TempIce;
//		break;
//
//	}
//
//}