Q1

class Solution {
public:
    // Function to get the binary representation of a number as a string
        string toBinaryString(int num) {
            return bitset<64>(num).to_string().substr(bitset<64>(num).to_string().find('1'));
        }

    int maxGoodNumber(vector<int>& nums) {
         int maxNum = 0;

        // Generate all permutations of the nums array
        sort(nums.begin(), nums.end());
        do {
            string binaryConcat = "";
            // Concatenate the binary representations
            for (int num : nums) {
                binaryConcat += toBinaryString(num);
            }
            // Convert the concatenated binary string to an integer
            int currentNum = stoi(binaryConcat, nullptr, 2);
            // Track the maximum number
            maxNum = max(maxNum, currentNum);
        } while (next_permutation(nums.begin(), nums.end()));

        return maxNum;
    }
};


// Q2 star 
class Solution {
public:
        void checkSuspiciousMethods(int k, vector<vector<int>>& graph, vector<bool>& suspicious) {
            queue<int> q;
            q.push(k);
            suspicious[k] = true;

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                for (int neighbor : graph[current]) {
                    if (!suspicious[neighbor]) {
                        suspicious[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
          vector<vector<int>> graph(n);         // Normal graph for invocations
            vector<vector<int>> reverseGraph(n);  // Reverse graph to check for incoming edges

            for (const auto& invocation : invocations) {
                int from = invocation[0];
                int to = invocation[1];
                graph[from].push_back(to);        // Direct graph: from -> to
                reverseGraph[to].push_back(from); // Reverse graph: to <- from
            }

            // Step 2: Mark all suspicious methods using BFS/DFS starting from k
            vector<bool> suspicious(n, false);
            checkSuspiciousMethods(k, graph, suspicious);

            // Step 3: Check if any suspicious method is invoked by a non-suspicious method
            for (int i = 0; i < n; ++i) {
                if (!suspicious[i]) {  // Non-suspicious method
                    for (int invokedMethod : graph[i]) {
                        if (suspicious[invokedMethod]) {
                            // Non-suspicious method invoking a suspicious method: return all methods
                            vector<int> allMethods(n);
                            for (int j = 0; j < n; ++j) {
                                allMethods[j] = j;
                            }
                            return allMethods;
                        }
                    }
                }
            }

            // Step 4: If we reach here, it means we can safely remove suspicious methods
            vector<int> remainingMethods;
            for (int i = 0; i < n; ++i) {
                if (!suspicious[i]) {
                    remainingMethods.push_back(i);
                }
            }

            return remainingMethods;
    }
};
// Q2 ends