#include "Teacher.h"

Teacher::Teacher(int teacherID, string empName, int empAge, string empTeachingSubject)
    : Person(empName, empAge, teacherID), teachingSubject(empTeachingSubject) {}

void Teacher::setTeachingSubject(string subject) {
    teachingSubject = subject;
}

string Teacher::getTeachingSubject() const {
    return teachingSubject;
}

void Teacher::displayPerson() const {
    /*string name = Person::getName();
    int age = Person::getAge();*/
    std::cout << "Teacher" << std::endl;
    std::cout << "Employee ID: " << getID() << std::endl;
    std::cout << "Name:  " << getName() << std::endl;
    std::cout << "Age: " << getAge() << std::endl;
    std::cout << "Teaching Subject: " << teachingSubject << std::endl;
}

void Teacher::readDataFromStream(istream& is) {
    string name = Person::getName();
    int age = Person::getAge();
    int teacherID = Person::getID();
    is >> teacherID >> name >> age >> teachingSubject;
}

void Teacher::writeDataToStream(ostream& os) const {
    string name = Person::getName();
    int age = Person::getAge();
    int teacherID = Person::getID();
    os << "T " << teacherID << " " << name << " " << age << " " << teachingSubject;
}

string Teacher::getType() const {
    return "Teacher";
}

void Teacher::updatePerson() {
    cout << "\t\tEnter New Teaching Subject: ";
    cin.ignore();
    getline(cin, teachingSubject);
}
