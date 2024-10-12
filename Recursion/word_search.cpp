#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();

        // Loop through each cell of the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Start DFS if the first character matches
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(std::vector<std::vector<char>>& board, const std::string& word, int i, int j, int index) {
        // If we have matched the entire word
        if (index == word.size()) {
            return true;
        }

        // Boundary checks and character match
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        // Mark the cell as visited
        char temp = board[i][j];
        board[i][j] = '#';  // Temporary marker

        // Explore all 4 possible directions (up, down, left, right)
        bool found = dfs(board, word, i + 1, j, index + 1) ||  // Down
                     dfs(board, word, i - 1, j, index + 1) ||  // Up
                     dfs(board, word, i, j + 1, index + 1) ||  // Right
                     dfs(board, word, i, j - 1, index + 1);    // Left

        // Backtrack by restoring the original value
        board[i][j] = temp;

        return found;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    std::string word1 = "ABCCED";
    std::string word2 = "SEE";

    std::cout << (sol.exist(board, word1) ? "true" : "false") << std::endl;  // Output: true
    std::cout << (sol.exist(board, word2) ? "true" : "false") << std::endl;  // Output: true

    return 0;
}
