#include<bits/stdc++.h>
using namespace std;
    int orangesRotting(vector<vector<int>>& grid) {
       int m=grid.size(); int n= grid[0].size();
       int tot =0;int days=0; int rot_cnt=0; queue<pair<int,int>> q;

       for (int i = 0; i < m; i++)
       {
            for (int j = 0; j < n; j++)
            {
                if(grid[i][j]!= 0) tot++;
                if(grid[i][j]== 2) {
                    
                    q.push({i,j});
                }
                
            }
            
       }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
       while(!q.empty())
       {
        int k =q.size();
         rot_cnt+=k;
         while (k--)
         {
            int  x = q.front().first; int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++){
                int nx= x+dx[i];
                int ny = y+dy[i];
                if(nx<0 || ny<0 || nx>=m || ny>= n|| grid[nx][ny] !=1) continue;
                grid[nx][ny]=2;
                q.push({nx,ny});
            }
            

         }
         if(!q.empty())days++;
         
       }

       return tot == rot_cnt?days:-1;
       
    }

    int main()
    {
        vector<vector<int>> v{ {2,1,1} , {1,1,0} , {0,1,1} } ;
        int rotting = orangesRotting(v);
        cout<<"Minimum Number of Minutes Required "<<rotting<<endl;
        
    }