#include <iostream>
#include <string>
using namespace std;

// This function returns a string that is n number of char c:
string nCharString(size_t n, char c) {
    // return the n character string
    string charString;

    // Add char c to the end of the string charString:
    for (int i = 0; i < n; ++i) {
        charString.push_back(c);
    }

    return charString;
}