// mac937@nyu.edu
// hw8 question 6

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

const int MAX_LINE_LENGTH = 1024;

// Returns true if and only if a character is a digit.
bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

// Returns true if and only if a character is an English letter.
bool isLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

// Returns true if and only if a charater is a letter or digit.
bool isLetterOrDigit(char ch) {
    return isLetter(ch) || isDigit(ch);
}

// Checks whether a region of a line is only digits.
bool isOnlyDigits(const string& line, int start, int length) {
    assert(line.length() >= (start + length));
    bool hasNonDigit = false;
    for (int i = start; i < (start + length) && !hasNonDigit; i++) {
        if (!isDigit(line[i])) {
            hasNonDigit = true;
        }
    }
    return !hasNonDigit;
}

// Finds how many characters until the next space or end of string.
int findNextBoundary(const string& line, int start) {
    assert(start < line.length());
    int pos = start;
    while (pos < line.length() && isLetterOrDigit(line[pos])) {
        pos++;
    }
    return pos - start;
}

// Prints a line with all-digit words obfuscated.
void printObfuscated(const string& line, char obfuscator) {
    int pos = 0;
    while (pos < line.length()) {
        if (isLetterOrDigit(line[pos])) {
            int runLength = findNextBoundary(line, pos);
            bool onlyDigits = isOnlyDigits(line, pos, runLength);
            for (int i = pos; i < (pos + runLength); i++) {
                if (onlyDigits) {
                    cout << obfuscator;
                } else {
                    cout << line[i];
                }
            }
            pos += runLength;
        } else {
            cout << line[pos];
            pos++;
        }
    }
}

// Prompts user for a line of text and prints the line with all-digit
// words obfuscated.
int main() {
    char input[MAX_LINE_LENGTH];
    cout << "Please enter a line of text:" << endl;
    cin.getline(input, MAX_LINE_LENGTH);
    string line(input);
    printObfuscated(line, 'x');
    cout << endl;
    return 0;
}
