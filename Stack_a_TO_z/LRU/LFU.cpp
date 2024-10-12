#include <iostream>
#include <unordered_map>
#include <list>

class LFUCache {
public:
    int capacity, minFreq;
    
    // key -> (value, frequency)
    std::unordered_map<int, std::pair<int, int>> keyValueFreq;
    
    // frequency -> list of keys
    std::unordered_map<int, std::list<int>> freqKeys;
    
    // key -> iterator of the key in the corresponding frequency list
    std::unordered_map<int, std::list<int>::iterator> keyIter;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0 ;
    }

    int get(int key) {
        if (keyValueFreq.find(key) == keyValueFreq.end()) {
            return -1; // key not found
        }

        // Get the value and the current frequency of the key
        int value = keyValueFreq[key].first;
        int freq = keyValueFreq[key].second;

        // Remove the key from the current frequency list
        freqKeys[freq].erase(keyIter[key]);
        if (freqKeys[freq].empty()) {
            freqKeys.erase(freq);
            if (minFreq == freq) {
                minFreq++;
            }
        }

        // Increment the frequency of the key
        freq++;
        keyValueFreq[key].second = freq;
        freqKeys[freq].push_front(key);
        keyIter[key] = freqKeys[freq].begin();

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyValueFreq.find(key) != keyValueFreq.end()) {
            // If the key exists, update its value and increase the frequency
            keyValueFreq[key].first = value;
            get(key); // Update the frequency using the get function
            return;
        }

        if (keyValueFreq.size() == capacity) {
            // Evict the least frequently used key (LFU)
            int keyToEvict = freqKeys[minFreq].back();
            freqKeys[minFreq].pop_back();
            if (freqKeys[minFreq].empty()) {
                freqKeys.erase(minFreq);
            }
            keyValueFreq.erase(keyToEvict);
            keyIter.erase(keyToEvict);
        }

        // Insert the new key with frequency 1
        keyValueFreq[key] = {value, 1};
        freqKeys[1].push_front(key);
        keyIter[key] = freqKeys[1].begin();
        minFreq = 1; // Reset minFreq to 1 since we added a new key
    }
};

// Test the LFUCache implementation
int main() {
    LFUCache lfu(2); // LFUCache with a capacity of 2
    
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    
    std::cout << "get(1): " << lfu.get(1) << std::endl;  // return 1
                                                         // cache=[1,2], cnt(2)=1, cnt(1)=2
    
    lfu.put(3, 3);   // 2 is the LFU key, invalidate 2
                     // cache=[3,1], cnt(3)=1, cnt(1)=2
    
    std::cout << "get(2): " << lfu.get(2) << std::endl;  // return -1 (not found)
    std::cout << "get(3): " << lfu.get(3) << std::endl;  // return 3
                                                         // cache=[3,1], cnt(3)=2, cnt(1)=2
    
    lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1
                     // cache=[4,3], cnt(4)=1, cnt(3)=2
    
    std::cout << "get(1): " << lfu.get(1) << std::endl;  // return -1 (not found)
    std::cout << "get(3): " << lfu.get(3) << std::endl;  // return 3
    std::cout << "get(4): " << lfu.get(4) << std::endl;  // return 4
    
    return 0;
}
