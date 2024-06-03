#include <fstream>
#include <iostream>
#include "ToDo.h"

using namespace std;

void exchange(int &numberOne, int &numberTwo)
{
    cout << numberOne << "first left second right" << numberTwo << endl;
    int first = numberOne;
    cout << first << "first" << endl;

    int second = numberTwo;
    cout << second  << "second" << endl;

    int *memOne = &numberOne;
    cout << memOne << "memOne" << endl;

    int* memTwo = &numberTwo;
    cout << memTwo << "memTwo" << endl;

    int *temp = memOne;
    cout << temp << endl;

    *memOne = second;
    cout << memOne << endl;

    *memTwo = first;
    cout << memTwo << endl;

    cout << numberOne << "first left second right" << numberTwo << endl;
    //FINALLLLLLLLLLYYYYYYYY

}

int findBiggest(int arr[], int cap)
{
    int biggestCurrently = 0;
    int counter = 0;
    int temp = 0;
    int indexBiggest = 0;
    while (true) {
        if (counter < cap) {
            temp = arr[counter];
            cout << temp << endl;
            if (temp > biggestCurrently) {
                biggestCurrently = temp;
                indexBiggest = counter;
            }
            
            counter++;
        }
        else {
            break;
        }
        
    }
    cout << indexBiggest << "biggest index" << endl;
    return indexBiggest;
    //works next.
}

bool readStringsFromFile(string fileName, string strs[], int cap)
{
    bool ok = false;
    ifstream name(fileName);
    if (name.is_open()) {
        ok = true;
        int counter = 0;
        string temp = "";
        cout << "cap" << cap << endl;
        while (counter < cap) {
            getline(name, temp);
            cout << "temp " << temp << endl;
            strs[counter] = temp;
            cout << "strsCounter " << strs[counter] << endl;
            counter++;
            
        }
        
    }


    return ok;
}


