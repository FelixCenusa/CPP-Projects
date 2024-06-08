#include <iostream>
#include <string>
using namespace std;

int minimumTests(int maximumTests) {
    int low = 1;
    int high = maximumTests - 1;
    int tests = 0;
    while (low <= high) {
        int mid = (high + low) / 2;
        low = mid + 1;
        tests++;
    }
    return tests;
}

int main() {
    int input;
    bool first = true;
    while (true)
    {
		cin >> input;
        if (input == 0) {
			break;
		}
        if (!first)
        {
            cout << "\n";
        }
        first = false;
        cout << minimumTests(input);

    }
    return 0;
}