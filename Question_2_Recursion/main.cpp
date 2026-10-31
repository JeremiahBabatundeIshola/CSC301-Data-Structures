
#include <iostream>
#include <string>
using namespace std;

// Recursive function to calculate factorial
long long factorial(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive case
    return n * factorial(n - 1);
}

// Recursive function to calculate a Fibonacci number
long long fibonacci(int n) {
    // Base cases
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive function to reverse a string
string reverseString(string text, int index) {
    // Base case
    if (index < 0) {
        return "";
    }

    // Recursive case
    return text[index] + reverseString(text, index - 1);
}

// Recursive binary search function
int binarySearch(int arr[], int left, int right, int target) {
    // Base case: target is not found
    if (left > right) {
        return -1;
    }

    // Find the middle index
    int mid = left + (right - left) / 2;

    // Base case: target is found
    if (arr[mid] == target) {
        return mid;
    }

    // Recursive case: search the left half
    if (target < arr[mid]) {
        return binarySearch(arr, left, mid - 1, target);
    }

    // Recursive case: search the right half
    return binarySearch(arr, mid + 1, right, target);
}


int main() {
    int number;

    cout << "Enter a non-negative integer: ";
    cin >> number;

    if (number < 0 || number > 20) {
        cout << "Please enter a number between 0 and 20." << endl;
    } else {
        cout << "Factorial of " << number << " = "
             << factorial(number) << endl;
    }

int n;

cout << "\nEnter the number of Fibonacci terms: ";
cin >> n;

if (n < 0 || n > 40) {
    cout << "Please enter a number between 0 and 40." << endl;
} else {
    cout << "Fibonacci sequence: ";

    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }

    cout << endl;
}
string text;

cout << "\nEnter a string to reverse: ";
cin >> text;

cout << "Reversed string: "
     << reverseString(text, static_cast<int>(text.length()) - 1)
     << endl;
// FACTORIAL TEST CASES
cout << "\n===== FACTORIAL TESTS =====" << endl;

cout << "Test 1 - Factorial of 0: " << factorial(0) << endl;
cout << "Test 2 - Factorial of 1: " << factorial(1) << endl;
cout << "Test 3 - Factorial of 5: " << factorial(5) << endl;


// FIBONACCI TEST CASES
cout << "\n===== FIBONACCI TESTS =====" << endl;

int fibTests[] = {1, 6, 0};

for (int j = 0; j < 3; j++) {
    cout << "Test " << j + 1 << " - First "
         << fibTests[j] << " terms: ";

    for (int k = 0; k < fibTests[j]; k++) {
        cout << fibonacci(k) << " ";
    }

    cout << endl;
}


// STRING REVERSAL TEST CASES
cout << "\n===== STRING REVERSAL TESTS =====" << endl;

string test1 = "HELLO";
string test2 = "A";
string test3 = "DATA";
string test4 = "";

cout << "Test 1 - HELLO: "
     << reverseString(test1, static_cast<int>(test1.length()) - 1) << endl;

cout << "Test 2 - A: "
     << reverseString(test2, static_cast<int>(test2.length()) - 1) << endl;

cout << "Test 3 - DATA: "
     << reverseString(test3, static_cast<int>(test3.length()) - 1) << endl;

cout << "Test 4 - Empty string: "
     << reverseString(test4, static_cast<int>(test4.length()) - 1) << endl;

     // Binary Search Tests
cout << "\n===== BINARY SEARCH TESTS =====" << endl;

int arr[] = {2, 4, 6, 8, 10, 12, 14};
int size = sizeof(arr) / sizeof(arr[0]);

int target1 = 8;
int result1 = binarySearch(arr, 0, size - 1, target1);
cout << "Test 1 - Search for 8: ";
if (result1 != -1)
    cout << "Found at index " << result1 << endl;
else
    cout << "Not found" << endl;

int target2 = 14;
int result2 = binarySearch(arr, 0, size - 1, target2);
cout << "Test 2 - Search for 14: ";
if (result2 != -1)
    cout << "Found at index " << result2 << endl;
else
    cout << "Not found" << endl;

int target3 = 5;
int result3 = binarySearch(arr, 0, size - 1, target3);
cout << "Test 3 - Search for 5: ";
if (result3 != -1)
    cout << "Found at index " << result3 << endl;
else
    cout << "Not found" << endl;

int* emptyArr = nullptr;
int emptyResult = binarySearch(emptyArr, 0, -1, 5);
cout << "Test 4 - Empty array: ";
if (emptyResult != -1)
    cout << "Found at index " << emptyResult << endl;
else
    cout << "Not found (correct)" << endl;
    return 0;
}

