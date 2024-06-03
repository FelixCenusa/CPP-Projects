#pragma once
#include <string>
#include <iostream>
#include "Juice.h"
#include "Egg.h"
using namespace std;
class Shop
{
public:
	Shop(int cap = 1);
	~Shop();

	int getNrOfProducts();
	void addEgg(int price, int nrOfEggsInPackage);
	void addJuice(int price, float liters, string fruit);
	int totalNrOfEggs();
	float totalLitresOfJuice();
	void showAllProducts();

	Shop(const Shop& other);
	void operator=(const Shop& other);

	Product** getAccessToArray();
	Product* getAccessToProductAt(int index);



private:
	void deleteMem();
	void expand();
	int nrOf;
	int cap;
	Product** products;
};