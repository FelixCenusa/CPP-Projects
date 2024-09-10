#include "Student.h"

Student::Student(int studentID, string stdName, int stdAge, string stdStudyField)
    : Person(stdName, stdAge, studentID), studyField(stdStudyField) {}

void Student::setStudyField(string field) {
    studyField = field;
}

string Student::getStudyField() const {
    return studyField;
}

void Student::displayPerson() const {
    std::cout << "Student" << std::endl;
    std::cout << "Student ID: " << getID() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Age: " << getAge() << std::endl;
    std::cout << "Study Field: " << studyField << std::endl;
}

void Student::readDataFromStream(istream& is) {
    string name = Person::getName();
    int age = Person::getAge();
    int studentID = Person::getID();
    is >> studentID >> name >> age >> studyField;
}

void Student::writeDataToStream(ostream& os) const {
    string name = Person::getName();
    int age = Person::getAge();
    int studentID = Person::getID();
    os << "S " << studentID << " " << getName() << " " << getAge() << " " << studyField;
}

string Student::getType() const {
    return "Student";
}

void Student::updatePerson() {
    cout << "\t\tEnter New Study Field: ";
    cin.ignore();
    getline(cin, studyField);
}
