#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a; // Base case
    return gcd(b, a % b); // Recursive case
}

int main() {
    int a = 56, b = 98;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}
