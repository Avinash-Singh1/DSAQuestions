#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm> // For std::sort

using namespace std;

int smallestUnoccupiedChair(vector<vector<int>>& times, int targetFriend) {
    // Number of friends
    int n = times.size();
    
    // Sort friends by arrival time
    vector<tuple<int, int, int>> events; // (time, type, index)
    for (int i = 0; i < n; ++i) {
        events.emplace_back(times[i][0], 1, i); // Arrival event
        events.emplace_back(times[i][1], -1, i); // Departure event
    }
    sort(events.begin(), events.end());
    
    priority_queue<int, vector<int>, greater<int>> availableChairs;
    map<int, int> friendToChair; // Map from friend index to their assigned chair
    set<int> occupiedChairs; // To keep track of occupied chairs
    
    int currentChair = 0;
    
    for (const auto& event : events) {
        int time = get<0>(event);
        int type = get<1>(event); // 1 for arrival, -1 for departure
        int friendIndex = get<2>(event);
        
        if (type == 1) { // Arrival
            if (availableChairs.empty()) {
                // No available chairs, use the next new chair
                friendToChair[friendIndex] = currentChair;
                occupiedChairs.insert(currentChair);
                ++currentChair;
            } else {
                // Use the smallest available chair
                int chair = availableChairs.top();
                availableChairs.pop();
                friendToChair[friendIndex] = chair;
                occupiedChairs.insert(chair);
            }
        } else { // Departure
            int chair = friendToChair[friendIndex];
            availableChairs.push(chair);
            occupiedChairs.erase(chair);
        }
    }
    
    return friendToChair[targetFriend];
}

int main() {
    vector<vector<int>> times1 = {{1,4}, {2,3}, {4,6}};
    int targetFriend1 = 1;
    cout << "Output: " << smallestUnoccupiedChair(times1, targetFriend1) << endl; // Output: 1
    
    vector<vector<int>> times2 = {{3,10}, {1,5}, {2,6}};
    int targetFriend2 = 0;
    cout << "Output: " << smallestUnoccupiedChair(times2, targetFriend2) << endl; // Output: 2
    
    return 0;
}
