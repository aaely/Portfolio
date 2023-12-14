#include <fstream>
#include "functions.h"

ProduceItem::ProduceItem(string n) {
    name = n;
    occurance = 1;
}

int main() {

    ifstream inFS;
    ofstream outFile;
    string itemName;
    vector<ProduceItem> items;

    /// opening the infile 
    cout << "Opening file CS210_Project_Three_Input_File.txt" << endl;
    inFS.open("CS210_Project_Three_Input_File.txt");

    /// if fail to open, end program with error
    if (!inFS.is_open()) {
      cout << "Could not open file numFile.txt." << endl;
      return 1;
    }

    /// look through infile data until end of file and if file data is still good
    while (!inFS.eof() && inFS.good()) {
        bool found = false;
        inFS >> itemName;
        /// if vector has items, check to see if item is in vector and increment if found
        if (items.size() > 0) {
            for(int i = 0; i < (int(items.size())); i++) {
                if (items.at(i).GetName() == itemName) {
                    items.at(i).SetOccurance(items.at(i).GetOccurance() + 1);
                    found = true;
                }
            }
        }
        /// if empty, push item into vector
        if (items.size() == 0) {
            found = true;
            ProduceItem item(itemName);
            items.push_back(item);
        }
        /// if item not found in vector, push to vector
        if (found == false) {
            ProduceItem item(itemName);
            items.push_back(item);
        }
    }

    int option;
    /// loop through menu until quit is called
    do {
        PrintMenu();
        option = get_option();
        ExecuteMenu(option, items);
    } while (option != 4);

    return 0;
}