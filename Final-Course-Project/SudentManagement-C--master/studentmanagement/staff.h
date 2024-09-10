#pragma once
#include "person.h"
class Staff : public Person {
private:
    string role;

public:
    Staff() = default;

    Staff(int staffID, string sName, int sAge, string sRole);

    void displayPerson() const override;

    void readDataFromStream(istream& is) override;

    void writeDataToStream(ostream& os) const override;


    string getType() const override;

    string getRole() const;

    void setRole(string& newRole);


    void updatePerson() override;
};