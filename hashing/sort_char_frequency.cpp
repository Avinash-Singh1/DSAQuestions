#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

string frequencySort(string s) {
    // Step 1: Count frequencies
    unordered_map<char, int> freqMap;
    for (char c : s) {
        freqMap[c]++;
        cout<< c<<"  "<<  freqMap[c]<<endl;
    }
    
    // Step 2: Use a max-heap to store characters based on frequency
    priority_queue<pair<int, char>> maxHeap;
    for (auto& entry : freqMap) {
        maxHeap.push({entry.second, entry.first});
        cout<< "   maxHeap.push({entry:  "<<entry.second<<" " <<entry.first<<endl;
    }
    
    
    // Step 3: Construct the result string
    string result;
    while (!maxHeap.empty()) {
        pair<int, char> top = maxHeap.top();
        cout<<"top "<<top.second<<endl;
        maxHeap.pop();
        result.append(top.first, top.second);
         cout << "Character: " << top.second << ", Frequency: " << top.first << endl;
    }
    
    return result;
}

int main() {
    string s = "tree";
    cout << "Input: " << s << endl;
    cout << "Output: " << frequencySort(s) << endl;

    // s = "cccaaa";
    // cout << "Input: " << s << endl;
    // cout << "Output: " << frequencySort(s) << endl;

    // s = "Aabb";
    // cout << "Input: " << s << endl;
    // cout << "Output: " << frequencySort(s) << endl;

    return 0;
}
