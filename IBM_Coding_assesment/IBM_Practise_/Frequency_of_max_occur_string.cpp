#include <bits/stdc++.h>
using namespace std;

int getMaxOccurences(string components, int minLength, int maxLength, int maxUnique)
{
    int n = components.length();
    int maxOccurence = 0;

    for (int length = minLength; length <= maxLength; length++)
    {
        unordered_map<string, int> substring_count;
        unordered_map<char, int> charcount;
        int uniqueChars = 0;

        for (int i = 0; i < n; i++)
        {
            char currentChar = components[i];
            charcount[currentChar]++;

            if (i >= length)
            {
                char leftChar = components[i - length];
                charcount[leftChar]--;
                if (charcount[leftChar] == 0)
                {
                    charcount.erase(leftChar);
                }
            }

            uniqueChars = charcount.size();

            if (i >= length - 1 && uniqueChars <= maxUnique)
            {
                string substring = components.substr(i - length + 1, length);
                substring_count[substring]++;
                maxOccurence = max(maxOccurence, substring_count[substring]);
            }
        }
    }
    return maxOccurence;  // Add the return statement to return the result
}

int main()
{
    string components = "abcde";
    int minLength = 2;
    int maxLength = 3;
    int maxUnique = 3;
    cout << getMaxOccurences(components, minLength, maxLength, maxUnique) << endl;

    string components2 = "aaaaabbbccc";
    int minLength2 = 2;
    int maxLength2 = 4;
    int maxUnique2 = 26;
    cout << getMaxOccurences(components2, minLength2, maxLength2, maxUnique2) << endl;


    return 0;
}
