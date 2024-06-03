#include "Person.h"

Person::Person(string personName, int personAge, int personID)
	: name(personName), age(personAge), ID(personID) {}

void Person::setName(string personName) {
	this->name = personName;
}

string Person::getName() const {
	return name;
}

void Person::setAge(int personAge) {
	this->age = personAge;
}

int Person::getAge() const {
	return age;
}

void Person::setID(int personID) {
	this->ID = personID;
}

int Person::getID() const {
	return ID;
}

string Person::getNameFromID(int id) {
	if (id == ID) {
		return name;
	}
	else {
		return "ID not found";
	}
}

void Person::writeDataToStream(ostream& os) const {
	os << age << " " << name;
}