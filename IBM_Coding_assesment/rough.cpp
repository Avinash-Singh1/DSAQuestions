#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

// Custom comparator for priority queue
struct Compare {
    bool operator()(pair<int, char>& a, pair<int, char>& b) {
        return a.first > b.first; // Min-heap based on frequency
    }
};

// Function to find the minimum number of moves
int minMovesToReduceString(string s) {
    unordered_map<char, vector<int>> charIndices; // Map to store character occurrences
    int n = s.size();
    
    // Fill the map with character indices
    for (int i = 0; i < n; ++i) {
        charIndices[s[i]].push_back(i);
    }
    
    priority_queue<pair<int, char>, vector<pair<int, char>>, Compare> pq; // Min-heap
    
    // Populate the priority queue with characters based on their frequency
    for (auto& entry : charIndices) {
        pq.push({entry.second.size(), entry.first});
    }
    
    unordered_set<int> deletedIndices; // Set to track deleted indices
    int moves = 0;
    
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        
        char c = top.second;
        vector<int>& indices = charIndices[c];
        
        if (indices.empty()) continue; // Skip if no more occurrences
        
        // Perform the move: delete occurrences of 'c' to the left and right
        for (int index : indices) {
            if (deletedIndices.find(index) == deletedIndices.end()) {
                deletedIndices.insert(index);
                
                // Remove left occurrence
                int leftIndex = index - 1;
                while (leftIndex >= 0 && s[leftIndex] == c) {
                    deletedIndices.insert(leftIndex);
                    --leftIndex;
                }
                
                // Remove right occurrence
                int rightIndex = index + 1;
                while (rightIndex < n && s[rightIndex] == c) {
                    deletedIndices.insert(rightIndex);
                    ++rightIndex;
                }
                
                ++moves; // Increment move count
            }
        }
    }
    
    return moves;
}

int main() {
    string s = "saasascscsc";
    cout << "Minimum number of moves: " << minMovesToReduceString(s) << endl;
    // cout<<'07'-'0'<<endl;
    return 0;
}
