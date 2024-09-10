#include "KlassHandler.h"



void KlassHandler::save() {
	ofstream out("klasser.txt");
	if (out.is_open()) {
		out << nrOf << endl;
		for (int i = 0; i < nrOf; i++) {
			out << KlassArrayHere[i]->getRoomCode() << "|";
			out << KlassArrayHere[i]->getSubject() << "|";
			out << KlassArrayHere[i]->getTeacher()->getID() << "|";
			out << KlassArrayHere[i]->getStaff()->getID() << "|";
			for (int j = 0; j < KlassArrayHere[i]->getNrOfStudents(); j++)
			{
				out << KlassArrayHere[i]->getStudentAtIndex(j)->getID() << "/";
			}
			out << endl;
		}
		for (int i = 0; i < nrOf; i++)
		{
			delete KlassArrayHere[i];
		}
		delete[] KlassArrayHere;
		out.close();
	}
	else {
		cout << "Could not open file for writing" << endl;
	}
}

void KlassHandler::load() {
	KlassArrayHere = new Klass * [CAP];
	for (int i = 0; i < CAP; i++)
	{
		KlassArrayHere[i] = nullptr;

	}
	ifstream in("klasser.txt");
	if (in.is_open()) {
		in >> nrOf;
		in.ignore();
		for (int i = 0; i < nrOf; i++) {
			string roomCode;
			string subject;
			string teacherIDStr; // int
			string staffIDStr; // int
			string allStudentsID;
			string wholeLine;
			getline(in, wholeLine);
			const int size = 5;
			string lineHere[5];
			string variable;

			int index = 0;
			for (char c : wholeLine) {
				if (c == '|') {
					if (index < size) {
						lineHere[index] = variable;
						variable.clear();
						index++;
					}
					else {
						break;
					}
				}
				else {
					variable += c;
				}
			}

			if (index < size) {
				lineHere[index] = variable;
			}
			roomCode = lineHere[0];
			subject = lineHere[1];
			teacherIDStr = lineHere[2];
			long int teacherID;
			cout << endl;
			teacherID = stoi(teacherIDStr);
			staffIDStr = lineHere[3];
			long int staffID = stoi(staffIDStr);
			allStudentsID = lineHere[4];

			Teacher* teacherHere = peopleHandler.getTeacherFromID(teacherID);
			Staff* staffHere = peopleHandler.getStaffFromID(staffID);


			int numberOfStudents = 0;
			Student* allStudentsHere[50] = { nullptr };
			int j = 0;
			string temp = "";
			for (int i = 0; i < allStudentsID.size(); i++) {
				if (allStudentsID[i] == '/') {
					allStudentsHere[j] = peopleHandler.getStudentFromID(stoi(temp));
					numberOfStudents++;
					temp = "";
					j++;
				}
				else {
					temp += allStudentsID[i];
				}
			}


			KlassArrayHere[i] = new Klass(roomCode, subject, teacherHere, staffHere, allStudentsHere, numberOfStudents);
			for (int c = 0; c < numberOfStudents; c++)
			{
				cout << KlassArrayHere[i]->getStudentAtIndex(c)->getAge() << endl;

			}

		}
		in.close();
	}
	else {
		cout << "Could not open file or something" << endl;
	}
}

int KlassHandler::getIndexOfKlassFromSubject(string subject) const {
	for (int i = 0; i < nrOf; i++)
	{
		if (KlassArrayHere[i]->getSubject() == subject)
		{
			return i;
		}
	}
	return -1;
}

void KlassHandler::printKlass(string subject) const {
	bool foundKlass = false;
	for (int i = 0; i < nrOf; i++)
	{
		if (KlassArrayHere[i]->getSubject() == subject)
		{
			foundKlass = true;
			cout << "Subject: " << KlassArrayHere[i]->getSubject() << endl;
			cout << "Room Code: " << KlassArrayHere[i]->getRoomCode() << endl;
			cout << "Teacher Name: " << peopleHandler.getNameFromID(KlassArrayHere[i]->getTeacher()->getID()) << endl;
			cout << "All Student Names: " << getAllStudentsNamesInKlass(subject) << endl;
			cout << "Staff Name: " << peopleHandler.getNameFromID(KlassArrayHere[i]->getStaff()->getID()) << endl;
			cout << "Average Age In Klass: " << getAverageAgeInKlass(KlassArrayHere[i]) << endl;
			cout << "Total Age In Klass: " << getTotalAgeInKlass(KlassArrayHere[i]) << endl;
			cout << endl;
			break;

		}
	}
	if (foundKlass == false)
	{
		cout << "Klass with that subject does not exist " << endl;
	}
}

void KlassHandler::printAllKlasses() const {
	for (int i = 0; i < nrOf; i++)
	{
		cout << "Subject: " << KlassArrayHere[i]->getSubject() << endl;
		cout << "Room Code: " << KlassArrayHere[i]->getRoomCode() << endl;
		cout << "Teacher Name: " << peopleHandler.getNameFromID(KlassArrayHere[i]->getTeacher()->getID()) << endl;
		cout << "Staff Name: " << peopleHandler.getNameFromID(KlassArrayHere[i]->getStaff()->getID()) << endl;
		cout << "All Student Names: " << getAllStudentsNamesInKlass(KlassArrayHere[i]->getSubject()) << endl;
		cout << "Average Age In Klass: " << getAverageAgeInKlass(KlassArrayHere[i]) << endl;
		cout << "Total Age In Klass: " << getTotalAgeInKlass(KlassArrayHere[i]) << endl;
		cout << endl;

	}
}

float KlassHandler::getAverageAgeInKlass(Klass* KlassHere) const {
	int sum = 0;
	int count = 0;
	int countHere = 0;
	float result = 0;
	for (int i = 0; i < nrOf; i++) {
		if (KlassArrayHere[i] == KlassHere) {
			sum = getTotalAgeInKlass(KlassHere);
			count += KlassArrayHere[i]->getNrOfStudents();
			count++;
			count++;
			result = sum / count;
			return result;

		}
	}
}

int KlassHandler::getTotalAgeInKlass(Klass* KlassHere) const {
	int sum = 0;
	for (int i = 0; i < nrOf; i++) {
		if (KlassArrayHere[i] == KlassHere) {
			sum += getSumStudentAgesInKlass(KlassHere);
			sum += KlassArrayHere[i]->getStaff()->getAge();
			sum += KlassArrayHere[i]->getTeacher()->getAge();
			return sum;
		}
	}
}

int KlassHandler::getTeacherAgeFromID(const int teacherID) const {
	int age;
	age = peopleHandler.getAgeFromID(teacherID);
	return age;
}

int KlassHandler::getStaffAgeFromID(const int staffID) const {
	int age;
	age = peopleHandler.getAgeFromID(staffID);
	return age;
}

int KlassHandler::getStudentAge(const int studentID) const {
	int age;
	age = peopleHandler.getAgeFromID(studentID);
	return age;
}

int KlassHandler::getSumStudentAgesInKlass(Klass* KlassHere) const {
	int sumOfStudentsAges = 0;
	Student* allStudentsInHere;
	int nrOfStudents = 0;
	for (int i = 0; i < nrOf; i++) {
		if (KlassArrayHere[i] == KlassHere) {
			nrOfStudents = KlassArrayHere[i]->getNrOfStudents();
			for (int j = 0; j < nrOfStudents; j++) {
				sumOfStudentsAges += KlassArrayHere[i]->getStudentAtIndex(j)->getAge();
			}
		}
	}
	return sumOfStudentsAges;
}

int KlassHandler::getSumPeopleTotalInKlass(string subject) const { 
	int TotalPeople = 0;
	Teacher* teacherHere;
	Staff* staffHere;
	int nrOfStudents;
	for (int i = 0; i < nrOf; i++) {
		if (KlassArrayHere[i]->getSubject() == subject) {
			teacherHere = KlassArrayHere[i]->getTeacher();
			staffHere = KlassArrayHere[i]->getStaff();
			nrOfStudents = KlassArrayHere[i]->getNrOfStudents();
			TotalPeople += nrOfStudents;
			if (dynamic_cast<Teacher*>(teacherHere) != nullptr)
			{
				TotalPeople += 1;
			}
			if (dynamic_cast<Staff*>(staffHere) != nullptr)
			{
				TotalPeople += 1;
			}
			break;
		}
	}

	return TotalPeople;
}

