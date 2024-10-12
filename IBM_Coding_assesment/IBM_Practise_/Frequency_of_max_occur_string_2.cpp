#include <bits/stdc++.h>
using namespace std;

int getMaxOccurrences(string components, int minLength, int maxLength, int maxUnique) {
    int n = components.size();
    unordered_map<string, int> substring_count;
    int maxOccurrence = 0;

    for (int i = 0; i < n; ++i) {
        unordered_map<char, int> charcount;
        string substring = "";

        for (int j = i; j < min(i + maxLength, n); ++j) {
            substring += components[j];
            charcount[components[j]]++;

            if (charcount.size() > maxUnique) {
                break;
            }

            if (substring.size() >= minLength) {
                substring_count[substring]++;
                maxOccurrence = max(maxOccurrence, substring_count[substring]);
            }
        }
    }
    return maxOccurrence;
}

int main() {
    // string components = "abcde";
    // int minLength = 2;
    // int maxLength = 3;
    // int maxUnique = 3;
    // cout << getMaxOccurrences(components, minLength, maxLength, maxUnique) << endl;

    // string components2 = "aaaaabbbccc";
    // int minLength2 = 3;
    // int maxLength2 = 5;
    // int maxUnique2 = 2;
    // cout << getMaxOccurrences(components2, minLength2, maxLength2, maxUnique2) << endl;

    string components2 = "aaaaabbbccc";
    int minLength2 = 2;
    int maxLength2 = 4;
    int maxUnique2 = 26;
    cout << getMaxOccurrences(components2, minLength2, maxLength2, maxUnique2) << endl;

    return 0;
}
