#include "PeopleHandler.h"


void PeopleHandler::writeToTextFile(const string& filename) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (const auto& person : people) {
        person->writeDataToStream(outFile);
        outFile << endl;
    }

    outFile.close();
}

void PeopleHandler::readFromTextFile(const string& filename) {
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    people.clear();

    while (inFile) {
        char personType;
        int personID;
        string name;
        int age;
        string specs;

        while (inFile >> personType >> personID >> name >> age >> specs) {

            if (personType == 'S') {
                unique_ptr<Student> newStudent = nullptr;
                newStudent = make_unique<Student>();
                newStudent->setName(name);
                newStudent->setAge(age);
                newStudent->setID(personID);
                newStudent->setStudyField(specs);
                people.push_back(move(newStudent));
            }
            else if (personType == 'T') {
                unique_ptr<Teacher> newTeacher = nullptr;
                newTeacher = make_unique<Teacher>();
                newTeacher->setName(name);
                newTeacher->setAge(age);
                newTeacher->setID(personID);
                newTeacher->setTeachingSubject(specs);
                people.push_back(move(newTeacher));
            }
            else if (personType == 'F') {
                unique_ptr<Staff> newStaff = nullptr;
                newStaff = make_unique<Staff>();
                newStaff->setName(name);
                newStaff->setAge(age);
                newStaff->setID(personID);
                newStaff->setRole(specs);
                people.push_back(move(newStaff));
            }



        }

    }

    inFile.close();
}

PeopleHandler::PeopleHandler() {
    readFromTextFile("people.txt");
}

