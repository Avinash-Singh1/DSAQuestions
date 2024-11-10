#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0) return; // Base case
    towerOfHanoi(n - 1, source, destination, auxiliary); // Move n-1 disks to auxiliary
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, source, destination); // Move n-1 disks to destination
}

int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
