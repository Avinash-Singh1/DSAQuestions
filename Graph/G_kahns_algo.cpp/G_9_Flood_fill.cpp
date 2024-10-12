#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&ans,
     vector<vector<int>>& image, int newColor,
     int iniColor) {
      ans[row][col]=newColor;
      int delRow[] = {-1, 0, 1, 0};
      int delCol[] = {0, 1, 0, -1};
      int n = image.size(); int m= image[0].size();
      for (int i = 0; i < 4; i++)
      {
        int nx = row+ delRow[i];
        int ny = col+ delCol[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny]==iniColor){
            dfs(nx,ny,ans,image,newColor,iniColor);
        }
        
      }
      

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
    int sr, int sc, int newColor) {
       int initcolor = image[sr][sc];
       vector<vector<int>> ans = image;
       
       dfs(sr,sc,ans,image,newColor,initcolor);
        return ans;
    }
};

int main(){
		
	vector<vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
	
// sr = 1, sc = 1, newColor = 2  	
	Solution obj;
	vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}