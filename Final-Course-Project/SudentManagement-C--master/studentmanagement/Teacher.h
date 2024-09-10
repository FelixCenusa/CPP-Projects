#pragma once
#include "person.h"
class Teacher : public Person {
private:
    string teachingSubject;

public:
    Teacher() = default;

    Teacher(int teacherID, string empName, int empAge, string empTeachingSubject);


    void setTeachingSubject(string subject);

    string getTeachingSubject() const;

    void displayPerson() const override;

    void readDataFromStream(istream& is) override;

    void writeDataToStream(ostream& os) const override;


    string getType() const override;


    void updatePerson() override;
};