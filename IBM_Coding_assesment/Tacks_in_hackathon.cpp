#include <bits/stdc++.h>
using namespace std;

int countTeams(int teamSize_1, int teamSize_2, int p) {
    // Initialize variables for the first team size
    int minT1 = p / teamSize_1;
    int rem1 = p % teamSize_1;

    // Try to fit as many teamSize_1 teams as possible and fill the remainder with teamSize_2
    while (minT1 >= 0) {
        if (rem1 % teamSize_2 == 0) {
            break;
        }
        minT1--;
        rem1 += teamSize_1;
    }

    // Initialize variables for the second team size
    int minT2 = p / teamSize_2;
    int rem2 = p % teamSize_2;

    // Try to fit as many teamSize_2 teams as possible and fill the remainder with teamSize_1
    while (minT2 >= 0) {
        if (rem2 % teamSize_1 == 0) {
            break;
        }
        minT2--;
        rem2 += teamSize_2;
    }

    // Check results and return the minimum number of teams or -1 if not possible
    if (minT1 < 0 && minT2 < 0) {
        return -1;
    } else if (minT1 < 0) {
        return minT2 + rem2 / teamSize_1;
    } else if (minT2 < 0) {
        return minT1 + rem1 / teamSize_2;
    } else {
        return min(minT1 + rem1 / teamSize_2, minT2 + rem2 / teamSize_1);
    }
}

int main() {
    // int teamSize_1 = 3;
    // int teamSize_2 = 4;
    // int p = 6;
    // int result = countTeams(teamSize_1, teamSize_2, p);

    // if (result == -1) {
    //     cout << "Cannot form teams with the given participant count" << endl;
    // } else {
    //     cout << "Minimum number of teams: " << result << endl;
    // }

    int teamSize_1 = 3;
    int teamSize_2 = 4;
    int p = 6;
    int result = countTeams(teamSize_1, teamSize_2, p);

    if (result == -1) {
        cout << "Cannot form teams with the given participant count" << endl;
    } else {
        cout << "Minimum number of teams: " << result << endl;
    }
    return 0;
}
