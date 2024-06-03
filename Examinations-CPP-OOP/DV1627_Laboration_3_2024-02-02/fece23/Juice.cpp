#include "Juice.h"

Juice::Juice(int price, float litres, string fruit) : Product(price)
{
	this->litres = litres;
	this->fruit = fruit;

}

Juice::~Juice()
{
}

string Juice::toString() const
{
	return  "Juice:  Liters: " + Product::toString() + to_string(litres) + " Fruit type: " + fruit + "\n";
}

float Juice::getLiters()
{
	return litres;
}
