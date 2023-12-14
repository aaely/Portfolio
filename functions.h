#include <iostream>
#include <vector>
#include <limits>
#include <cctype>
#include <algorithm>
#include "ProduceItem.h"


/// @brief
/// loop that continues until the correct input is received for an option
/// @return 
int get_option() {
    int option;
    for (;;) {
        cout << "Enter option:\n";
        if (cin >> option && option > 0 && option < 5) {
            break;
        } else {
            cout << "Please enter a valid option" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return option;
}

// Function to convert a string to lowercase
string toLowerString(const std::string& s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
        return tolower(c);
    });
    return result;
}

/// @brief
/// loops through items vector until the name is found
/// @return 
int FindItemOccurance(string n, vector<ProduceItem>& items) {
    for(int i = 0; i < (int (items.size())); i++) {
        if (toLowerString(n) == toLowerString(items.at(i).GetName())) {
            return items.at(i).GetOccurance();
        }
    }
    return 0;
}

/// @brief 
/// prints menu options to user
void PrintMenu() {
    cout << "MENU" << endl;
    cout << "1 - Search for item by name" << endl;
    cout << "2 - Print all items and their occurances" << endl;
    cout << "3 - Print all items and their occurances by histogram" << endl;
    cout << "4 - Quit" << endl;
    cout << endl;
}

/// @brief 
/// Takes in items vector and loops through and prints out the name and occurance number
/// @param items 
void PrintAllItems(vector<ProduceItem>& items) {
    for(int i = 0; i < (int (items.size())); i++) {
        cout << items.at(i).GetName() << " " << items.at(i).GetOccurance() << endl;
    }
}

/// @brief 
/// Takes in items vector and loops through and prints out a * for each occurance
/// @param items 
void PrintHistogram(vector<ProduceItem>& items) {
    for(int i = 0; i < (int (items.size())); i++) {
        cout << items.at(i).GetName() << " ";
        for(int j = 0; j < (int (items.at(i).GetOccurance())); j++) {
            cout << "*";
        }
        cout << endl;
    }
}

/// @brief 
/// takes in the option and the items vector and determines what action to take
/// @param items 
void ExecuteMenu(int option, vector<ProduceItem>& items) {
    string name;
    switch (option) {
        case 1: {
            cout << "Enter the name of the item to look up" << endl;
            cin >> name;
            int i = FindItemOccurance(name, items);
            if (i < 1) {
                cout << "Item not found." << endl;
            } else {
                cout << name << " " << i << endl;
            }
            break;
        }
        case 2: {
            PrintAllItems(items);
            break;
        }
        case 3: {
            PrintHistogram(items);
            break;
        }
        default: break;
    }
}