string KlassHandler::getTeacherName(const int& teacherID) const {
	return peopleHandler.getNameFromID(teacherID);
}

string KlassHandler::getStudentName(const int& studentID) const {
	return peopleHandler.getNameFromID(studentID);
}

string KlassHandler::getStaffName(const int& staffID) const {
	return peopleHandler.getNameFromID(staffID);
}

const string KlassHandler::getAllStudentsNamesInKlass(string subject) const { // ---------------------------------- DONE
	string stringOfStudents = "";
	for (int i = 0; i < nrOf; i++) {
		if (KlassArrayHere[i]->getSubject() == subject) {
			for (int j = 0; j < KlassArrayHere[i]->getNrOfStudents(); j++)
			{
				stringOfStudents += KlassArrayHere[i]->getStudentAtIndex(j)->getName() + ", ";

			}
			break;
		}
	}
	stringOfStudents = stringOfStudents.substr(0, stringOfStudents.size() - 2);
	return stringOfStudents;
}

string KlassHandler::findWhatKlassStudentIsInFromID(const int studentID) const {
	return findWhatKlassStudentIsInFromName(peopleHandler.getNameFromID(studentID));
}

string KlassHandler::findWhatKlassTeacherIsInFromID(const int teacherID) const {
	return findWhatKlassTeacherIsInFromName(peopleHandler.getNameFromID(teacherID));
}

string KlassHandler::findWhatKlassStaffIsInFromID(const int staffID) const {
	return findWhatKlassStaffIsInFromName(peopleHandler.getNameFromID(staffID));
}

string KlassHandler::findWhatKlassStudentIsInFromName(const string studentName) const {
	string klass = "Does not attend any classes";
	for (int i = 0; i < nrOf; i++) {
		for (int j = 0; j < KlassArrayHere[i]->getNrOfStudents(); j++)
		{
			if (KlassArrayHere[i]->getStudentAtIndex(j)->getName() == studentName)
			{
				klass = "Student " + studentName + " goes to this class: " + KlassArrayHere[i]->getSubject() + "\n";
			}
		}
	}
	return klass;
}

string KlassHandler::findWhatKlassTeacherIsInFromName(const string teacherName) const {
	string klass = "Does not tend any classes";
	for (int i = 0; i < nrOf; i++) {
		if (KlassArrayHere[i]->getTeacher()->getName() == teacherName)
		{
			klass = "Teacher " + teacherName + " teaches this class: " + KlassArrayHere[i]->getSubject() + "\n";
		}
	}
	return klass;
}

string KlassHandler::findWhatKlassStaffIsInFromName(const string staffName) const {
	string klass = "Is not responsible for any classes";
	for (int i = 0; i < nrOf; i++) {
		if (KlassArrayHere[i]->getStaff()->getName() == staffName)
		{
			klass = "Staff " + staffName + " is responsible this class: " + KlassArrayHere[i]->getSubject() + "\n";
		}
	}
	return klass;
}

string KlassHandler::findWhatKlassPersonIsInFromID(const int personID, const string personType) const {
	if (personType == "Student")
	{
		return findWhatKlassStudentIsInFromID(personID);
	}

	else if (personType == "Teacher")
	{
		return findWhatKlassTeacherIsInFromID(personID);

	}
	else if (personType == "Staff")
	{
		return findWhatKlassStaffIsInFromID(personID);

	}
	else
	{
		return "Invalid person type";
	}
}

string KlassHandler::findWhatKlassPersonIsFromName(const string personName, const string personType) const {
	if (personType == "Student")
	{
		return findWhatKlassStudentIsInFromName(personName);
	}

	else if (personType == "Teacher")
	{
		return findWhatKlassTeacherIsInFromName(personName);

	}
	else if (personType == "Staff")
	{
		return findWhatKlassStaffIsInFromName(personName);

	}
	else
	{
		return "Invalid person type";
	}
}

string KlassHandler::findWhatKlassPersonIsFromNameOrID(const string personNameOrID, const string personType) const {
	if (isdigit(personNameOrID[0]))
	{
		int personID = stoi(personNameOrID);
		return findWhatKlassPersonIsInFromID(personID, personType);
	}
	else
	{
		return findWhatKlassPersonIsFromName(personNameOrID, personType);
	}
}

string KlassHandler::findWHatKlassPersonIsFromNameOrIDWithoutPersonType(const string personNameOrID) const {
	if (isdigit(personNameOrID[0]))
	{
		int personID = stoi(personNameOrID);
		string try1 = findWhatKlassPersonIsInFromID(personID, "Student");
		string try2 = findWhatKlassPersonIsInFromID(personID, "Teacher");
		string try3 = findWhatKlassPersonIsInFromID(personID, "Staff");
		if (try1 != "Does not attend any classes")
		{
			return try1;
		}
		else if (try2 != "Does not tend any classes")
		{
			return try2;
		}
		else if (try3 != "Is not responsible for any classes")
		{
			return try3;
		}
		else
		{
			return "Person does not exist";
		}
	}
	else
	{
		string try4 = findWhatKlassPersonIsFromName(personNameOrID, "Student");
		string try5 = findWhatKlassPersonIsFromName(personNameOrID, "Teacher");
		string try6 = findWhatKlassPersonIsFromName(personNameOrID, "Staff");
		if (try4 != "Does not attend any classes")
		{
			return try4;
		}
		else if (try5 != "Does not tend any classes")
		{
			return try5;
		}
		else if (try6 != "Is not responsible for any classes")
		{
			return try6;
		}
		else
		{
			return "Person does not exist";
		}
	}
}

