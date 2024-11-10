
#include <bits/stdc++.h>
using namespace std;

using namespace std;

// Function to calculate the Hamming distance
int calculateHammingDistance(const string& original, const string& rearranged) {
    int distance = 0;
    for (size_t i = 0; i < original.size(); ++i) {
        if (original[i] != rearranged[i]) {
            ++distance;
        }
    }
    return distance;
}

// Function to check if a string is binary
bool isBinaryString(const string& str) {
    for (char ch : str) {
        if (ch != '0' && ch != '1') {
            return false;
        }
    }
    return true;
}

// Function to generate all possible rearrangements
vector<string> generateRearrangements(const string& binaryStr) {
    int zeroCount = count(binaryStr.begin(), binaryStr.end(), '0');
    int oneCount = binaryStr.size() - zeroCount;

    vector<string> rearrangements;
    string temp(zeroCount, '0');
    temp.append(string(oneCount, '1'));
    rearrangements.push_back(temp);

    while (next_permutation(temp.begin(), temp.end())) {
        rearrangements.push_back(temp);
    }

    return rearrangements;
}

// Main function to process each test case
void processTestCases(int T) {
    for (int t = 0; t < T; ++t) {
        string binaryStr;
        int A, B;

        cin >> binaryStr;
        cin >> A >> B;

        // Check if the input string is a valid binary string
        if (!isBinaryString(binaryStr)) {
            cout << "INVALID" << endl;
            continue;
        }

        // Generate all possible rearrangements
        vector<string> rearrangements = generateRearrangements(binaryStr);

        // Find the rearrangement with the minimum Hamming distance
        int minHammingDistance = INT_MAX;
        string minRearranged;
        int minCost = INT_MAX;

        for (const auto& rearranged : rearrangements) {
            int hammingDistance = calculateHammingDistance(binaryStr, rearranged);
            int cost = hammingDistance * min(A, B);

            if (cost < minCost) {
                minHammingDistance = hammingDistance;
                minRearranged = rearranged;
                minCost = cost;
            }
        }

        cout << minHammingDistance << endl;
    }
}

int main() {
    int T;
    cin >> T;

    processTestCases(T);

    return 0;
}