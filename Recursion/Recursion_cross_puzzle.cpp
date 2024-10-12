#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

bool canPlaceHorizontally(const vector<string> &crossword, const string &word, int row, int col) {
    if (col + word.length() > 10) return false; // Out of bounds
    for (int i = 0; i < word.length(); i++) {
        if (crossword[row][col + i] != '-' && crossword[row][col + i] != word[i]) return false;
    }
    return true;
}

bool canPlaceVertically(const vector<string> &crossword, const string &word, int row, int col) {
    if (row + word.length() > 10) return false; // Out of bounds
    for (int i = 0; i < word.length(); i++) {
        if (crossword[row + i][col] != '-' && crossword[row + i][col] != word[i]) return false;
    }
    return true;
}

void placeHorizontally(vector<string> &crossword, const string &word, int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        crossword[row][col + i] = word[i];
    }
}

void removeHorizontally(vector<string> &crossword, const string &word, int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        crossword[row][col + i] = '-';
    }
}

void placeVertically(vector<string> &crossword, const string &word, int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        crossword[row + i][col] = word[i];
    }
}

void removeVertically(vector<string> &crossword, const string &word, int row, int col) {
    for (int i = 0; i < word.length(); i++) {
        crossword[row + i][col] = '-';
    }
}

bool solveCrossword(vector<string> &crossword, vector<string> &words, int index) {
    if (index == words.size()) return true; // All words placed

    string word = words[index];

    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            if (canPlaceHorizontally(crossword, word, row, col)) {
                placeHorizontally(crossword, word, row, col);
                if (solveCrossword(crossword, words, index + 1)) return true;
                removeHorizontally(crossword, word, row, col);
            }
            if (canPlaceVertically(crossword, word, row, col)) {
                placeVertically(crossword, word, row, col);
                if (solveCrossword(crossword, words, index + 1)) return true;
                removeVertically(crossword, word, row, col);
            }
        }
    }
    return false; // No valid position found
}

vector<string> crosswordPuzzle(vector<string> crossword, const string &words) {
    vector<string> wordList;
    stringstream ss(words);
    string word;
    while (getline(ss, word, ';')) {
        wordList.push_back(word);
    }

    solveCrossword(crossword, wordList, 0);
    return crossword;
}

int main() {
    vector<string> crossword(10);
    for (int i = 0; i < 10; i++) {
        getline(cin, crossword[i]);
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (const auto &line : result) {
        cout << line << endl;
    }

    return 0;
}

// Sample Input 2

// ++++++-+++
// ++------++
// ++++++-+++
// ++++++-+++
// +++------+
// ++++++-+-+
// ++++++-+-+
// ++++++++-+
// ++++++++-+
// ++++++++-+
// ICELAND;MEXICO;PANAMA;ALMATY
// Sample Output 2

// ++++++I+++
// ++MEXICO++
// ++++++E+++
// ++++++L+++
// +++PANAMA+
// ++++++N+L+
// ++++++D+M+
// ++++++++A+
// ++++++++T+
// ++++++++Y+