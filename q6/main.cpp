// mac937@nyu.edu
// hw8 question 6

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

const int MAX_LINE_LENGTH = 1024;

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isLetterOrDigit(char ch) {
    return isLetter(ch) || isDigit(ch);
}

// Checks whether a substring of a line  is only digits.
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

// Finds how many characters until the next space or end of string position
int findNextBoundary(const string& line, int start) {
    int pos = start;
    while (pos < line.length() && isLetterOrDigit(line[pos])) {
        pos++;
    }
    return pos - start;
}

// Returns a char from the string or the obfuscator, as specified by the `obfuscate` flag.
char getOutputChar(const string& line, int index, bool obfuscate, char obfuscator) {
    if (obfuscate) {
        return obfuscator;
    } else {
        return line[index];
    }
}

void printObfuscated(const string& line, char obfuscator) {
    int pos = 0;
    while (pos < line.length()) {
        if (isLetterOrDigit(line[pos])) {
            int runLength = findNextBoundary(line, pos);
            bool onlyDigits = isOnlyDigits(line, pos, runLength);
            for (int i = pos; i < (pos + runLength); i++) {
                cout << getOutputChar(line, i, onlyDigits, obfuscator);
            }
            pos += runLength;
        } else {
            cout << line[pos];
            pos++;
        }
    }
}

int main() {
    char input[MAX_LINE_LENGTH];
    cout << "Please enter a line of text:" << endl;
    cin.getline(input, MAX_LINE_LENGTH);
    string line(input);
    printObfuscated(line, 'x');
    cout << endl;
    return 0;
}
