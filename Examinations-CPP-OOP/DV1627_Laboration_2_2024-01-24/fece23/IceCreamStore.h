#pragma once
#include <string>
#include "IceCream.h"
using namespace std;
//const int CAP = 10;
class IceCreamStore
{
public:
	IceCreamStore(string storeName = "NoStoreName");
	~IceCreamStore();

	string getStoreName();
	int getCurrentNrOfCandies(); //Fel namn but ok
	bool addIceCream(string name, float price); // call default
	bool removeIceCream(string name, float price); // swap with last delete

	IceCream* iceCreamAt(int index);

private:
	string storeName;
	int currentNrOfIceCreams; // nrof
	//Where is CAP??? CAn I make it const int cap = 10?
	int CAP = 10;
	IceCream* iceCreams;
};