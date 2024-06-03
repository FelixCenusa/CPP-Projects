#pragma once
#include <string>
#include <iostream>
#include "Product.h"
using namespace std;
class Juice : public Product
{
public:
	Juice(int price, float litres, string fruit);
	virtual ~Juice();

	string toString() const override; // Juice:      and rest

	float getLiters();


private:
	float litres;
	string fruit;
};