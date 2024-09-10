#include "Staff.h"

Staff::Staff(int staffID, string sName, int sAge, string sRole)
    : Person(sName, sAge, staffID), role(sRole) {}

void Staff::displayPerson() const {
    std::cout << "Staff" << std::endl;
    std::cout << "Staff ID: " << Person::getID() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Age: " << getAge() << std::endl;
    std::cout << "Role: " << role << std::endl;
}

void Staff::readDataFromStream(istream& is) {
    string name = Person::getName();
    int age = Person::getAge();
    int staffID = Person::getID();

    is >> staffID >> name >> age >> role;
}

void Staff::writeDataToStream(ostream& os) const {
    string name = Person::getName();
    int age = Person::getAge();
    int staffID = Person::getID();
    os << "F " << staffID << " " << name << " " << age << " " << role;
}

string Staff::getType() const {
    return "Staff";
}

string Staff::getRole() const {
    return role;
}

void Staff::setRole(string& newRole) {
    role = newRole;
}

void Staff::updatePerson() {
    cout << "\t\tEnter New Role  : ";
    cin.ignore();
    getline(cin, role);
}
