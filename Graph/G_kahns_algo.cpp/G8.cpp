#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
  void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid) {
     
     queue<pair<int,int>>q;
     q.push({row,col});
      int n = grid.size(); 
      int m = grid[0].size();

     while(!q.empty()){
        int x= q.front().first;
        int y= q.front().second;
        q.pop();

         // traverse in the neighbours and mark them if its a land 
          for(int delrow = -1; delrow<=1;delrow++) {
              for(int delcol = -1; delcol <= 1; delcol++) {
                  int nrow = x + delrow; 
                  int ncol = y + delcol; 
                  // neighbour row and column is valid, and is an unvisited land
                  if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                  && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                      vis[nrow][ncol] = 1; 
                      q.push({nrow, ncol}); 
                  }
              }
          }

     }
  }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>> vis(n,vector<int>(m,0));
        int no_island=0;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < m; j++)
                {
                    if(!vis[i][j] && grid[i][j]=='1'){
                        no_island++;
                        bfs(i,j,vis,grid);
                    }
                }
                
        }
       return no_island;
    }
};

int main() {
    // n: row, m: column
    vector<vector<char>> grid
    {
        {'0', '1', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '0', '0'},
        {'0', '1', '0', '1'}
    };

        
    Solution obj;
    cout << obj.numIslands(grid) << endl;
        
    return 0;
}