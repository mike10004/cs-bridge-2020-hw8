#pragma clang diagnostic push                    // stage: cut 
#pragma ide diagnostic ignored "cert-msc32-c"    // stage: cut
#pragma ide diagnostic ignored "cert-msc30-c"    // stage: cut
// mac937@nyu.edu
// hw8 question 4

#include <iostream>
#include <cstdlib>

using namespace std;

const int PIN[] = {2, 5, 7, 8, 5};
const int PIN_LENGTH = 5;
const int DIGITS[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const int NUM_DIGITS = 10;
const int SUB_MIN = 1;
const int SUB_MAX = 3;

void generateAndPrintKey(const int pin[], int pinLength, int pinSubs[], int numDigits) {
    for (int i = 0; i < numDigits; i++) {
        int randomNumber = (rand() % (SUB_MAX - SUB_MIN + 1)) + SUB_MIN;
        cout << randomNumber << ' ';
        for (int j = 0; j < pinLength; j++) {
            if (pin[j] == i) {
                pinSubs[j] = randomNumber; 
            }
        }
    }
    cout << endl;
}

void printArray(const int values[], int length) {
    for (int i = 0; i < length; i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << values[i];
    }
}

int main() {
    int pinSubs[PIN_LENGTH];
    srand(time(nullptr));
    cout << "PIN: ";
    printArray(DIGITS, NUM_DIGITS);
    cout << endl;
    cout << "NUM: ";
    generateAndPrintKey(PIN, PIN_LENGTH, pinSubs, NUM_DIGITS);
    bool pinWrong = false;
    for (int pinSub : pinSubs) {
        char pinEntryChar;
        cin >> pinEntryChar;
        int pinEntryDigit = pinEntryChar - '0';
        if (pinSub != pinEntryDigit) {
            pinWrong = true;
            // accept the rest of the PIN even though it's already wrong
        }
    }
    cout << "Your PIN is ";
    if (pinWrong) {
        cout << "not ";
    }
    cout << "correct" << endl;
    return 0;
}

#pragma clang diagnostic pop            // stage: cut
