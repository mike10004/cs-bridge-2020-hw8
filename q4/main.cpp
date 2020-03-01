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

/**
 * Generates a random integer in the given range.
 * Random number generator must be seeded before calling this function.
 * Behavior is undefined if range size is larger than maximum positive int.
 * @param minInclusive range minimum (inclusive)
 * @param maxInclusive range maximum (inclusive)
 * @return a randomly generated integer
 */
int generateRandomInt(int minInclusive, int maxInclusive) {
    return (rand() % (maxInclusive - minInclusive + 1)) + minInclusive;
}

/**
 * Generates a sequence of substitute numbers for the user to enter
 * instead of their PIN and records the correct substituted-PIN
 * in an array.
 * @param pin PIN number
 * @param pinLength PIN length
 * @param pinSubs destination for correct sequence of substitute PIN digits 
 * @param numDigits number of possible values for each digit of PIN
 */
void generateAndPrintSubs(const int pin[], int pinLength, int pinSubs[], int numDigits) {
    for (int i = 0; i < numDigits; i++) {
        int randomNumber = generateRandomInt(SUB_MIN, SUB_MAX);
        cout << randomNumber << ' ';
        for (int j = 0; j < pinLength; j++) {
            if (pin[j] == i) {
                pinSubs[j] = randomNumber; 
            }
        }
    }
}

/**
 * Prints an array.
 * @param values array
 * @param length array length
 */
void printArray(const int values[], int length) {
    for (int i = 0; i < length; i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << values[i];
    }
}

/**
 * Reads a sequence of substitute PIN numbers from standard input
 * and checks whether they are correct.
 * @param pinSubs array containing the correct sequence of substitue PIN digits
 * @param pinLength number of digits to read
 * @return true if the correct sequence of digits is read
 */
bool readSubbedPin(const int pinSubs[], int pinLength) {
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

/**
 * Prints a set of substitute digit mappings for a PIN number, 
 * reads a sequence of digits from standard input, and reports
 * whether the input sequence is correct.
 * @return zero on clean exit (regardless of PIN correctness)
 */
int main() {
    int pinSubs[PIN_LENGTH];
    long seed = time(nullptr);
    // stage: cut start
    const char *seedStr = getenv("Q4_SEED");
    if (seedStr != nullptr) {
        seed = strtol(seedStr, nullptr, 10);
    }
    // stage: cut stop
    // cerr << seed << endl;  // stage: cut
    srand(seed);
    cout << "PIN: ";
    printArray(DIGITS, NUM_DIGITS);
    cout << endl;
    cout << "NUM: ";
    generateAndPrintSubs(PIN, PIN_LENGTH, pinSubs, NUM_DIGITS);
    cout << endl;
    bool pinCorrect = readSubbedPin(pinSubs, PIN_LENGTH);
    cout << "Your PIN is ";
    if (!pinCorrect) {
        cout << "not ";
    }
    cout << "correct" << endl;
    return 0;
}

#pragma clang diagnostic pop            // stage: cut
