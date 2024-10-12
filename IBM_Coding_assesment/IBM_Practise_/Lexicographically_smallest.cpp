#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool canPlaceSubstring(const string &word, const string &substr, int pos)
{
    for (int i = 0; i < substr.size(); ++i)
    {
        if (word[pos + i] != '?' && word[pos + i] != substr[i])
        {
            return false;
        }
    }
    return true;
}

string replaceQuestionMarks(string &word, int pos, const string &substr)
{
    for (int i = 0; i < substr.size(); ++i)
    {
        word[pos + i] = substr[i];
    }
    for (int i = 0; i < word.size(); ++i)
    {
        if (word[i] == '?')
        {
            word[i] = 'a'; // Replace remaining '?' with 'a' for lexicographically smallest string
        }
    }
    return word;
}

string findLexicographicallySmallestString(string word, string substr)
{
    int n = word.size(), m = substr.size();
    string result = "-1";

    for (int i = 0; i <= n - m; ++i)
    {
        if (canPlaceSubstring(word, substr, i))
        {
            string temp = word;
            temp = replaceQuestionMarks(temp, i, substr);
            if (result == "-1" || temp < result)
            {
                result = temp;
            }
        }
    }
    return result;
}

int main()
{
    string word = "as?b?e?gf";
    string substr = "dbk";

    string result = findLexicographicallySmallestString(word, substr);
    cout << "Result: " << result << endl;

    string word2 = "????";
    string substr2 = "ab";

    string result2 = findLexicographicallySmallestString(word2, substr2);
    cout << "Result: " << result2 << endl;

    string word3 = "?abc?";
    string substr3 = "abc";

    string result3 = findLexicographicallySmallestString(word3, substr3);
    cout << "Result: " << result3 << endl;
    return 0;
}
