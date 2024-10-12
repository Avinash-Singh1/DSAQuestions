#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &arr, long long n, long long x) {
        // Your code here
        long long l = 0;
        long long h = n - 1;
        int ans = -1;
        
        while (l <= h) {
            long long mid = l + (h - l) / 2;
            
            if (arr[mid] <= x) {
                ans = mid; // store index of the floor element
                l = mid + 1; // move right to find a closer floor
            } else {
                h = mid - 1; // move left as the mid element is greater than x
            }
        }
        return ans; // return the index of the floor element or -1 if not found
    }
};

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v(n);

        for (long long i = 0; i < n; i++) {
            cin >> v[i];
        }

        Solution obj;
        // cout << obj.findFloor(v, n, x) << endl;
        cout << lower_bound(v.begin(),v.end(),10)-v.begin() << endl;
    }

    return 0;
}
