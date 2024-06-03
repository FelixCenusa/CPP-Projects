#include "Product.h"

Product::Product(int price)
{
	this->price = price;

}

Product::~Product()
{
}

string Product::toString() const
{
	return "Product:  Price:" + to_string(price) + " ";

}
