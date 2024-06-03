#pragma once
#include <string>
using namespace std;
class IceCream
{
public:
	IceCream(string name = "NoName", float price = 0.f);
	~IceCream();

	void setName(string name);
	void setPrice(float price);
	string getName();
	string toString(); // include name and price

	bool operator <(const IceCream& other); // const? JUST PRICE this->price == other.price
	bool operator ==(const IceCream& other); // const? PRICE AND NAME &&


private:
	string name;
	float price;
};