#include "IceCream.h"

IceCream::IceCream(string name, float price)
{
	this->name = name;
	this->price = price;

}

IceCream::~IceCream()
{
}

void IceCream::setName(string name)
{
	this->name = name;

}

void IceCream::setPrice(float price)
{
	this->price = price;

}

string IceCream::getName()
{
	return name;
}


string IceCream::toString()
{
	return "Name: " + name + " Price: " + to_string(price) + "\n";
}

bool IceCream::operator<(const IceCream& other)
{
	return this->price < other.price;
}

bool IceCream::operator==(const IceCream& other)
{
	return this->price == other.price && this->name == other.name;
}
