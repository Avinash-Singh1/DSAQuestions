#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> digits = {5, 9, 9}; // Example: digits representing 999
    
    // Simulate adding 1 to the number represented by digits
    digits.insert(digits.begin(), 1); // Handle carry: prepend 1
    
    // Now digits contains {1, 0, 0, 0}, representing 1000
    for (int digit : digits) {
        cout << digit << " ";
    }
    cout << endl;
    
    return 0;
}
