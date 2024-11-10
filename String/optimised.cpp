#include <bits/stdc++.h>
using namespace std;

int main() {
    string name = "avinash is a good boy";
    istringstream stream(name);
    vector<string> words;
    string word;

    // Store each word in a vector
    while (stream >> word) {
        words.push_back(word);
    }
    
    // for (auto it: words)
    // {
    //     cout<<" "<<it<<endl;
    // }
    

    // Reverse iterate through the vector and build the result string
    string reversed_sentence;
    for (auto it = words.rbegin(); it != words.rend(); ++it) {
        if (!reversed_sentence.empty()) {
            reversed_sentence += " ";  // Add space between words
        }
        cout<<" "<<*it<<" ";
        reversed_sentence += *it;
    }

    // cout << reversed_sentence << endl;
    return 0;
}
