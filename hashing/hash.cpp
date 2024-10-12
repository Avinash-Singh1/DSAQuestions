#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 2, 1, 4, 5, 1, 2, 3, 4, 4};
    std::unordered_map<int, int> frequencyMap;

    // Iterate through the vector and count the frequency of each number
    for (int num : numbers) {
        frequencyMap[num]++;
    }

    // Output the frequency of each number
    std::cout << "Frequency of elements:" << std::endl;
    for (const auto& pair : frequencyMap) {
        std::cout << "Number " << pair.first << " occurs " << pair.second << " times." << std::endl;
    }

    return 0;
}
