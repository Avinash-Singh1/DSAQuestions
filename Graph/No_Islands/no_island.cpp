class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& grid){
        int n= grid.size();
        int m = grid[0].size();
        
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        
        
        while(!q.empty()){
            int row=q.front().first;
            int col= q.front().second;
            q.pop();
            
            for(int drow=-1;drow<=1;drow++){
                for(int dcol=-1;dcol<=1;dcol++){
                    int nrow=row+drow; int ncol= col+dcol;
                    if( nrow>=0 && nrow<n && ncol>=0 && ncol <m && !vis[nrow][ncol]&& grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }


// Input: grid = [[0,1],[1,0],[1,1],[1,0]]
// Output: 1
// Explanation:
// The grid is-

// All lands are connected.