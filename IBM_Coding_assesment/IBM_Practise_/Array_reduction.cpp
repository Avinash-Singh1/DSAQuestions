
#include <bits/stdc++.h>
using namespace std;

int totalCost(vector<int> &arr)
{

    int total_cost = 0;

    while (arr.size() > 1)
    {
        auto min_element_it = min_element(arr.begin(), arr.end());
        auto max_element_it = max_element(arr.begin(), arr.end());
        int min_element = *min_element_it;
        int max_element = *max_element_it;
        // cout << "min: " << minval << " max: " << maxval << endl;
        // calculate the cost of  the operation
        int cost = ceil(static_cast<double>(min_element + max_element) /( max_element - min_element + 1));

        // get the indices of minimum and max element
        int min_index = min_element_it - arr.begin();
        int max_index = max_element_it - arr.begin();

        // remove the min and max elements by index
        arr.erase(arr.begin() + max_index);
        arr.erase(arr.begin() + min_index);

        // add their sum back to the array
        arr.push_back(min_element + max_element);

         total_cost += cost;
    }
    return total_cost;
}

int main()
{
    vector<int> arr1 = {2, 3, 4, 5, 7};
    cout << "Total Cost for arr1: " << totalCost(arr1) << endl; // Expected output: 8
    vector<int> arr2 = { 3, 5, 2,1,9, 6};
    cout << "Total Cost for arr1: " << totalCost(arr2) << endl; // Expected output: 10

    vector<int> arr3= {8,8,8,8};
    cout << "Total Cost for arr2: " << totalCost(arr3) << endl;  // Expected output: 21

    return 0;
}
