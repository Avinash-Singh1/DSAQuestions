#include <iostream>
#include <vector>
using namespace std;

int countUnorderedPairs(const vector<int>& arr) {
    int count = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int xorValue = arr[i] ^ arr[j];
            int andValue = arr[i] & arr[j];
            if (xorValue > andValue) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    vector<int> arr = {4, 3, 5, 2};
    int result = countUnorderedPairs(arr);
    cout << "Number of pairs: " << result << endl;  // Output: 4
    return 0;
}
