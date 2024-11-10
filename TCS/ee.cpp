
#include <bits/stdc++.h>
using namespace std;


const int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int M, N;
vector<vector<int>> data;
vector<vector<int>> fudged_data;

bool inBounds(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

int calculateFudge(int x, int y) {
    int max_data = data[x][y];
    for (int i = 0; i < 8; ++i) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (inBounds(nx, ny)) {
            max_data = max(max_data, data[nx][ny]);
        }
    }
    return max(0, max_data - data[x][y]);
}

int main() {
    // Input reading
    cin >> M >> N;
    data.resize(M, vector<int>(N));
    fudged_data.resize(M, vector<int>(N, 0)); // No fudged data initially

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> data[i][j];
        }
    }

    int start_x, start_y, end_x, end_y;
    cin >> start_x >> start_y;
    cin >> end_x >> end_y;

    // Convert to zero-indexed
    start_x--;
    start_y--;
    end_x--;
    end_y--;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, start_x, start_y});

    while (!pq.empty()) {
        int fudge = std::get<0>(pq.top());
        int x = std::get<1>(pq.top());
        int y = std::get<2>(pq.top());
        pq.pop();

        // If we reached the end position, return the fudge value
        if (x == end_x && y == end_y) {
            cout << fudge << endl;
            return 0;
        }

        // Explore all neighbors
        for (int i = 0; i < 8; ++i) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            
            if (inBounds(nx, ny)) {
                int fudge_needed = calculateFudge(nx, ny);
                
                int total_fudge = fudge + fudge_needed;
                
                if (fudged_data[nx][ny] == 0 || total_fudge < fudged_data[nx][ny]) {
                    fudged_data[nx][ny] = total_fudge;
                    pq.push({total_fudge, nx, ny});
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

const int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

struct Cell {
    int x, y;     // Coordinates of the cell
    int data;     // Amount of data in the cell
    int cost;     // Cost of fudging data to reach this cell
};

bool isInBounds(int x, int y, int M, int N) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

struct Compare {
    bool operator()(const Cell& a, const Cell& b) {
        return a.cost > b.cost;
    }
};

int main() {
    int M, N;
    cin >> M >> N;
    
    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    
    int virus_x, virus_y;
    cin >> virus_x >> virus_y;
    virus_x--; virus_y--;  // Convert to 0-indexed
    
    int dummy_x, dummy_y;
    cin >> dummy_x >> dummy_y;
    dummy_x--; dummy_y--;  // Convert to 0-indexed
    
    priority_queue<Cell, vector<Cell>, Compare> pq;
    
    pq.push({virus_x, virus_y, grid[virus_x][virus_y], 0});
    
    vector<vector<int>> fudged(M, vector<int>(N, INT_MAX));
    fudged[virus_x][virus_y] = 0;
    
    while (!pq.empty()) {
        Cell current = pq.top();
        pq.pop();
        
        if (current.x == dummy_x && current.y == dummy_y) {
            cout << current.cost << endl;
            return 0;
        }
        
        for (auto& dir : directions) {
            int nx = current.x + dir[0];
            int ny = current.y + dir[1];
            
            if (isInBounds(nx, ny, M, N)) {
                int maxData = -1;
                for (auto& d : directions) {
                    int nnx = nx + d[0];
                    int nny = ny + d[1];
                    if (isInBounds(nnx, nny, M, N)) {
                        maxData = max(maxData, grid[nnx][nny]);
                    }
                }
                
                int newCost = max(0, maxData - grid[nx][ny]);
                
                if (current.cost + newCost < fudged[nx][ny]) {
                    fudged[nx][ny] = current.cost + newCost;
                    pq.push({nx, ny, grid[nx][ny], fudged[nx][ny]});
                }
            }
        }
    }
    
    return 0;
}
