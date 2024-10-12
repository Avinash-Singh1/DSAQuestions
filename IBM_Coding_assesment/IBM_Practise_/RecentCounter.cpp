#include <queue>
using namespace std;

class RecentCounter {
private:
    queue<int> requests;  // Queue to store the times of the requests

public:
    RecentCounter() {
        // Constructor initializes an empty queue
    }
    
    int ping(int t) {
        // Add the new request time `t` to the queue
        requests.push(t);
        
        // Remove requests that are older than 3000 milliseconds from `t`
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }
        
        // The size of the queue now represents the number of requests within the last 3000 milliseconds
        return requests.size();
    }
};
