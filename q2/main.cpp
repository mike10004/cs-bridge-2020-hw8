// mac937@nyu.edu
// hw8 question 2

#include <iostream>
#include <string>

using namespace std;

// Converts simple lower case letters to upper case.
// Only modifies characters in the range [a, z]. 
// Returns any other argument unchanged.
char toUpperCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return static_cast<char>(ch - ('a' - 'A'));
    }
    return ch;
}

// Checks whether a string is a palindrome, case-insensitively
// Behavior may not be what you want if string contains non-letters such 
// as spaces or apostrophes, or letters with diacritic marks.
bool isPalindrome(const string& str) {
    int length = str.length();
    for (int i = 0; i < length / 2; i++) {
        if (toUpperCase(str[i]) != toUpperCase(str[length - i - 1])) {
            return false;
        }
    }
    return true;
}

// Asks for single word and reports whether it's a palindrome.
int main() {
    string word;
    cout << "Please enter a word: ";
    cin >> word;
    cout << word << " is ";
    if (!isPalindrome(word)) {
        cout << "not ";
    }
    cout << "a palindrome" << endl;
    return 0;
}
