#pragma once
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
#include "Klass.h"
#include "PeopleHandler.h"
using namespace std;

class KlassHandler {
private:
	int nrOf; // Number of Klass objects
	const int CAP = 11; // Capacity of the Klass array
	Klass** KlassArrayHere;
	PeopleHandler peopleHandler;

	void save();

	// aaaaaaaaa
	void load();

public:


	// --------------------------------------------------------------------------------------------




	int getIndexOfKlassFromSubject(string subject) const;


	void printKlass(string subject) const;

	void printAllKlasses() const;

	float getAverageAgeInKlass(Klass* KlassHere) const;

	int getTotalAgeInKlass(Klass* KlassHere) const;

	int getTeacherAgeFromID(const int teacherID) const;

	int getStaffAgeFromID(const int staffID) const;

	int getStudentAge(const int studentID) const;

	int getSumStudentAgesInKlass(Klass* KlassHere) const;
				


	int getSumPeopleTotalInKlass(string subject) const;



	string getTeacherName(const int& teacherID) const;
	string getStudentName(const int& studentID) const;
	string getStaffName(const int& staffID) const;

	const string getAllStudentsNamesInKlass(string subject) const;



	string findWhatKlassStudentIsInFromID(const int studentID) const;
	string findWhatKlassTeacherIsInFromID(const int teacherID) const;
	string findWhatKlassStaffIsInFromID(const int staffID) const;
	//-- Same as above but with names instead of ID's
	string findWhatKlassStudentIsInFromName(const string studentName) const;
	string findWhatKlassTeacherIsInFromName(const string teacherName) const;
	string findWhatKlassStaffIsInFromName(const string staffName) const;

	string findWhatKlassPersonIsInFromID(const int personID, const string personType) const;
	string findWhatKlassPersonIsFromName(const string personName, const string personType) const;
	string findWhatKlassPersonIsFromNameOrID(const string personNameOrID, const string personType) const;
	string findWHatKlassPersonIsFromNameOrIDWithoutPersonType(const string personNameOrID) const;

	// --------------------------------------------------------------------------------------------

	void addKlassJustRoomCodeAndSubject();

	void addFullKlass();
	

	void removeKlass();

	void updateKlass();

	void endlinesFancy();

	void addPersonToKlass(string personType);

	void removePersonFromKlass(string personType, string KlassSubject);

	Klass* getKlassFromSubject(string subject);

	void printAllSubjects();

	// =================================================================================================

	void handleKlasses();

	/// Above fixed YES ---------------------------------- DONE
};