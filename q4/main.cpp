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

void generateAndPrintSubs(const int pin[], int pinLength, int pinSubs[], int numDigits) {
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

bool requestPin(const int pinSubs[], int pinLength) {
    bool pinWrong = false;
    for (int i = 0; i < pinLength; i++) {
        char pinEntryChar;
        cin >> pinEntryChar;
        int pinEntryDigit = pinEntryChar - '0';
        if (pinSubs[i] != pinEntryDigit) {
            pinWrong = true;
            // accept the rest of the PIN even though it's already wrong
        }
    }
    return !pinWrong;
}

int main() {
    int pinSubs[PIN_LENGTH];
    long seed = time(nullptr);
    // stage: cut start
    const char *seedStr = getenv("Q4_SEED");
    if (seedStr != nullptr) {
        seed = strtol(seedStr, nullptr, 10);
    }
    // cerr << seed << endl;  // stage: cut
    srand(seed);
    cout << "PIN: ";
    printArray(DIGITS, NUM_DIGITS);
    cout << endl;
    cout << "NUM: ";
    generateAndPrintSubs(PIN, PIN_LENGTH, pinSubs, NUM_DIGITS);
    bool pinCorrect = requestPin(pinSubs, PIN_LENGTH);
    cout << "Your PIN is ";
    if (!pinCorrect) {
        cout << "not ";
    }
    cout << "correct" << endl;
    return 0;
}

#pragma clang diagnostic pop            // stage: cut
