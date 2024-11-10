#include <iostream>
#include <vector>
using namespace std;

void calculateScore(int n, int m, const vector<vector<int>>& grid, int i, int j, vector<vector<int>>& score, int currentValue) {
    if (i + 1 < n && grid[i + 1][j] >= currentValue) {
        score[i + 1][j] += 1;
        calculateScore(n, m, grid, i + 1, j, score, grid[i + 1][j]); 
    }

    if (j + 1 < m && grid[i][j + 1] >= currentValue) {
        score[i][j + 1] += 1;
        calculateScore(n, m, grid, i, j + 1, score, grid[i][j + 1]); 
    }
}

int main() {
    int rows, cols, targetScore;
    cin >> rows >> cols;  // Input the grid dimensions

    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> targetScore;

    vector<vector<int>> score(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            calculateScore(rows, cols, grid, i, j, score, grid[i][j]);
        }
    }

    bool found = false;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (score[i][j] == targetScore) {
                cout << i << " " << j << endl;  
                found = true;
            }
        }
    }

    if (!found) {
        cout << "NO" << endl;
    }

    return 0;
}
