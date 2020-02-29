// mac937@nyu.edu
// hw8 question 3

#include <iostream>

using namespace std;

/**
 * Swaps two values.
 * @param a reference to one value
 * @param b reference to the other value
 */
void swap(int& a, int& b);

/**
 * Reverses the order of elements in an array.
 * @param arr array 
 * @param arrSize array length
 */
void reverseArray(int arr[], int arrSize);

/**
 * Determines whether a number is even.
 * @param number the number
 * @return true if even, false if odd
 */
bool isEven(int number);

/**
 * Updates an array so that only even numbers remain,
 * in their original order, and returns the number of
 * even numbers, which can be interpreted as the new 
 * array length.
 * @param arr array
 * @param arrSize original array length on input, new array length upon return
 */
void removeOdd(int arr[], int& arrSize);

/**
 * Updates an array so that all odd numbers are at positions before all even numbers.
 * @param arr array
 * @param arrSize array length
 */
void splitParity(int arr[], int arrSize);

/**
 * Prints an array.
 * @param arr  array
 * @param arrSize array length
 */
void printArray(int arr[], int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
    return 0;
}

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void reverseArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize / 2; i++) {
        swap(arr[i], arr[arrSize - i - 1]);
    }
}

bool isEven(int number) {
    return number % 2 == 0;
}

void removeOdd(int arr[], int& arrSize) {
    int numEvens = 0;
    for (int i = 0; i < arrSize; i++) {
        if (isEven(arr[i])) {
            arr[numEvens] = arr[i];
            numEvens++;
        } 
    }
    arrSize = numEvens;
}

// implementation modeled after mystery algorithm of ZyBooks Exercise 8.3.5
void splitParity(int arr[], int arrSize) {
    int i = 0, j = arrSize - 1;
    while (i < j) {
        while (i < j and !isEven(arr[i])) {
            i += 1;
        }
        while (i < j and isEven(arr[j])) {
            j -= 1;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
}
