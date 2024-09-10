#pragma once
#include "person.h"
class Student : public Person {
private:
    string studyField;

public:
    Student() = default;

    Student(int studentID, string stdName, int stdAge, string stdStudyField);


    void setStudyField(string field);

    string getStudyField() const;

    void displayPerson() const override;

    void readDataFromStream(istream& is) override;

    void writeDataToStream(ostream& os) const override;



    string getType() const override;

    void updatePerson() override;
};