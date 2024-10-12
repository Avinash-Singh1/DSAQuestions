#include <iostream>
#include <climits>

int countTeams(int teamSize1, int teamSize2, int p) {
    int minTeams = INT_MAX;

    for (int x = 0; x <= p / teamSize1; ++x) {
        int remainingParticipants = p - x * teamSize1;
        
        if (remainingParticipants % teamSize2 == 0) {
            int y = remainingParticipants / teamSize2;
            minTeams = std::min(minTeams, x + y);
        }
    }

    return (minTeams == INT_MAX) ? -1 : minTeams;
}

int main() {
    // Test cases
    std::cout << countTeams(3, 4, 7) << std::endl; // Output: 2
    std::cout << countTeams(3, 4, 6) << std::endl; // Output: 2
    std::cout << countTeams(5, 7, 15) << std::endl; // Output: 3
    std::cout << countTeams(5, 7, 11) << std::endl; // Output: -1

    return 0;
}
