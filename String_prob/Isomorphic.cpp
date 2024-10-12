#include <iostream>
#include <string>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) return false;

    std::unordered_map<char, char> s_to_t_map;
    std::unordered_map<char, char> t_to_s_map;

    for (size_t i = 0; i < s.length(); ++i) {
        char s_char = s[i];
        char t_char = t[i];

        // Check if there's already a mapping for s_char
        if (s_to_t_map.find(s_char) != s_to_t_map.end()) {
            // If there is a mapping, it must match the current t_charhttps://chatgpt.com/c/ae365334-82e5-4ba3-8545-3c8e50141bd7
            if (s_to_t_map[s_char] != t_char) return false;
        } else {
            // Otherwise, set the mapping
            s_to_t_map[s_char] = t_char;
        }

        // Check if there's already a mapping for t_char
        if (t_to_s_map.find(t_char) != t_to_s_map.end()) {
            // If there is a mapping, it must match the current s_char
            if (t_to_s_map[t_char] != s_char) return false;
        } else {
            // Otherwise, set the mapping
            t_to_s_map[t_char] = s_char;
        }
    }

    return true;
}

int main() {
    // Test case 1
    std::string s1 = "egg";
    std::string t1 = "add";
    std::cout << "Isomorphic: " << isIsomorphic(s1, t1) << std::endl;  // Output: true

    // Test case 2
    std::string s2 = "foo";
    std::string t2 = "bar";
    std::cout << "Isomorphic: " << isIsomorphic(s2, t2) << std::endl;  // Output: false

    // Test case 3
    std::string s3 = "paper";
    std::string t3 = "title";
    std::cout << "Isomorphic: " << isIsomorphic(s3, t3) << std::endl;  // Output: true

    // Test case 4
    std::string s4 = "ab";
    std::string t4 = "aa";
    std::cout << "Isomorphic: " << isIsomorphic(s4, t4) << std::endl;  // Output: false

    return 0;
}
