#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <string>
#include <vector>
#include <memory>
using namespace std;

#include "person.h"
#include "Teacher.h"
#include "staff.h"
#include "student.h"
#include "Klass.h"

class PeopleHandler {
private:
    vector<unique_ptr<Person>> people; // Vector here

    void writeToTextFile(const string& filename);

    void readFromTextFile(const string& filename);

public:
    PeopleHandler();

    ~PeopleHandler() = default;

    void addNewStudent();

    void addNewTeacher();

    void addNewStaff();

    void displayAllPeople() const;

    void printAllExistingPeopleOfType(string type) const;

    void searchPerson() const;

    void updatePerson();

    void deletePerson();

    int countPeopleOfType(const string& type) const;

    int ageOfPeopleOfType(const string& type) const;

    int getAgeFromID(int id) const;

    string getNameFromID(int id) const;

    string getTypeNameFromID(int id, string type) const;


    int getIDFromName(string name) const;

    int getTypeIDFromName(string name, string type) const;




    int totalAgeStudents() const;

    int totalAgeTeachers() const;

    int totalAgeStaff() const;

    int totalAgeTotalPeople() const;

    float averageAgeOfPeople() const;


    int countStudents() const;

    int countTeachers() const;

    int countStaff() const;

    int countTotalPeople() const;

    bool handlePeople();

    Teacher* getTeacherFromID(int id);
    Student* getStudentFromID(int id);
    Staff* getStaffFromID(int id);
};
