#include<bits/stdc++.h>
using namespace std;
    int orangesRotting(vector<vector<int>>& grid) {
       int n = grid.size(); int m = grid[0].size();
       int tot=0; int days=0; int rot_cnt=0;
       queue<pair<int,int>> q;

       for (int i = 0; i < n; i++)
       {
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j]!= 0)tot++;
            if(grid[i][j]==2)q.push({i,j});
        }
        
       }

       int dx[4]={-1,1,0,0};
       int dy[4]={0,0,1,-1};

       while (!q.empty())
       {
        int cnt_qvalue = q.size();
        rot_cnt+=cnt_qvalue;
        // find out how many of them will get rot by current rot
        while(cnt_qvalue--){
            int x =  q.front().first;
            int y = q.front().second;
            q.pop();
            // find fresh orange in four direction and rott them 
            for (int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y+ dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=1)continue;
                else{
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            
        }
        if(!q.empty()) days++;


       }
       
       return tot ==rot_cnt?days: -1;



    }

    int main()
    {
        vector<vector<int>> v{ {2,1,1} , {1,1,0} , {0,1,1} } ;
        int rotting = orangesRotting(v);
        cout<<"Minimum Number of Minutes Required "<<rotting<<endl;
        
    }