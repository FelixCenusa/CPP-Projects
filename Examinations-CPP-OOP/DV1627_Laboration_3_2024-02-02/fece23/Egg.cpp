#include "Egg.h"

Egg::Egg(int price, int nrOfEggsInPackage) : Product(price)
{
	this->nrOfEggsInPackage = nrOfEggsInPackage;
}

Egg::~Egg()
{
}

string Egg::toString() const
{
	return  "Egg:  Eggs in package: " + Product::toString() + to_string(nrOfEggsInPackage) + "\n";

}

int Egg::getNrOfEggsInPackage()
{
	return nrOfEggsInPackage;
}
