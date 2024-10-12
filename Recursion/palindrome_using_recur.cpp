#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string mystring, int s, int n) {
    if (s >= n) {
        return true;
    }
    if (mystring[s] != mystring[n]) {
        return false;
    }
    return isPalindrome(mystring, s + 1, n - 1);
}

int main() {
    cout << "Enter the string: ";
    string s;
    cin >> s;
    int n = s.length();
    bool result = isPalindrome(s, 0, n - 1);
    cout << "Result: " << (result ? "Palindrome" : "Not a palindrome") << endl;

    return 0;
}
