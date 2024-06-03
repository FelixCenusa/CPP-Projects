#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <string>
#include <vector>
#include <memory>
using namespace std;
#include "peoplehandler.h"
#include "person.h"
#include "Teacher.h"
#include "staff.h"
#include "student.h"
#include "klasshandler.h"

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    KlassHandler klassBeingHandled;
    klassBeingHandled.handleKlasses();
    //Fully works tested
    //No errors at all 0 debug return.
    //This is the final version of the program.

    return 0;
}