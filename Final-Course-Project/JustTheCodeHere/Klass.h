#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <string>
#include <vector>
#include <memory>

#include "person.h"
#include "Teacher.h"
#include "staff.h"
#include "student.h"
#include "PeopleHandler.h"

using namespace std;

class Klass {
private:
    string roomCode;
    string subject;
    Student* students[50];
    Teacher* teacher;
    Staff* staff;
    int nrOf;//nrof students

public:
    // Default Constructor
    Klass();

    // Constructor
    Klass(const string& roomCode, const string& subject);

    // Constructor

    Klass(const string& roomCode, const string& subject, Teacher* teacher, Staff* staff, Student* studentsH[], int nrOf);

    bool checkIfStudentExistsInKlass(Student* students);


    // Getters and Setters
    const string& getRoomCode() const;
    void setRoomCode(const string& roomCode);
    const string& getSubject() const;
    void setSubject(const string& subject);
    Teacher* getTeacher() const;
    void setTeacher(Teacher* teacher);
    Staff* getStaff() const;
    void setStaff(Staff* staff);
    //get nrof and removers
    const int getNrOfStudents() const;
    void removeTeacher();
    void removeStaff();
    void removeStudent(Student* students);



    Student* getLastStudent() const;
    void setStudentLast(Student* students);
    Student* getStudentAtIndex(int index) const;
    Student* getAllStudents() const;





    void printKlass();
};
