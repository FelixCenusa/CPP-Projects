#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person {
private:
    int age;
    string name;
    int ID;

public:
    Person() = default;

    Person(string personName, int personAge, int personID);

    void setName(string personName);

    string getName() const;

    void setAge(int personAge);

    int getAge() const;


    void setID(int personID);

    int getID() const;

    string getNameFromID(int id);

    virtual void displayPerson() const = 0;
    virtual void readDataFromStream(istream& is) = 0;

    virtual void writeDataToStream(ostream& os) const;

    virtual string getType() const = 0;
    virtual void updatePerson() = 0; 
    virtual ~Person() = default;

};

