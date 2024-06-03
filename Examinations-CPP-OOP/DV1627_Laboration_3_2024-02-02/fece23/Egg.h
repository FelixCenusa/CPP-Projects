#pragma once
#include <string>
#include <iostream>
#include "Product.h"
using namespace std;
class Egg : public Product
{
public:
	Egg(int price, int nrOfEggsInPackage);
	virtual ~Egg();

	string toString() const override; // Egg:      and rest
	int getNrOfEggsInPackage();

private:
	int nrOfEggsInPackage;
};