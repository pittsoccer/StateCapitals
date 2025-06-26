
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// constants
const int NUM_ELEMENTS = 100;

// function prototypes
int linearSearch(const string data[], int numElements, string stateKey);

int main() {
    string capital[NUM_ELEMENTS] = {};
    string state[NUM_ELEMENTS] = {};
    string stateKey = "";
    int position = 0;
    char choice = 'y';
    ifstream inFile;

    // open file
    inFile.open("states.txt");

    // assign states to array
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        getline(inFile, state[i]);
        getline(inFile, capital[i]);
    }


    while (choice == 'y' || choice == 'Y') {
        // input state
        cout << "Enter state: ";
        getline(cin, stateKey);

        // calculate position
        position = linearSearch(state, NUM_ELEMENTS, stateKey);

        // find state positon & capital
        if (position == -1) {
            cout << "State not found" << endl;
        }
        else {
            cout << "Capital is: " << capital[position] << endl;
        }

        // ask the user if they want to continue
        cout << endl;
        cout << "Do you want to lookup another state? (y/n): ";
        cin >> choice;
        cout << endl;

        cin.ignore();
    }

    return 0;
}


/********************************************************************
Name:       linearSearch
Purpose:    searches through an array for a key
Incoming:   data[] (string) - array of item quantities
            numElements (int) - number of elements
            stateKey (string) - key to find state
Outgoing:   N/A
Returns:    spot or -1
********************************************************************/
int linearSearch(const string data[], int numElements, string stateKey) {
    int spot = 0;
    bool found = false;

    while (!found && (spot < numElements)) {
        // find spot
        if (data[spot] == stateKey) {
            found = true;
        }
        else {
            spot++;
        }
    }

    // return spot
    if (found) {
        return spot;
    }
    else {
        return -1;
    }
}
