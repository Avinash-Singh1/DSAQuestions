// #include <iostream>
// #include <sstream>
// #include <vector>

#include <bits/stdc++.h>
using namespace std;




std::vector<std::string> splitIntoWords(const std::string& s) {
    std::vector<std::string> words;
    std::istringstream stream(s);
    std::string word;
    
    // Extract each word separated by spaces
    while (stream >> word) {
        words.push_back(word);
    }
    
    // return words;
    string result;
    int n =words.size();
    std::cout<<n<<std::endl;
    for(int i =n-1;i>=0;i--){
        std::cout<<words[i]<<std::endl;
        if(i==n-1)
        {
          result =result+words[i];
          continue;
        }
        result =result+" "+words[i];
    }
    cout<<result<<endl;

}

int main() {
    std::string s = "  hello world  ";
    
    std::vector<std::string> words = splitIntoWords(s);
    
    // Output each word in the vector
    // for (const std::string& word : words) {
    //     std::cout << "\"" << word << "\" ";
    // }
    
    std::cout << std::endl;

    return 0;
}
