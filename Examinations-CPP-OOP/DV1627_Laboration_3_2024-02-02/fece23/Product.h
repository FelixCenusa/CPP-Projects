#pragma once
#include <string>
#include <iostream>
using namespace std;
class Product
{
public:
	Product(int price);
	virtual ~Product();

	virtual string toString() const = 0; // = 0

private:
	int price;
};