void KlassHandler::addKlassJustRoomCodeAndSubject() {
	if (nrOf < CAP) {
		string roomCode;
		string subject;
		cout << "Enter room code: ";
		getline(cin, roomCode);
		cout << "Enter subject: ";
		getline(cin, subject);
		KlassArrayHere[nrOf] = new Klass(roomCode, subject);
		cout << "Would you like to add a teacher to this class? Y/N" << endl;
		string choice;
		getline(cin, choice);
		if (choice == "Y") {
			cout << "Heres a list of the Teachers to help you remember who to add: " << endl;
			peopleHandler.printAllExistingPeopleOfType("Teacher");
			int teacherID;
			string teacherIDOrName;
			cout << "Enter existing teacher ID or Name: (9 digits or less for ID)";
			cin >> teacherIDOrName;
			cin.ignore();
			while (true)
			{
				if (isdigit(teacherIDOrName[0])) {
					try
					{
						teacherID = stoi(teacherIDOrName);
						teacherIDOrName = peopleHandler.getTypeNameFromID(teacherID, "Teacher");
						if (teacherIDOrName == "Not found")
						{
							cout << "Teacher with the ID :  " << teacherID << " does not exist." << endl;
							cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
							cout << "Enter existing teacher ID or Name: " << endl;
							cin >> teacherIDOrName;
						}
						else
						{
							Teacher* teacherHere = peopleHandler.getTeacherFromID(teacherID);
							KlassArrayHere[nrOf]->setTeacher(teacherHere);
							cout << "Teacher with the Name :  " << teacherIDOrName << " and ID: " << teacherID << " has been added." << endl;
							break;

						}

					}
					catch (const std::exception&)
					{
						cout << "You entered a non-numeric value for the ID or it was larger then 9 digits, please enter a numeric value:" << endl;
						cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
						cout << "Enter existing teacher ID or Name: " << endl;
						cin >> teacherIDOrName;

					}
				}
				else if (teacherIDOrName == "stop" || teacherIDOrName == "s") {
					break;
				}
				else {
					teacherID = peopleHandler.getTypeIDFromName(teacherIDOrName, "Teacher");
					if (teacherID == -1) {
						cout << "Teacher with the Name :  " << teacherIDOrName << " does not exist." << endl;
						cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
						cout << "Enter existing teacher ID or Name: " << endl;
						cin >> teacherIDOrName;
						cin.ignore();
					}
					else {
						Teacher* teacherHere = peopleHandler.getTeacherFromID(teacherID);
						KlassArrayHere[nrOf]->setTeacher(teacherHere);
						cout << "Teacher with the Name :  " << teacherIDOrName << " and ID: " << teacherID << " has been added." << endl;
						break;
					}

				}


			}
		}
		else
		{
			Teacher* teacherHere = peopleHandler.getTeacherFromID(2);
			KlassArrayHere[nrOf]->setTeacher(teacherHere);
		}

		cout << "Would you like to add Staff to this class? Y/N" << endl;
		string choiceStaff;
		getline(cin, choiceStaff);
		if (choiceStaff == "Y") {
			cout << "Heres a list of the Staff to help you remember who to add: " << endl;
			peopleHandler.printAllExistingPeopleOfType("Staff");
			int staffID;
			string staffIDOrName;
			cout << "Enter existing Staff ID or Name: (9 digits or less for ID)";
			cin >> staffIDOrName;
			cin.ignore();
			while (true)
			{
				if (isdigit(staffIDOrName[0])) {
					try
					{
						staffID = stoi(staffIDOrName);
						staffIDOrName = peopleHandler.getTypeNameFromID(staffID, "Staff");
						if (staffIDOrName == "Not found")
						{
							cout << "Staff with the ID :  " << staffID << " does not exist." << endl;
							cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
							cout << "Enter existing Staff ID or Name: " << endl;
							cin >> staffIDOrName;
						}
						else
						{
							Staff* staffHere = peopleHandler.getStaffFromID(staffID);
							KlassArrayHere[nrOf]->setStaff(staffHere);
							cout << "Staff with the Name :  " << staffIDOrName << " and ID: " << staffID << " has been added." << endl;
							break;

						}

					}
					catch (const std::exception&)
					{
						cout << "You entered a non-numeric value for the ID or it was larger then 9 digits, please enter a numeric value:" << endl;
						cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
						cout << "Enter existing Staff ID or Name: " << endl;
						cin >> staffIDOrName;

					}
				}
				else if (staffIDOrName == "stop" || staffIDOrName == "s") {
					break;
				}
				else {
					staffID = peopleHandler.getTypeIDFromName(staffIDOrName, "Staff");
					if (staffID == -1) {
						cout << "Staff with the Name :  " << staffIDOrName << " does not exist." << endl;
						cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
						cout << "Enter existing Staff ID or Name: " << endl;
						cin >> staffIDOrName;
						cin.ignore();
					}
					else {
						Staff* staffHere = peopleHandler.getStaffFromID(staffID);
						KlassArrayHere[nrOf]->setStaff(staffHere);
						cout << "Staff with the Name :  " << staffIDOrName << " and ID: " << staffID << " has been added." << endl;
						break;
					}

				}


			}
		}
		else
		{
			Staff* staffHere = peopleHandler.getStaffFromID(1);
			KlassArrayHere[nrOf]->setStaff(staffHere);
		}

		cout << "Would you like to add Students to this class? Y/N" << endl;
		string choiceStudents;
		getline(cin, choiceStudents);
		if (choiceStudents == "Y")
		{
			cout << "How many existing students do you want to input? ";
			int amountOfStudents;
			cin >> amountOfStudents;
			cin.ignore();
			while (true)
			{
				try
				{
					if (amountOfStudents > 50)
					{
						cout << "Too many students. Maximum 50:";
						cin >> amountOfStudents;
						cin.ignore();
					}
					else if (amountOfStudents < 0)
					{
						cout << "You must enter a positive number: ";
						cin >> amountOfStudents;
						cin.ignore();
					}
					else
					{
						break;
					}

				}
				catch (const std::exception&)
				{
					cout << "You must enter a NUMBER under 50" << endl;
					cin >> amountOfStudents;
					cin.ignore();


				}

			}
			for (int i = 0; i < amountOfStudents; i++) {
				cout << ((amountOfStudents - (i))) << " student(s) left to input." << endl;
				cout << "Heres a list of the existing Students to help you remember who to add: " << endl;
				peopleHandler.printAllExistingPeopleOfType("Student");
				cout << "To stop entering students type \"stop\" or \"s\"." << endl;
				cout << "Enter existing student ID or Name: (9 digits or less for ID)";
				int studentID;
				string studentIDOrName;
				string studentName;
				cin >> studentIDOrName;
				cin.ignore();

				while (true)
				{
					if (isdigit(studentIDOrName[0])) {
						try
						{
							studentID = stoi(studentIDOrName);
							studentIDOrName = peopleHandler.getTypeNameFromID(studentID, "Student");
							if (studentIDOrName == "Not found")
							{
								cout << "Student with the ID :  " << studentID << " does not exist." << endl;
								cout << "Heres a list of the existing Students to help you remember who to add: " << endl;
								peopleHandler.printAllExistingPeopleOfType("Student");
								cout << "Enter existing student ID or Name: " << endl;
								cin >> studentIDOrName;
							}
							else
							{
								bool alreadyExists = false;
								Student* studentHere = peopleHandler.getStudentFromID(studentID);
								if (KlassArrayHere[nrOf]->checkIfStudentExistsInKlass(studentHere))
								{
									alreadyExists = true;
									cout << "Student with the Name :  " << studentIDOrName << " and ID: " << studentID << " is already in the Klass." << endl;
									i--;
									break;
								}
								if (alreadyExists == false)
								{
									Student* studentHere = peopleHandler.getStudentFromID(studentID);
									KlassArrayHere[nrOf]->setStudentLast(studentHere);
									cout << "Student with the Name :  " << studentIDOrName << " and ID: " << studentID << " has been added." << endl;

								}
								break;

							}

						}
						catch (const std::exception&)
						{
							cout << "You entered a non-numeric value for the ID or it was larger then 9 digits, please enter a numeric value:" << endl;
							cout << "Heres a list of the existing Students to help you remember who to add: " << endl;
							peopleHandler.printAllExistingPeopleOfType("Student");
							cout << "Enter existing student ID or Name: " << endl;
							cin >> studentIDOrName;

						}
					}
					else if (studentIDOrName == "stop" || studentIDOrName == "s") {
						break;
					}
					else {
						studentID = peopleHandler.getTypeIDFromName(studentIDOrName, "Student");
						if (studentID == -1) {
							cout << "Student with the Name :  " << studentIDOrName << " does not exist." << endl;
							cout << "Heres a list of the existing Students to help you remember who to add: " << endl;
							peopleHandler.printAllExistingPeopleOfType("Student");
							cout << "Enter existing student ID or Name: " << endl;
							cin >> studentIDOrName;
							cin.ignore();
						}
						else {
							bool alreadyExists = false;
							Student* studentHere = peopleHandler.getStudentFromID(studentID);
							if (KlassArrayHere[nrOf]->checkIfStudentExistsInKlass(studentHere))
							{
								alreadyExists = true;
								cout << "Student with the Name :  " << studentIDOrName << " and ID: " << studentID << " is already in the Klass." << endl;
								i--;
								break;
							}
							if (alreadyExists == false)
							{
								Student* studentHere = peopleHandler.getStudentFromID(studentID);
								KlassArrayHere[nrOf]->setStudentLast(studentHere);
								cout << "Student with the Name :  " << studentIDOrName << " and ID: " << studentID << " has been added." << endl;
							}
							break;
						}

					}


				}
			}

		}

		nrOf++;
	}
	else {
		cout << "No more space for Klasses :( " << endl;
	}
}

