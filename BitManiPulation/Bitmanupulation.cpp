#include <iostream>
using namespace std;

int minBitFlips(int start, int goal) {
    // XOR the two numbers
    int xorResult = start ^ goal;
    cout<<"xorResult: "<<xorResult<<endl;
    // Count the number of 1's in xorResult
    int count = 0;
    while (xorResult > 0) {
        count += xorResult & 1;
        cout<<"count: "<<count<<endl;
        xorResult >>= 1;
        cout<<"xorResult: "<<xorResult<<endl;
    }
    
    return count;
}

int main() {
    int start = 10;  // Example value
    int goal = 7;    // Example value
    int count=13>>1;
    int count2 =6&1;
    cout<<count2<<" : count\n";

    cout << "Minimum bit flips to convert " << start << " to " << goal << " is: " << minBitFlips(start, goal) << endl;

    return 0;
}
