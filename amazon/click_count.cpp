#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int minimumkeypadClickCount(const std::string& text) {
    // Define the keypad layout
    std::vector<std::string> keypad = {
        "abc",  // Button 1
        "def",  // Button 2
        "ghi",  // Button 3
        "jkl",  // Button 4
        "mno",  // Button 5
        "pqr",  // Button 6
        "stu",  // Button 7
        "vwx",  // Button 8
        "yz"    // Button 9
    };

    // Create a mapping from letters to button presses
    std::unordered_map<char, int> clickCount;
    for (int i = 0; i < keypad.size(); ++i) {
        for (int j = 0; j < keypad[i].size(); ++j) {
            clickCount[keypad[i][j]] = j + 1; // Presses: 1 for 1st letter, 2 for 2nd, 3 for 3rd
        }
    }

    // Calculate total clicks for the input text
    int totalClicks = 0;
    for (char c : text) {
        if (clickCount.find(c) != clickCount.end()) {
            totalClicks += clickCount[c]; // Add the click count for the character
        } else {
            // Handle case where character is not found in keypad (if needed)
            std::cerr << "Character " << c << " not found in keypad!" << std::endl;
        }
    }

    return totalClicks; // Return the total click count
}

int main() {
    // Test cases
    std::cout << minimumkeypadClickCount("hello") << std::endl; // Output: 8
   
    return 0;
}