void KlassHandler::addFullKlass() {
	if (nrOf < CAP) {
		string roomCode;
		string subject;
		int teacherID;
		string teacherIDOrName;
		int staffID;
		string staffIDOrName;
		string allStudentsID;
		cout << "Enter room code: ";
		getline(cin, roomCode);
		cout << "Enter subject: ";
		getline(cin, subject);
		cout << "Enter existing teacher ID or Name: (9 digits or less for ID)";
		cout << "Heres a list of the existing Teachers to help you remember who to add: " << endl;
		peopleHandler.printAllExistingPeopleOfType("Teacher");
		cin >> teacherIDOrName;
		cin.ignore();
		while (true)
		{
			if (isdigit(teacherIDOrName[0])) {
				try
				{
					teacherID = stoi(teacherIDOrName);
					teacherIDOrName = peopleHandler.getTypeNameFromID(teacherID, "Teacher");
					if (teacherIDOrName == "Not found")
					{
						cout << "Teacher with the ID :  " << teacherID << " does not exist." << endl;
						cout << "Heres a list of the existing Teachers to help you remember who to add: " << endl;
						peopleHandler.printAllExistingPeopleOfType("Teacher");
						cout << "Enter existing teacher ID or Name: " << endl;
						cin >> teacherIDOrName;
					}
					else
					{

						cout << "Teacher with the Name :  " << teacherIDOrName << " and ID: " << teacherID << " has been added." << endl;
						break;

					}

				}
				catch (const std::exception&)
				{
					cout << "You entered a non-numeric value for the ID or it was larger then 9 digits, please enter a numeric value:" << endl;
					cout << "Heres a list of the existing Teachers to help you remember who to add: " << endl;
					peopleHandler.printAllExistingPeopleOfType("Teacher");
					cout << "Enter existing teacher ID or Name: " << endl;
					cin >> teacherIDOrName;

				}
			}
			else {
				teacherID = peopleHandler.getTypeIDFromName(teacherIDOrName, "Teacher");
				if (teacherID == -1) {
					cout << "Teacher with the Name :  " << teacherIDOrName << " does not exist." << endl;
					cout << "Heres a list of the existing Teachers to help you remember who to add: " << endl;
					peopleHandler.printAllExistingPeopleOfType("Teacher");
					cout << "Enter existing teacher ID or Name: " << endl;
					cin >> teacherIDOrName;
					cin.ignore();
				}
				else {
					cout << "Teacher with the Name :  " << teacherIDOrName << " and ID: " << teacherID << " has been added." << endl;
					break;
				}

			}


		}

		cout << "Enter existing staff ID or Name: (9 digits or less for ID)";
		cout << "Heres a list of the existing Staff to help you remember who to add: " << endl;
		peopleHandler.printAllExistingPeopleOfType("Staff");
		cin >> staffIDOrName;
		cin.ignore();
		while (true)
		{
			if (isdigit(staffIDOrName[0])) {
				try
				{
					staffID = stoi(staffIDOrName);
					staffIDOrName = peopleHandler.getTypeNameFromID(staffID, "Staff");
					if (staffIDOrName == "Not found")
					{
						cout << "Staff with the ID :  " << staffID << " does not exist." << endl;
						cout << "Heres a list of the existing Staff to help you remember who to add: " << endl;
						peopleHandler.printAllExistingPeopleOfType("Staff");
						cout << "Enter existing staff ID or Name: " << endl;
						cin >> staffIDOrName;
					}
					else
					{
						cout << "Staff with the Name :  " << staffIDOrName << " and ID: " << staffID << " has been added." << endl;
						break;

					}

				}
				catch (const std::exception&)
				{
					cout << "You entered a non-numeric value for the ID or it was larger then 9 digits, please enter a numeric value:" << endl;
					cout << "Heres a list of the existing Staff to help you remember who to add: " << endl;
					peopleHandler.printAllExistingPeopleOfType("Staff");
					cout << "Enter existing staff ID or Name: " << endl;
					cin >> staffIDOrName;

				}
			}
			else {
				staffID = peopleHandler.getTypeIDFromName(staffIDOrName, "Staff");
				if (staffID == -1) {
					cout << "Staff with the Name :  " << staffIDOrName << " does not exist." << endl;
					cout << "Heres a list of the existing Staff to help you remember who to add: " << endl;
					peopleHandler.printAllExistingPeopleOfType("Staff");
					cout << "Enter existing staff ID or Name: " << endl;
					cin >> staffIDOrName;
					cin.ignore();
				}
				else {
					cout << "Staff with the Name :  " << staffIDOrName << " and ID: " << staffID << " has been added." << endl;
					break;
				}

			}


		}

		cout << "How many existing students do you want to input? ";
		int amountOfStudents;
		cin >> amountOfStudents;
		cin.ignore();
		while (true)
		{
			try
			{
				if (amountOfStudents > 50)
				{
					cout << "Too many students. Maximum 50:";
					cin >> amountOfStudents;
					cin.ignore();
				}
				else if (amountOfStudents < 0)
				{
					cout << "You must enter a positive number: ";
					cin >> amountOfStudents;
					cin.ignore();
				}
				else
				{
					break;
				}

			}
			catch (const std::exception&)
			{
				cout << "You must enter a NUMBER under 50" << endl;
				cin >> amountOfStudents;
				cin.ignore();


			}

		}
		for (int i = 0; i < amountOfStudents; i++) {
			cout << ((amountOfStudents - (i))) << " student(s) left to input." << endl;
			cout << "To stop entering students type \"stop\" or \"s\"." << endl;
			cout << "Enter existing student ID or Name: (9 digits or less for ID)";
			cout << "Heres a list of the existing Students to help you remember who to add: " << endl;
			peopleHandler.printAllExistingPeopleOfType("Student");
			int studentID;
			string studentIDOrName;
			string studentName;
			cin >> studentIDOrName;
			cin.ignore();

			while (true)
			{
				if (isdigit(studentIDOrName[0])) {
					try
					{
						studentID = stoi(studentIDOrName);
						studentIDOrName = peopleHandler.getTypeNameFromID(studentID, "Student");
						if (studentIDOrName == "Not found")
						{
							cout << "Student with the ID :  " << studentID << " does not exist." << endl;
							cout << "Heres a list of the existing Students to help you remember who to add: " << endl;
							peopleHandler.printAllExistingPeopleOfType("Student");
							cout << "Enter existing student ID or Name: " << endl;
							cin >> studentIDOrName;
						}
						else
						{
							allStudentsID += to_string(studentID) + "/";
							cout << "Student with the Name :  " << studentIDOrName << " and ID: " << studentID << " has been added." << endl;

							break;

						}

					}
					catch (const std::exception&)
					{
						cout << "You entered a non-numeric value for the ID or it was larger then 9 digits, please enter a numeric value:" << endl;
						cout << "Heres a list of the existing Students to help you remember who to add: " << endl;
						peopleHandler.printAllExistingPeopleOfType("Student");
						cout << "Enter existing student ID or Name: " << endl;
						cin >> studentIDOrName;

					}
				}
				else if (studentIDOrName == "stop" || studentIDOrName == "s") {
					break;
				}
				else {
					studentID = peopleHandler.getTypeIDFromName(studentIDOrName, "Student");
					if (studentID == -1) {
						cout << "Student with the Name :  " << studentIDOrName << " does not exist." << endl;
						cout << "Heres a list of the existing Students to help you remember who to add: " << endl;
						peopleHandler.printAllExistingPeopleOfType("Student");
						cout << "Enter existing student ID or Name: " << endl;
						cin >> studentIDOrName;
						cin.ignore();
					}
					else {
						allStudentsID += to_string(studentID) + "/";
						cout << "Student with the Name :  " << studentIDOrName << " and ID: " << studentID << " has been added." << endl;
						break;
					}
				}


			}


		}


		Teacher* teacherHere = peopleHandler.getTeacherFromID(teacherID);
		Staff* staffHere = peopleHandler.getStaffFromID(staffID);

		int numberOfStudents = 0;
		Student* allStudentsHere[50] = { nullptr };
		int j = 0;
		string temp = "";
		for (int i = 0; i < allStudentsID.size(); i++) {
			if (allStudentsID[i] == '/') {
				allStudentsHere[j] = peopleHandler.getStudentFromID(stoi(temp));
				numberOfStudents++;
				temp = "";
				j++;
			}
			else {
				temp += allStudentsID[i];
			}
		}

		KlassArrayHere[nrOf] = new Klass(roomCode, subject, teacherHere, staffHere, allStudentsHere, numberOfStudents);

		nrOf++;
	}
	else {
		cout << "No more space for Klasses :( " << endl;
	}
}

