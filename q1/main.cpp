// mac937@nyu.edu
// CS Bridge Winter 2020 Extended
// HW8 Question 1

#include <iostream>
#include <cassert>

using namespace std;

const int NUM_VALUES = 20;

/**
 * Prompts the user to enter values to populate an array.
 * @param values the array
 * @param numValues number of values to request
 */
void populate(int values[], int numValues) {
    cout << "Please enter " << numValues << " integers separated by a space:" << endl;
    for (int i = 0; i < numValues; i++) {
        cin >> values[i];
    }
}

/**
 * Finds the minimum value of an array.
 * @param values the array
 * @param numValues array length
 * @return the minimum value
 */
int minInArray(const int *values, int numValues) {
    assert(numValues > 0);
    int minValue = values[0];
    for (int i = 1; i < numValues; i++) {
        if (values[i] < minValue) {
            minValue = values[i];
        }
    }
    return minValue;
}

/**
 * Prints the indices at which a value is found in an array.
 * @param needle the value to print the indices of
 * @param haystack the array
 * @param numValues array length
 */
void printIndices(int needle, const int haystack[], int numValues) {
    for (int i = 0; i < numValues; i++) {
        if (haystack[i] == needle) {
            cout << ' ' << i;
        }
    }
}

/**
 * Prints the indices where the minium value of an array is found.
 * @return zero on normal operation
 */
int main() {
    int values[NUM_VALUES];
    populate(values, NUM_VALUES);
    int minValue = minInArray(values, NUM_VALUES);
    cout << "The minimum value is " << minValue 
         << ", and it is located in the following indices:";
    printIndices(minValue, values, NUM_VALUES);
    cout << endl;
    return 0;
}
