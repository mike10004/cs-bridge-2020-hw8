// mac937@nyu.edu
// hw8 question 5

#include <iostream>
#include <string>

using namespace std;

// "Initialifies" a name by truncating it to its first letter and 
// adding a period.
void initialify(string& name) {
    char initial[] = "_";
    if (!name.empty()) {
        initial[0] = name[0];
        name.assign(initial);
    }
    if (name[name.length() - 1] != '.') {
        name.append(".");
    }
}

// Ask for a name, e.g. "Mary Average User", and prints it in the 
// form "User, Mary A."
int main() {
    string firstName, middleName, lastName;
    cout << "Enter full name: ";
    cin >> firstName >> middleName >> lastName;
    initialify(middleName);
    cout << lastName << ", " 
         << firstName << ' '
         << middleName << endl;
    return 0;
}