void KlassHandler::removeKlass() {
	cout << "Heres a list of the Klasses to help you remember who to remove: " << endl;
	for (int i = 0; i < nrOf; i++)
	{
		cout << KlassArrayHere[i]->getSubject() << endl;
	}
	cout << "Enter subject of klass to remove: ";
	string subject;
	string sure;
	bool found = false;
	getline(cin, subject);
	for (int i = 0; i < nrOf; i++)
	{
		if (subject == KlassArrayHere[i]->getSubject())
		{
			found = true;
			cout << "Are you sure you want to delete this Klass and all its contents? Y/N " << endl;
			getline(cin, sure);
			if (sure == "Y")
			{
				delete KlassArrayHere[i];
				KlassArrayHere[i] = KlassArrayHere[nrOf - 1];
				nrOf--;
				cout << "Klass with the subject: " << subject << " deleted" << endl;
			}
			else
			{
				cout << "Klass not removed" << endl;
			}

			break;
		}
		else
		{
			cout << "Searching for Klass..." << endl;
		}
		{

		}

	}
	if (found == false)
	{
		cout << "Klass with that subject name does not exist. Nothing was deleted.";
	}
}

void KlassHandler::updateKlass() {
	cout << "Enter subject of klass to update: " << endl;
	cout << "Heres a list of the Klasses to help you remember what subject to update a person to: " << endl;
	for (int i = 0; i < nrOf; i++)
	{
		cout << KlassArrayHere[i]->getSubject() << endl;
	}
	cout << endl;
	cout << endl;
	string subject;
	getline(cin, subject);
	endlinesFancy();
	bool foundKlass = false;
	for (int i = 0; i < nrOf; i++) {
		if (KlassArrayHere[i]->getSubject() == subject) {
			foundKlass = true;
			string roomCode;
			string subject;
			int teacherID;
			int staffID;
			string allStudentsID;
			cout << "Here is the current room code: " << KlassArrayHere[i]->getRoomCode() << endl;
			cout << "Enter room code to update to, or type same room code to keep it the same: " << endl << endl;
			getline(cin, roomCode);
			endlinesFancy();
			cout << "Here is the current subject: " << KlassArrayHere[i]->getSubject() << endl;
			cout << "Enter subject to update to, or type same subject to keep it the same: " << endl;
			getline(cin, subject);
			endlinesFancy();
			cout << "Here is the current teacher ID: " << KlassArrayHere[i]->getTeacher()->getID() << endl;
			//print all teachers info so the user remembers what to type
			cout << "Heres a list of the existing Teachers to help you remember who to add: " << endl;
			peopleHandler.printAllExistingPeopleOfType("Teacher");
			cout << "Enter teacher ID to update to, or type same ID to keep it the same: " << endl << endl;
			cin >> teacherID;
			cin.ignore();
			endlinesFancy();
			while (true)
			{
				if (teacherID != KlassArrayHere[i]->getTeacher()->getID() && peopleHandler.getTypeNameFromID(teacherID, "Teacher") == "Not found")
				{
					cout << "Teacher with the ID :  " << teacherID << " does not exist." << endl;
					cout << "Heres a list of the existing Teachers to help you remember who to add: " << endl;
					peopleHandler.printAllExistingPeopleOfType("Teacher");
					cout << "Enter teacher ID to update to, or type same ID to keep it the same: " << endl << endl;
					cin >> teacherID;
					cin.ignore();
					endlinesFancy();
				}
				else
				{
					break;
				}
			}
			cout << "Here is the current staff ID: " << KlassArrayHere[i]->getStaff()->getID() << endl;
			cout << "Heres a list of the existing Staff to help you remember who to add: " << endl;
			peopleHandler.printAllExistingPeopleOfType("Staff");
			cout << "Enter staff ID to update to, or type same ID to keep it the same: " << endl << endl;
			cin >> staffID;
			cin.ignore();
			endlinesFancy();
			while (true)
			{
				if (staffID != KlassArrayHere[i]->getStaff()->getID() && peopleHandler.getTypeNameFromID(staffID, "Staff") == "Not found")
				{
					cout << "Staff with the ID :  " << staffID << " does not exist." << endl;
					cout << "Heres a list of the existing Staff to help you remember who to add: " << endl;
					peopleHandler.printAllExistingPeopleOfType("Staff");
					cout << "Enter staff ID to update to, or type same ID to keep it the same: " << endl << endl;
					cin >> staffID;
					cin.ignore();
					endlinesFancy();
				}
				else
				{
					break;
				}
			}
			if (KlassArrayHere[i]->getNrOfStudents() != 0)
			{
				cout << "Here is the current students ID: " << KlassArrayHere[i]->getAllStudents()->getID() << endl;
				//print all teachers info so the user remembers what to type
				cout << "Heres a list of the existing Students to help you remember who to add: " << endl;
				peopleHandler.printAllExistingPeopleOfType("Student");

			}
			else
			{
				cout << "No students exist yet in this Klass. " << endl;
			}
			cout << "Enter all students ID separated by a slash (eg: \"/\") to update to, or type same ID's to keep it the same: (end the prompt with a slash eg: 100/20/40/ )" << endl << endl;
			getline(cin, allStudentsID);
			endlinesFancy();
			Teacher* teacherHere = peopleHandler.getTeacherFromID(teacherID);
			Staff* staffHere = peopleHandler.getStaffFromID(staffID);


			int numberOfStudents = 0;
			Student* allStudentsHere[50] = { nullptr };
			int j = 0;
			string temp = "";
			for (int i = 0; i < allStudentsID.size(); i++) {
				if (allStudentsID[i] == '/') {
					allStudentsHere[j] = peopleHandler.getStudentFromID(stoi(temp));
					numberOfStudents++;
					temp = "";
					j++;
				}
				else {
					temp += allStudentsID[i];
				}
			}


			KlassArrayHere[i] = new Klass(roomCode, subject, teacherHere, staffHere, allStudentsHere, numberOfStudents);
			break;
		}
		else
		{
			cout << "Searching for Klass..." << endl;

		}
	}
	if (foundKlass == false)
	{
		cout << "Klass with that subject name does not exist. Nothing was updated.";
	}
}

void KlassHandler::endlinesFancy() {
	cout << "---------------------------------------------------" << endl << endl;
}

