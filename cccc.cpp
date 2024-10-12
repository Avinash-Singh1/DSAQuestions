
#include <bits/stdc++.h>
using namespace std;
class KthLargest {
private:
     priority_queue<int,  vector<int>,  greater<int>> minHeap;
    int k;

public:
    KthLargest(int k,  vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            cout<<"num: "<<num<<endl;
            minHeap.push(num);
            cout<<"minHeap.size() "<<minHeap.size()<<endl;
            if (minHeap.size() > k) {
                cout<<"in\n";
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

// Example usage:
int main() {
     vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    
     cout << kthLargest.add(3) <<  endl;  // Output: 4
     cout << kthLargest.add(5) <<  endl;  // Output: 5
     cout << kthLargest.add(10) <<  endl; // Output: 5
     cout << kthLargest.add(9) <<  endl;  // Output: 8
     cout << kthLargest.add(4) <<  endl;  // Output: 8
    
    return 0;
}
