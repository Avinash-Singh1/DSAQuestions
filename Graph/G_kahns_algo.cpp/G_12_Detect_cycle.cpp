#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
  bool dfs(int node,int parent, vector<int> adj[], int vis[]) {
      vis[node]=1;
      for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,node,adj,vis)==true) return true;
        }
        else if (it!=parent)return true;
      }

      return false;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // initialise them as unvisited 
        int vis[V]={0};
        for (int i = 0; i < V; i++)
        {
            if(!vis[i]){
                if(dfs(i,-1,adj,vis)==true) return true;
            }
        }
        
    }
};

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}