void KlassHandler::addPersonToKlass(string personType) {
	cout << "Enter subject of klass to add a " << personType << " to: ";
	cout << "Heres a list of the Klasses to help you remember what subject to add the person to: " << endl;
	for (int i = 0; i < nrOf; i++)
	{
		cout << KlassArrayHere[i]->getSubject() << endl;
	}
	string subject;
	bool found = false;
	getline(cin, subject);
	for (int i = 0; i < nrOf; i++) {
		if (KlassArrayHere[i]->getSubject() == subject) {
			found = true;
			if (personType == "Student") {
				cout << "Are you sure you want to add Students to this class? Y/N  :)" << endl;
				string choiceStudents;
				getline(cin, choiceStudents);
				if (choiceStudents == "Y")
				{
					cout << "How many existing students do you want to input? ";
					int amountOfStudents;
					cin >> amountOfStudents;
					cin.ignore();
					while (true)
					{
						try
						{
							if (amountOfStudents > 50)
							{
								cout << "Too many students. Maximum 50:";
								cin >> amountOfStudents;
								cin.ignore();
							}
							else if (amountOfStudents < 0)
							{
								cout << "You must enter a positive number: ";
								cin >> amountOfStudents;
								cin.ignore();
							}
							else
							{
								break;
							}

						}
						catch (const std::exception&)
						{
							cout << "You must enter a NUMBER under 50" << endl;
							cin >> amountOfStudents;
							cin.ignore();


						}

					}
					for (int i = 0; i < amountOfStudents; i++) {
						cout << "To stop entering students type \"stop\" or \"s\"." << endl;
						cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
						peopleHandler.printAllExistingPeopleOfType(personType);
						cout << "Enter existing student ID or Name: (9 digits or less for ID)";
						int studentID;
						string studentIDOrName;
						string studentName;
						cin >> studentIDOrName;
						cin.ignore();

						while (true)
						{
							if (isdigit(studentIDOrName[0])) {
								try
								{
									studentID = stoi(studentIDOrName);
									studentIDOrName = peopleHandler.getTypeNameFromID(studentID, "Student");
									if (studentIDOrName == "Not found")
									{
										cout << "Student with the ID :  " << studentID << " does not exist." << endl;
										cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
										peopleHandler.printAllExistingPeopleOfType(personType);
										cout << "Enter existing student ID or Name: " << endl;
										cin >> studentIDOrName;
									}
									else
									{
										bool alreadyExists = false;
										Student* studentHere = peopleHandler.getStudentFromID(studentID);
										if (KlassArrayHere[i]->checkIfStudentExistsInKlass(studentHere))
										{
											alreadyExists = true;
											cout << "Student with the Name :  " << studentIDOrName << " and ID: " << studentID << " is already in the Klass." << endl;
											i--;
											break;
										}
										if (alreadyExists == false)
										{
											Student* studentHere = peopleHandler.getStudentFromID(studentID);
											KlassArrayHere[i]->setStudentLast(studentHere);
											cout << "Student with the Name :  " << studentIDOrName << " and ID: " << studentID << " has been added." << endl;
										}
										break;

									}

								}
								catch (const std::exception&)
								{
									cout << "You entered a non-numeric value for the ID or it was larger then 9 digits, please enter a numeric value:" << endl;
									cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
									peopleHandler.printAllExistingPeopleOfType(personType);
									cout << "Enter existing student ID or Name: " << endl;
									cin >> studentIDOrName;

								}
							}
							else if (studentIDOrName == "stop" || studentIDOrName == "s") {
								break;
							}
							else {
								studentID = peopleHandler.getTypeIDFromName(studentIDOrName, "Student");
								if (studentID == -1) {
									cout << "Student with the Name :  " << studentIDOrName << " does not exist." << endl;
									cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
									peopleHandler.printAllExistingPeopleOfType(personType);
									cout << "Enter existing student ID or Name: " << endl;
									cin >> studentIDOrName;
									cin.ignore();
								}
								else {
									bool alreadyExists = false;
									Student* studentHere = peopleHandler.getStudentFromID(studentID);
									if (KlassArrayHere[i]->checkIfStudentExistsInKlass(studentHere))
									{
										alreadyExists = true;
										cout << "Student with the Name :  " << studentIDOrName << " and ID: " << studentID << " is already in the Klass." << endl;
										i--;
										break;
									}
									if (alreadyExists == false)
									{
										Student* studentHere = peopleHandler.getStudentFromID(studentID);
										KlassArrayHere[i]->setStudentLast(studentHere);
										cout << "Student with the Name :  " << studentIDOrName << " and ID: " << studentID << " has been added." << endl;
									}
									break;
								}

							}


						}
					}

				}
			}
			else if (personType == "Teacher") {
				cout << "Are you sure you want to add a Teacher to this class? Y/N  :)" << endl;
				string choice;
				getline(cin, choice);
				if (choice == "Y") {
					int teacherID;
					string teacherIDOrName;
					cout << "Enter existing teacher ID or Name: (9 digits or less for ID)";
					cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
					peopleHandler.printAllExistingPeopleOfType(personType);
					cin >> teacherIDOrName;
					cin.ignore();
					while (true)
					{
						if (isdigit(teacherIDOrName[0])) {
							try
							{
								teacherID = stoi(teacherIDOrName);
								teacherIDOrName = peopleHandler.getTypeNameFromID(teacherID, "Teacher");
								if (teacherIDOrName == "Not found")
								{
									cout << "Teacher with the ID :  " << teacherID << " does not exist." << endl;
									cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
									cout << "Enter existing teacher ID or Name: " << endl;
									cin >> teacherIDOrName;
								}
								else
								{
									Teacher* teacherHere = peopleHandler.getTeacherFromID(teacherID);
									KlassArrayHere[i]->setTeacher(teacherHere);
									cout << "Teacher with the Name :  " << teacherIDOrName << " and ID: " << teacherID << " has been added." << endl;
									break;

								}

							}
							catch (const std::exception&)
							{
								cout << "You entered a non-numeric value for the ID or it was larger then 9 digits, please enter a numeric value:" << endl;
								cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
								cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
								peopleHandler.printAllExistingPeopleOfType(personType);
								cout << "Enter existing teacher ID or Name: " << endl;
								cin >> teacherIDOrName;

							}
						}
						else if (teacherIDOrName == "stop" || teacherIDOrName == "s") {
							break;
						}
						else {
							teacherID = peopleHandler.getTypeIDFromName(teacherIDOrName, "Teacher");
							if (teacherID == -1) {
								cout << "Teacher with the Name :  " << teacherIDOrName << " does not exist." << endl;
								cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
								cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
								peopleHandler.printAllExistingPeopleOfType(personType);
								cout << "Enter existing teacher ID or Name: " << endl;
								cin >> teacherIDOrName;
								cin.ignore();
							}
							else {
								Teacher* teacherHere = peopleHandler.getTeacherFromID(teacherID);
								KlassArrayHere[i]->setTeacher(teacherHere);
								cout << "Teacher with the Name :  " << teacherIDOrName << " and ID: " << teacherID << " has been added." << endl;
								break;
							}

						}


					}
				}
			}
			else if (personType == "Staff") {
				cout << "Are you sure you want to add Staff to this class? Y/N  :)" << endl;
				string choiceStaff;
				getline(cin, choiceStaff);
				if (choiceStaff == "Y") {
					int staffID;
					string staffIDOrName;
					cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
					peopleHandler.printAllExistingPeopleOfType(personType);
					cout << "Enter existing Staff ID or Name: (9 digits or less for ID)";
					cin >> staffIDOrName;
					cin.ignore();
					while (true)
					{
						if (isdigit(staffIDOrName[0])) {
							try
							{
								staffID = stoi(staffIDOrName);
								staffIDOrName = peopleHandler.getTypeNameFromID(staffID, "Teacher");
								if (staffIDOrName == "Not found")
								{
									cout << "Staff with the ID :  " << staffID << " does not exist." << endl;
									cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
									cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
									peopleHandler.printAllExistingPeopleOfType(personType);
									cout << "Enter existing Staff ID or Name: " << endl;
									cin >> staffIDOrName;
								}
								else
								{
									Staff* staffHere = peopleHandler.getStaffFromID(staffID);
									KlassArrayHere[i]->setStaff(staffHere);
									cout << "Staff with the Name :  " << staffIDOrName << " and ID: " << staffID << " has been added." << endl;
									break;

								}

							}
							catch (const std::exception&)
							{
								cout << "You entered a non-numeric value for the ID or it was larger then 9 digits, please enter a numeric value:" << endl;
								cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
								cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
								peopleHandler.printAllExistingPeopleOfType(personType);
								cout << "Enter existing Staff ID or Name: " << endl;
								cin >> staffIDOrName;

							}
						}
						else if (staffIDOrName == "stop" || staffIDOrName == "s") {
							break;
						}
						else {
							staffID = peopleHandler.getTypeIDFromName(staffIDOrName, "Staff");
							if (staffID == -1) {
								cout << "Staff with the Name :  " << staffIDOrName << " does not exist." << endl;
								cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
								cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
								peopleHandler.printAllExistingPeopleOfType(personType);
								cout << "Enter existing Staff ID or Name: " << endl;
								cin >> staffIDOrName;
								cin.ignore();
							}
							else {
								Staff* staffHere = peopleHandler.getStaffFromID(staffID);
								KlassArrayHere[i]->setStaff(staffHere);
								cout << "Staff with the Name :  " << staffIDOrName << " and ID: " << staffID << " has been added." << endl;
								break;
							}

						}


					}
				}
			}
			break;
		}
		else
		{
			cout << "Searching for Klass.." << endl;
		}

	}
	if (found == false)
	{
		cout << "Klass with that subject name does not exist. Nothing was added.";
	}
}

