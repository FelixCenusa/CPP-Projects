#include "Klass.h"


Klass::Klass() {
	roomCode = "A0";
	subject = "Unknown";
	teacher = nullptr;
	staff = nullptr;
	nrOf = 0;
	for (int i = 0; i < 50; i++)
	{
		students[i] = nullptr;
	}
};

Klass::Klass(const string& roomCode, const string& subject) {
	this->roomCode = roomCode;
	this->subject = subject;
	teacher = nullptr;
	staff = nullptr;
	nrOf = 0;
	for (int i = 0; i < 50; i++)
	{
		students[i] = nullptr;
	}
};

Klass::Klass(const string& roomCode, const string& subject, Teacher* teacher, Staff* staff, Student* studentsH[], int nrOf) {
	this->roomCode = roomCode;
	this->subject = subject;
	this->teacher = teacher;
	this->staff = staff;
	this->nrOf = nrOf;
	for (int i = 0; i < nrOf; i++)
	{
		this->students[i] = studentsH[i];
		cout << this->students[i]->getName() << endl;
	}

};

bool Klass::checkIfStudentExistsInKlass(Student* students) {
	for (int i = 0; i < nrOf; i++)
	{
		if (this->students[i] == students)
		{
			return true;
		}
	}
	return false;
};

const string& Klass::getRoomCode() const {
	return roomCode;
};

void Klass::setRoomCode(const string& roomCode) {
	this->roomCode = roomCode;
};

const string& Klass::getSubject() const {
	return subject;
};

void Klass::setSubject(const string& subject) {
	this->subject = subject;
};

Teacher* Klass::getTeacher() const {
	return teacher;
};

void Klass::setTeacher(Teacher* teacher) {
	this->teacher = teacher;
};

Staff* Klass::getStaff() const {
	return staff;
};

void Klass::setStaff(Staff* staff) {
	this->staff = staff;
};

const int Klass::getNrOfStudents() const {
	return nrOf;
};

void Klass::removeTeacher() {
	teacher = nullptr;
};

void Klass::removeStaff() {
	staff = nullptr;
};

void Klass::removeStudent(Student* students) {
	for (int i = 0; i < nrOf; i++)
	{
		if (this->students[i] == students)
		{
			this->students[i] = nullptr;
		}
	}
};

Student* Klass::getLastStudent() const {
	return students[nrOf];
};

void Klass::setStudentLast(Student* students) {
	this->students[nrOf] = students;
	nrOf++;
};

Student* Klass::getStudentAtIndex(int index) const {
	return students[index];
};

Student* Klass::getAllStudents() const {
	return *students;
};

void Klass::printKlass() {
	cout << "Room Code: " << roomCode << endl;
	cout << "Subject: " << subject << endl;
	bool atLeastOneStudent = false;
	if (teacher != nullptr)
	{
		cout << "Teacher: " << teacher->getName() << endl;
	}
	else
	{
		cout << "Teacher: No teacher assigned" << endl;
	}
	if (staff != nullptr)
	{
		cout << "Staff: " << staff->getName() << endl;
	}
	else
	{
		cout << "Staff: No staff assigned" << endl;
	}
	cout << "Students: " << endl;
	for (int i = 0; i < nrOf; i++)
	{
		if (students[i] != nullptr)
		{
			cout << students[i]->getName() << endl;
			atLeastOneStudent = true;

		}
	}
	if (!atLeastOneStudent)
	{
		cout << "No students attend this class :(" << endl;
	}
};
