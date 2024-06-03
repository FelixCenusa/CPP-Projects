#include "Shop.h"

Shop::Shop(int cap)
{
	this->cap = cap;
	this->nrOf = 0;
	this->products = new Product * [cap] {nullptr};

}

Shop::~Shop()
{
	deleteMem();
}

int Shop::getNrOfProducts()
{
	return nrOf;
}

void Shop::addEgg(int price, int nrOfEggsInPackage)
{
	if (nrOf == cap)
	{
		expand();
	}
	products[nrOf] = new Egg(price, nrOfEggsInPackage);
	nrOf++;
}

void Shop::addJuice(int price, float liters, string fruit)
{
	if (nrOf == cap)
	{
		expand();
	}
	products[nrOf] = new Juice(price, liters, fruit);
	nrOf++;
}

int Shop::totalNrOfEggs()
{
	int theEggs = 0;
	for (int i = 0; i < nrOf; i++)
	{
		Egg* EggCast = dynamic_cast<Egg*>(products[i]);
		if (EggCast != nullptr)
		{
			theEggs+= EggCast->getNrOfEggsInPackage();
		}
	}
	return theEggs;
}

float Shop::totalLitresOfJuice()
{
	float totalLitres = 0.f;
	for (int i = 0; i < nrOf; i++)
	{
		Juice* JuiceCast = dynamic_cast<Juice*>(products[i]);
		if (JuiceCast != nullptr)
		{
			totalLitres += JuiceCast->getLiters();
		}
	}
	return totalLitres;
}

void Shop::showAllProducts()
{
	for (int i = 0; i < nrOf; i++)
	{
		cout << products[i]->toString() << endl;
	}
}




Shop::Shop(const Shop& other)
{
	this->nrOf = other.nrOf;
	this->cap = other.cap;
	this->products = new Product * [cap] {nullptr};
	for (int i = 0; i < nrOf; i++)
	{
		Juice* JuiceCast = dynamic_cast<Juice*>(other.products[i]);
		if (JuiceCast != nullptr)
		{
			this->products[i] = new Juice(*JuiceCast);
		}
		Egg* EggCast = dynamic_cast<Egg*>(other.products[i]);
		if (EggCast != nullptr)
		{
			this->products[i] = new Egg(*EggCast);
		}
	}
}

void Shop::operator=(const Shop& other) //deletes
{
	if (this != &other)
	{
		this->deleteMem();
		this->nrOf = other.nrOf;
		this->cap = other.cap;
		this->products = new Product * [cap] {nullptr};
		for (int i = 0; i < nrOf; i++)
		{
			Juice* JuiceCast = dynamic_cast<Juice*>(other.products[i]);
			if (JuiceCast != nullptr)
			{
				this->products[i] = new Juice(*JuiceCast);
			}
			Egg* EggCast = dynamic_cast<Egg*>(other.products[i]);
			if (EggCast != nullptr)
			{
				this->products[i] = new Egg(*EggCast);
			}
		}

	}
}




Product** Shop::getAccessToArray()
{
	return products;
}

Product* Shop::getAccessToProductAt(int index)
{
	if (index > cap)
	{
		return nullptr;
	}
	return *products;
}

void Shop::deleteMem()
{
	for (int i = 0; i < nrOf; i++)
	{
		delete products[i];
	}
	delete[] products;
}

void Shop::expand()
{
	cap++;
	Product** tempArray;
	tempArray = new Product * [cap] {nullptr};
	for (int i = 0; i < nrOf; i++)
	{
		tempArray[i] = products[i];
	}
	delete[] products;
	products = tempArray;
}
