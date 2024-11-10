#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string calculateDistance(string str, int x, int y) {
    for (char ch : str) {
        if (ch != '0' && ch != '1') {
            return "INVALID";
        }
    }

    int zerosCount = 0;
    int onesCount = 0;

    for (char ch : str) {
        if (ch == '0') {
            zerosCount++;
        } else {
            onesCount++;
        }
    }

    string rearrangedStr(zerosCount, '0');
    rearrangedStr.append(onesCount, '1');

    int distance = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != rearrangedStr[i]) {
            distance++;
        }
    }

    return to_string(distance);
}

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore(); 

    for (int t = 0; t < testCases; t++) {
        string str;
        getline(cin, str); 

        string line;
        getline(cin, line); 
        stringstream ss(line);

        int x, y;
        ss >> x >> y; 

        string result = calculateDistance(str, x, y);

        cout << result;

        if (t < testCases - 1) {
            cout << "\n";
        }
    }

    return 0;
}