void KlassHandler::removePersonFromKlass(string personType, string KlassSubject) {
	cout << "A " << personType << " will be removed from " << KlassSubject << endl;
	for (int i = 0; i < nrOf; i++) {
		if (KlassArrayHere[i]->getSubject() == KlassSubject) {
			if (personType == "Student") {
				cout << "Are you sure you want to remove a Student from this class? Y/N  :)" << endl;
				string choiceStudents;
				cin >> choiceStudents;
				cin.ignore();
				if (choiceStudents == "Y")
				{
					cout << "How many existing students do you want to remove? ";
					int amountOfStudents;
					cin >> amountOfStudents;
					cin.ignore();
					while (true)
					{
						try
						{
							if (amountOfStudents > 50)
							{
								cout << "Too many students. Maximum 50:";
								cin >> amountOfStudents;
								cin.ignore();
							}
							else if (amountOfStudents < 0)
							{
								cout << "You must enter a positive number: ";
								cin >> amountOfStudents;
								cin.ignore();
							}
							else
							{
								break;
							}

						}
						catch (const std::exception&)
						{
							cout << "You must enter a NUMBER under 50" << endl;
							cin >> amountOfStudents;
							cin.ignore();


						}

					}
					for (int i = 0; i < amountOfStudents; i++) {
						cout << "To stop entering students to remove type \"stop\" or \"s\"." << endl;
						cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
						peopleHandler.printAllExistingPeopleOfType(personType);
						cout << "Enter existing student ID or Name to remove from " << KlassSubject << ": (9 digits or less for ID)" << endl;
						int studentID;
						string studentIDOrName;
						string studentName;
						cin >> studentIDOrName;
						cin.ignore();

						while (true)
						{
							if (isdigit(studentIDOrName[0])) {
								try
								{
									studentID = stoi(studentIDOrName);
									studentIDOrName = peopleHandler.getTypeNameFromID(studentID, "Student");
									if (studentIDOrName == "Not found")
									{
										cout << "Student with the ID :  " << studentID << " does not exist, he can not be removed." << endl;
										cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
										peopleHandler.printAllExistingPeopleOfType(personType);
										cout << "Enter existing student ID or Name to be removed from Klass: " << endl;
										cin >> studentIDOrName;
									}
									else
									{
										Student* studentHere = peopleHandler.getStudentFromID(studentID);
										KlassArrayHere[i]->removeStudent(studentHere);
										cout << "Student with the Name :  " << studentIDOrName << " and ID: " << studentID << " has been removed from " << KlassSubject << endl;
										break;

									}

								}
								catch (const std::exception&)
								{
									cout << "You entered a non-numeric value for the ID or it was larger then 9 digits, please enter a numeric value:" << endl;
									cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
									peopleHandler.printAllExistingPeopleOfType(personType);
									cout << "Enter existing student ID or Name to remove: " << endl;
									cin >> studentIDOrName;

								}
							}
							else if (studentIDOrName == "stop" || studentIDOrName == "s") {
								break;
							}
							else {
								studentID = peopleHandler.getTypeIDFromName(studentIDOrName, "Student");
								if (studentID == -1) {
									cout << "Student with the Name :  " << studentIDOrName << " does not exist, he can not be removed." << endl;
									cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
									peopleHandler.printAllExistingPeopleOfType(personType);
									cout << "Enter existing student ID or Name to be removed from Klass: " << endl;
									cin >> studentIDOrName;
									cin.ignore();
								}
								else {
									Student* studentHere = peopleHandler.getStudentFromID(studentID);
									KlassArrayHere[i]->removeStudent(studentHere);
									cout << "Student with the Name :  " << studentIDOrName << " and ID: " << studentID << " has been removed from " << KlassSubject << endl;
									break;
								}

							}


						}
					}

				}
			}
			else if (personType == "Teacher") {
				cout << "Are you sure you want to REMOVE a Teacher from this class? Y/N  :)" << endl;
				string choice;
				getline(cin, choice);
				if (choice == "Y") {
					int teacherID;
					string teacherIDOrName;
					cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
					peopleHandler.printAllExistingPeopleOfType(personType);
					cout << "Enter existing teacher ID or Name to remove: (9 digits or less for ID)";
					cin >> teacherIDOrName;
					cin.ignore();
					while (true)
					{
						if (isdigit(teacherIDOrName[0])) {
							try
							{
								teacherID = stoi(teacherIDOrName);
								teacherIDOrName = peopleHandler.getTypeNameFromID(teacherID, "Teacher");
								if (teacherIDOrName == "Not found")
								{
									cout << "Teacher with the ID :  " << teacherID << " does not exist and can not be removed." << endl;
									cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
									cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
									peopleHandler.printAllExistingPeopleOfType(personType);
									cout << "Enter existing teacher ID or Name to be removed: " << endl;
									cin >> teacherIDOrName;
								}
								else
								{
									KlassArrayHere[i]->removeTeacher();
									cout << "Teacher with the Name :  " << teacherIDOrName << " and ID: " << teacherID << " has been removed from " << KlassSubject << endl;
									break;

								}

							}
							catch (const std::exception&)
							{
								cout << "You entered a non-numeric value for the ID or it was larger then 9 digits, please enter a numeric value:" << endl;
								cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
								cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
								peopleHandler.printAllExistingPeopleOfType(personType);
								cout << "Enter existing teacher ID or Name to be removed: " << endl;
								cin >> teacherIDOrName;

							}
						}
						else if (teacherIDOrName == "stop" || teacherIDOrName == "s") {
							break;
						}
						else {
							teacherID = peopleHandler.getTypeIDFromName(teacherIDOrName, "Teacher");
							if (teacherID == -1) {
								cout << "Teacher with the Name :  " << teacherIDOrName << " does not exist and can not be removed." << endl;
								cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
								cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
								peopleHandler.printAllExistingPeopleOfType(personType);
								cout << "Enter existing teacher ID or Name to be removed: " << endl;
								cin >> teacherIDOrName;
								cin.ignore();
							}
							else {
								KlassArrayHere[i]->removeTeacher();
								cout << "Teacher with the Name :  " << teacherIDOrName << " and ID: " << teacherID << " has been removed from " << KlassSubject << endl;
								break;
							}

						}


					}
				}
			}
			else if (personType == "Staff") {
				cout << "Are you sure you want to REMOVE Staff from this class? Y/N  :)" << endl;
				string choiceStaff;
				getline(cin, choiceStaff);
				if (choiceStaff == "Y") {
					int staffID;
					string staffIDOrName;
					cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
					peopleHandler.printAllExistingPeopleOfType(personType);
					cout << "Enter existing Staff ID or Name to remove: (9 digits or less for ID)";
					cin >> staffIDOrName;
					cin.ignore();
					while (true)
					{
						if (isdigit(staffIDOrName[0])) {
							try
							{
								staffID = stoi(staffIDOrName);
								staffIDOrName = peopleHandler.getTypeNameFromID(staffID, "Teacher");
								if (staffIDOrName == "Not found")
								{
									cout << "Staff with the ID :  " << staffID << " does not exist and can not be removed." << endl;
									cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
									cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
									peopleHandler.printAllExistingPeopleOfType(personType);
									cout << "Enter existing Staff ID or Name to remove: " << endl;
									cin >> staffIDOrName;
								}
								else
								{
									KlassArrayHere[i]->removeStaff();
									cout << "Staff with the Name :  " << staffIDOrName << " and ID: " << staffID << " has been removed from " << KlassSubject << endl;
									break;

								}

							}
							catch (const std::exception&)
							{
								cout << "You entered a non-numeric value for the ID or it was larger then 9 digits, please enter a numeric value:" << endl;
								cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
								cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
								peopleHandler.printAllExistingPeopleOfType(personType);
								cout << "Enter existing Staff ID or Name to remove: " << endl;
								cin >> staffIDOrName;

							}
						}
						else if (staffIDOrName == "stop" || staffIDOrName == "s") {
							break;
						}
						else {
							staffID = peopleHandler.getTypeIDFromName(staffIDOrName, "Staff");
							if (staffID == -1) {
								cout << "Staff with the Name :  " << staffIDOrName << " does not exist and can not be removed." << endl;
								cout << "To stop entering teacheer type \"stop\" or \"s\"." << endl;
								cout << "Heres a list of the " << personType << " to help you remember who to add: " << endl;
								peopleHandler.printAllExistingPeopleOfType(personType);
								cout << "Enter existing Staff ID or Name to remove: " << endl;
								cin >> staffIDOrName;
								cin.ignore();
							}
							else {
								KlassArrayHere[i]->removeStaff();
								cout << "Staff with the Name :  " << staffIDOrName << " and ID: " << staffID << " has been removed from " << KlassSubject << endl;
								break;
							}

						}


					}
				}
			}
			break;
		}


	}

}

