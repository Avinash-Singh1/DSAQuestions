#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

map<string, string> jsonParse(const string& jsonString) {
    map<string, string> result;
    size_t pos = 0;
    
    while (pos < jsonString.size()) {
        size_t keyStart = jsonString.find('"', pos + 1);
        size_t keyEnd = jsonString.find('"', keyStart + 1);
        size_t valueStart = jsonString.find('"', keyEnd + 1);
        size_t valueEnd = jsonString.find('"', valueStart + 1);
        
        if (keyStart != string::npos && keyEnd != string::npos &&
            valueStart != string::npos && valueEnd != string::npos) {
            string key = jsonString.substr(keyStart + 1, keyEnd - keyStart - 1);
            string value = jsonString.substr(valueStart + 1, valueEnd - valueStart - 1);
            result[key] = value;https://chatgpt.com/
            pos = valueEnd + 1;
        } else {
            break;
        }
    }
    
    return result;
}

vector<string> getSsoNpItf(const string& json1, const string& json2) {
    vector<string> diff;

    map<string, string> map1 = jsonParse(json1);
    map<string, string> map2 = jsonParse(json2);

    auto keys = (map1.size() < map2.size()) ? map1 : map2;

    for (const auto& pair : keys) {
        const string& key = pair.first;

        if (map1.count(key) && map2.count(key)) {
            if (map1[key] != map2[key]) {
                diff.push_back(key);
            }
        }
    }

    sort(diff.begin(), diff.end());
    return diff;
}

int main() {
    string json1 = R"({"name":"John","age":"30","city":"New York"})";
    string json2 = R"({"name":"John","age":"31","city":"New York"})";

    vector<string> differences = getSsoNpItf(json1, json2);

    for (const string& key : differences) {
        cout << key << endl;
    }

    return 0;
}
