#include <iostream>
using namespace std;

void reverseString(string &str, int start, int end) {
    if (start >= end) return; // Base case
    swap(str[start], str[end]); // Swap characters
    reverseString(str, start + 1, end - 1); // Recursive case
}

int main() {
    string str = "recursion";
    reverseString(str, 0, str.size() - 1);
    cout << "Reversed string is " << str << endl;
    return 0;
}