Klass* KlassHandler::getKlassFromSubject(string subject) {
	for (int i = 0; i < nrOf; i++) {
		if (KlassArrayHere[i]->getSubject() == subject) {
			return KlassArrayHere[i];
		}
	}
	return nullptr;
};

void KlassHandler::printAllSubjects() {
	cout << "Heres a list of the Klasses Subjects to help you remember: " << endl;
	for (int i = 0; i < nrOf; i++)
	{
		cout << KlassArrayHere[i]->getSubject() << endl;
	}
};

void KlassHandler::handleKlasses() {

	bool breakPlease = peopleHandler.handlePeople();
	if (breakPlease)
	{
		return;
	}

	load();
	bool running = true;
	while (running) {
		cout << endl;
		cout << "\n\t\t--------------------------------";
		cout << "\n\t\t***   !    Klass Menu    !   ***";
		cout << "\n\t\t--------------------------------" << endl;
		cout << "1. Add a FULL Klass (must imput correct studnets teacher and staff)" << endl;// have
		cout << "2. Add a Klass (only needs Room number and Subject title)" << endl;// have
		cout << "3. Add people to a Klass" << endl;
		cout << "4. Remove people from a klass" << endl;
		cout << "5. Klass statistics :)" << endl;
		cout << "6. Update Klass" << endl;// have
		cout << "7. Find People in a Klass" << endl;// have"
		cout << "8. Remove Klass" << endl;// have
		cout << "9. Show contents of One Klass" << endl;// have"
		cout << "10. Show All Klasses" << endl;// have
		cout << "11. Save and exit back to main menu " << endl;
		cout << "12. Save and exit the program" << endl << endl << endl; // have
		int choice;
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 1:// DONE ---------------------------------------------------
			addFullKlass();// DONE ---------------------------------------------------
			break;// DONE ---------------------------------------------------
		case 2:// DONE ---------------------------------------------------
			addKlassJustRoomCodeAndSubject();// DONE ---------------------------------------------------
			break;// DONE ---------------------------------------------------
		case 3:
		{// DONE ---------------------------------------------------
			//add people to a klass Menu option for who
			cout << "Who would you like to add to the Klass?" << endl;
			cout << "1. Student" << endl;// DONE ---------------------------------------------------
			cout << "2. Teacher" << endl;
			cout << "3. Staff" << endl;// DONE ---------------------------------------------------
			int choice2;
			try
			{// DONE ---------------------------------------------------
				cin >> choice2;// DONE ---------------------------------------------------
				cin.ignore();

			}// DONE ---------------------------------------------------
			catch (const std::exception&)
			{
				cout << "You must enter a number, try again later." << endl;// DONE ---------------------------------------------------
			}
			switch (choice2) {// DONE ---------------------------------------------------
			case 1:
				addPersonToKlass("Student");
				break;
			case 2:
				addPersonToKlass("Teacher");// DONE ---------------------------------------------------
				break;
			case 3:
				addPersonToKlass("Staff");
				break;// DONE ---------------------------------------------------
			}
			break;// DONE ---------------------------------------------------
		}
		case 4: {
			//add people to a klass Menu option for who
			cout << "Who would you like to REMOVE from the Klass?" << endl;
			cout << "1. Student" << endl;// DONE ---------------------------------------------------
			cout << "2. Teacher" << endl;
			cout << "3. Staff" << endl;// DONE ---------------------------------------------------
			int PersonChoice;
			string SubjectHere;
			try
			{// DONE ---------------------------------------------------
				cin >> PersonChoice;// DONE ---------------------------------------------------
				cin.ignore();

			}// DONE ---------------------------------------------------
			catch (const std::exception&)
			{
				cout << "You must enter a number, try again later." << endl;// DONE ---------------------------------------------------
			}

			cout << "Enter subject of Klass: " << endl;;
			cin >> SubjectHere;

			switch (PersonChoice) {// DONE ---------------------------------------------------
			case 1:
				removePersonFromKlass("Student", SubjectHere);
				break;
			case 2:
				removePersonFromKlass("Teacher", SubjectHere);// DONE ---------------------------------------------------
				break;
			case 3:
				removePersonFromKlass("Staff", SubjectHere);
				break;// DONE ---------------------------------------------------
			}
			break;// DONE ---------------------------------------------------
		}
		case 5: {
			cout << "Klass statistics :)" << endl;
			cout << "1. Show total age in a klass" << endl;
			cout << "2. Show average age in a klass" << endl;
			cout << "3. Show total number of Students in a klass" << endl;
			cout << "4. Show total number of People in a klass" << endl;// DONE ---------------------------------------------------"
			//Klass statistics Menu option for who
			int ChoiceAgain;
			try
			{
				cin >> ChoiceAgain;
				cin.ignore();

			}
			catch (const std::exception&)
			{
				cout << "You must enter a number, try again later." << endl;
			}
			switch (ChoiceAgain) {
			case 1: {
				printAllSubjects();
				cout << "Enter the subject of the Klass you want to see the total age of: " << endl;
				string subject;
				cin >> subject;
				Klass* KlassHere = getKlassFromSubject(subject);
				cout << "The total age of the Klass is: " << getTotalAgeInKlass(KlassHere) << endl;
				break; }
			case 2: {
				printAllSubjects();
				cout << "Enter the subject of the Klass you want to see the average age of: " << endl;
				string subject2;
				cin >> subject2;
				Klass* KlassHere = getKlassFromSubject(subject2);
				cout << "The average age of the Klass is: " << getAverageAgeInKlass(KlassHere) << endl;
				break; }
			case 3: {
				printAllSubjects();
				cout << "Enter the subject of the Klass you want to see the total number of Students in: " << endl;
				string subject3;
				cin >> subject3;
				cout << "The total number of Students in the Klass is: ";
				for (int i = 0; i < nrOf; i++)
				{
					if (KlassArrayHere[i]->getSubject() == subject3)
					{
						cout << KlassArrayHere[i]->getNrOfStudents() << endl;
						break;
					}

				}
				break; }
			case 4: {
				printAllSubjects();
				cout << "Enter the subject of the Klass you want to see the total number of People in: " << endl;
				string subject4;
				cin >> subject4;
				cout << "The total number of People in the Klass is: " << getSumPeopleTotalInKlass(subject4) << endl;
				break;
			}
			}


			break;
		}
		case 6: {
			//Update Klass
			updateKlass();// DONE ---------------------------------------------------

			break;
		}
		case 7: {
			//Find People in a Klass
			cout << "Enter the name or ID of the person you want to find in a Klass: " << endl;// DONE ---------------------------------------------------
			string personNameOrID;
			cin >> personNameOrID;
			cout << personNameOrID << " is in " << findWHatKlassPersonIsFromNameOrIDWithoutPersonType(personNameOrID) << " Klass!!!" << endl;// DONE ---------------------------------------------------
			break;
		}
		case 8:// DONE ---------------------------------------------------
			removeKlass();// DONE ---------------------------------------------------
			break;// DONE ---------------------------------------------------
		case 9: {
			printAllSubjects();
			cout << "Enter the name of the Klass you want to see: " << endl;
			string klassName;
			cin >> klassName;
			printKlass(klassName);
			break; }
		case 10:// DONE ---------------------------------------------------
			printAllKlasses();// DONE ---------------------------------------------------
			break;// DONE ---------------------------------------------------
		case 11:
			//save and return to main men u people stufdf
			save();
			handleKlasses();
			running = false;
			break;
		case 12:
			save();
			cout << endl << endl << endl << "Bye Bye!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl << endl << endl << endl;
			running = false;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	}
}