void PeopleHandler::addNewStudent() {
    int studentID, age;
    string name, studyField;

    while (true) {
        cout << "Enter the students ID  (only numbers)    : ";
        if (cin >> studentID) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (const auto& person : people) {
        const Student* student = dynamic_cast<const Student*>(person.get());
        if (student && student->getID() == studentID) {
            cout << "\t\tStudent Already Exists" << endl;
            return;
        }
    }

    cout << "Enter Name        : ";
    cin.ignore();
    getline(cin, name);



    while (true) {
        cout << "Enter Age  : ";
        if (cin >> age) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Enter Study Field : ";
    cin.ignore();
    getline(cin, studyField);

    auto newStudent = make_unique<Student>(studentID, name, age, studyField);
    people.push_back(move(newStudent));

    writeToTextFile("people.txt");
}

void PeopleHandler::addNewTeacher() {
    int teacherID, age;
    string name, teachingSubject;

    while (true) {
        cout << "Enter Employee ID (only numbers)     : ";
        if (cin >> teacherID) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (const auto& person : people) {
        const Teacher* teacher = dynamic_cast<const Teacher*>(person.get());
        if (teacher && teacher->getID() == teacherID) {
            cout << "\t\tTeacher Already Exists" << endl;
            return;
        }
    }

    cout << "Enter Name            : ";
    cin.ignore();
    getline(cin, name);

    while (true) {
        cout << "Enter Age     : ";
        if (cin >> age) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Enter Teaching Subject : ";
    cin.ignore();
    getline(cin, teachingSubject);

    auto newTeacher = make_unique<Teacher>(teacherID, name, age, teachingSubject);
    people.push_back(move(newTeacher));

    writeToTextFile("people.txt");
}

void PeopleHandler::addNewStaff() {
    int staffID, age;
    string name, role;

    while (true) {
        cout << "Enter Staff ID  (only numbers)  : ";
        if (cin >> staffID) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (const auto& person : people) {
        const Staff* staff = dynamic_cast<const Staff*>(person.get());
        if (staff && staff->getID() == staffID) {
            cout << "\t\tStaff Member Already Exists" << endl;
            return;
        }
    }

    cout << "Enter Name     : ";
    cin.ignore();
    getline(cin, name);

    while (true) {
        cout << "Enter Age    : ";
        if (cin >> age) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Enter Role of the staff     : ";
    cin.ignore();
    getline(cin, role);

    auto newStaff = make_unique<Staff>(staffID, name, age, role);
    people.push_back(move(newStaff));

    writeToTextFile("people.txt");
}

void PeopleHandler::displayAllPeople() const {
    if (people.empty()) {
        cout << "\t\t No People Found " << endl;
    }


    for (const auto& person : people) {
        if (person->getAge() != 0)
        {
            person->displayPerson();
            cout << endl;
        }
    }
}

void PeopleHandler::printAllExistingPeopleOfType(string type) const {
    if (people.empty()) {
        cout << "\t\t No People Found " << endl;
    }

    for (const auto& person : people) {
        if (person->getType() == type) {
            if (person->getAge() != 0)
            {
                person->displayPerson();
                cout << endl;

            }
        }
    }
}

void PeopleHandler::searchPerson() const {
    int id;
    cout << "Enter ID to Search : ";
    cin >> id;

    for (const auto& person : people) {
        if (person->getID() == id) {
            person->displayPerson();
            return;
        }
    }

    cout << "\t\tPerson Not Found" << endl;
}

void PeopleHandler::updatePerson() {
    int ID;
    cout << "\t\tEnter ID to Update Record : ";
    cin >> ID;

    auto it = find_if(people.begin(), people.end(), [ID](const auto& person) {
        return person->getID() == ID;
        });

    if (it != people.end()) {
        (*it)->displayPerson();

        cout << "\t\tChoose attribute to update:" << endl;
        cout << "\t\t 1. Name" << endl;
        cout << "\t\t 2. Age" << endl;
        cout << "\t\t 3. Update Specific Details" << endl;
        cout << "\t\tEnter Your Choice : ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            cout << "\t\tEnter New Name :";
            cin.ignore();
            getline(cin, name);
            (*it)->setName(name);
            break;
        }
        case 2: {
            int age;
            while (true) {
                cout << "\t\tEnter New Age :";
                if (cin >> age) {
                    break;
                }
                else {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            (*it)->setAge(age);
            break;
        }
        case 3: {
            // Dynamically check the type using dynamic_cast
            if (auto student = dynamic_cast<Student*>(it->get())) {
                string StudyField;
                cout << "\t\tEnter New program :";
                cin.ignore();
                getline(cin, StudyField);
                student->setStudyField(StudyField);
            }
            else if (auto teacher = dynamic_cast<Teacher*>(it->get())) {
                string newTeachingSubject;
                cout << "\t\tEnter New Teaching Subject :";
                cin.ignore();
                getline(cin, newTeachingSubject);
                teacher->setTeachingSubject(newTeachingSubject);
            }
            else if (auto staff = dynamic_cast<Staff*>(it->get())) {
                string newRole;
                cout << "\t\tEnter New Role  : ";
                cin.ignore();
                getline(cin, newRole);
                staff->setRole(newRole);
            }
            else {
                cout << "\t\tInvalid Person Type" << endl;
            }
            break;
        }
        default:
            cout << "\t\tInvalid Number" << endl;
        }

        writeToTextFile("people.txt");
    }
    else {
        cout << "\t\tPerson Not Found" << endl;
    }
}

void PeopleHandler::deletePerson() {
    int ID;
    while (true) {
        cout << "\t\tEnter ID to Delete : ";
        if (cin >> ID) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    auto it = remove_if(people.begin(), people.end(), [ID](const auto& person) {
        return person->getID() == ID;
        });

    if (it != people.end()) {
        people.erase(it, people.end());
        cout << "\t\tPerson Removed Successfully" << endl;
        writeToTextFile("people.txt");
    }
    else {
        cout << "\t\tPerson Not Found" << endl;
    }
}

int PeopleHandler::countPeopleOfType(const string& type) const {
    int count = 0;
    for (const auto& person : people) {
        if (person->getType() == type) {
            if (person->getAge() != 0)
            {
                count++;

            }
        }
    }
    return count;
}

int PeopleHandler::ageOfPeopleOfType(const string& type) const {
    int count = 0;
    for (const auto& person : people) {
        if (person->getType() == type) {
            count += person->getAge();
        }
    }
    return count;
}

int PeopleHandler::getAgeFromID(int id) const {
    for (const auto& person : people) {
        if (person->getID() == id) {
            return person->getAge();
        }
    }
    return -1;
}

string PeopleHandler::getNameFromID(int id) const {
    for (const auto& person : people) {
        if (person->getID() == id) {
            return person->getName();
        }
    }
    return "Not found";
}

string PeopleHandler::getTypeNameFromID(int id, string type) const {
    for (const auto& person : people) {
        if (person->getID() == id) {
            if (person->getType() == type) {
                return person->getName();
            }
        }
    }
    return "Not found";
}

int PeopleHandler::getIDFromName(string name) const {
    for (const auto& person : people) {
        if (person->getName() == name) {
            return person->getID();
        }
    }
    return -1;
}

int PeopleHandler::getTypeIDFromName(string name, string type) const {
    for (const auto& person : people) {
        if (person->getName() == name) {
            if (person->getType() == type) {
                return person->getID();
            }
        }
    }
    return -1;
}

int PeopleHandler::totalAgeStudents() const {
    return ageOfPeopleOfType("Student");
}

int PeopleHandler::totalAgeTeachers() const {
    return ageOfPeopleOfType("Teacher");
}

int PeopleHandler::totalAgeStaff() const {
    return ageOfPeopleOfType("Staff");
}

int PeopleHandler::totalAgeTotalPeople() const {
    int count = 0;
    for (const auto& person : people) {
        count += person->getAge();
    }
    return count;
}

float PeopleHandler::averageAgeOfPeople() const {
    float count = 0;
    float avg = 0;
    for (const auto& person : people) {
        count += person->getAge();
        avg++;
    }
    count = count / avg;
    return count;
}

int PeopleHandler::countStudents() const {
    return countPeopleOfType("Student");
}

int PeopleHandler::countTeachers() const {
    return countPeopleOfType("Teacher");
}

int PeopleHandler::countStaff() const {
    return countPeopleOfType("Staff");
}

int PeopleHandler::countTotalPeople() const {
    return people.size() - 2;
}

bool PeopleHandler::handlePeople() {
    bool choice = true;


    while (choice) {
        int op;

        cout << "\n\t\t--------------------------------";
        cout << "\n\t\t*** School Management System ***";
        cout << "\n\t\t--------------------------------";
        cout << "\n\t\t 1. Add New Student " << endl;
        cout << "\t\t 2. Add New Teacher " << endl;
        cout << "\t\t 3. Add New Staff " << endl;
        cout << "\t\t 4. Display All People " << endl;
        cout << "\t\t 5. Search Person " << endl;
        cout << "\t\t 6. Update Person " << endl;
        cout << "\t\t 7. Delete Person " << endl;
        cout << "\t\t 8. Count Students " << endl;
        cout << "\t\t 9. Count Teachers " << endl;
        cout << "\t\t 10. Count Staff " << endl;
        cout << "\t\t 11. Count Total People " << endl;
        cout << "\t\t 12. Count Total Age Of Students " << endl;
        cout << "\t\t 13. Count Total Age Of Teachers " << endl;
        cout << "\t\t 14. Count Total Age Of Staff " << endl;
        cout << "\t\t 15. Count Total Age Of All People " << endl;
        cout << "\t\t 16. Average Age Of People " << endl;
        cout << "\t\t 17. Exit People choices and enter Klass choices" << endl;
        cout << "\t\t 18. Exit" << endl;// Change to exit fully.
        cout << "\t\t Enter Your Choice : ";

        cin >> op;

        if (cin.fail()) {
            cout << "\t\tInvalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (op) {
        case 1:
            addNewStudent();
            break;
        case 2:
            addNewTeacher();
            break;
        case 3:
            addNewStaff();
            break;
        case 4:
            displayAllPeople();
            break;
        case 5:
            searchPerson();
            break;
        case 6:
            updatePerson();
            break;
        case 7:
            deletePerson();
            break;
        case 8:
            cout << "\t\tTotal Students: " << countStudents() << " students." << endl;
            break;
        case 9:
            cout << "\t\tTotal Teachers: " << countTeachers() << " teachers." << endl;
            break;
        case 10:
            cout << "\t\tTotal Staff: " << countStaff() << " staff." << endl;
            break;
        case 11:
            cout << "\t\tTotal People in the school system: " << countTotalPeople() << " people." << endl;
            break;
        case 12:
            cout << "\t\tTotal Age Of Students: " << totalAgeStudents() << " years old." << endl;
            break;
        case 13:
            cout << "\t\tTotal Age Of Teachers: " << totalAgeTeachers() << " years old." << endl;
            break;
        case 14:
            cout << "\t\tTotal Age Of Staff: " << totalAgeStaff() << " years old." << endl;
            break;
        case 15:
            cout << "\t\tTotal Age Of People: " << totalAgeTotalPeople() << " years old." << endl;
            break;
        case 16:
            cout << "\t\tAverage Age Of People: " << averageAgeOfPeople() << " years old." << endl;
            break;
        case 17:

            choice = false;
            return false;
        case 18:

            choice = false;
            cout << endl << endl << endl << "Bye Bye!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl << endl << endl << endl;
            return true;
        default:
            cout << "\t\tInvalid Choice. Please enter a valid option.\n";
        }


    }
}

Teacher* PeopleHandler::getTeacherFromID(int id) {
	for (const auto& person : people) {
		if (person->getID() == id) {
			if (person->getType() == "Teacher") {
				return dynamic_cast<Teacher*>(person.get()); 
			}
		}
	}
};

Student* PeopleHandler::getStudentFromID(int id) {
	for (const auto& person : people) {
		if (person->getID() == id) {
			if (person->getType() == "Student") {
				return dynamic_cast<Student*>(person.get());
			}
		}
	}
};

Staff* PeopleHandler::getStaffFromID(int id) {
	for (const auto& person : people) {
		if (person->getID() == id) {
			if (person->getType() == "Staff") {
				return dynamic_cast<Staff*>(person.get());
			}
		}
	}
};
