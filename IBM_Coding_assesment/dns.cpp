#include <bits/stdc++.h>
using namespace std;

vector<int> getMintime(int cache_size, int cache_time, int server_time, vector<string> urls) {
    vector<int> timeTaken;
    queue<string> queue;
    unordered_set<string> cache_set;

    for (const string& url : urls) {
        if (cache_set.count(url) > 0) {
            timeTaken.push_back(cache_time);
        } else {
            if (queue.size() >= cache_size) {
                string frontUrl = queue.front();
                queue.pop();
                cache_set.erase(frontUrl);
            }
            timeTaken.push_back(server_time);
            queue.push(url);
            cache_set.insert(url);  // Add the URL to the cache set
        }
    }
    return timeTaken;
}

int main() {
    int cache_size = 2;
    int cache_time = 2;
    int server_time = 3;
    vector<string> urls = {
        "www.google.com",
        "www.yahoo.com",
        "www.google.com",
        "www.yahoo.com",
        "www.coursera.com"
    };
    vector<int> result = getMintime(cache_size, cache_time, server_time, urls);
    
    for (int time : result) {
        cout << time << " ";
    }
    cout << endl;
    
    return 0;
}
