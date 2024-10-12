#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    bool detectcycle(int node, int vis[], vector<int> adj[]) {
       
       queue<pair<int,int>> q;
       q.push({node,-1});

       while (!q.empty())
       {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it: adj[node]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push({it,node});
                }
                else if( it!= parent) return true;
            }   
       }
       return false;
       
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0}; 
       // for graph with connected components 
       for(int i = 0;i<V;i++) {
           if(!vis[i]) {
               if(detectcycle(i, vis, adj) == true) return true; 
           }
       }
       return false; 
    }
};

int main() {
    
    // V = 4, E = 2
    // vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    vector<int> adj[4] = {{}, {2, 3}, {1, 3}, {1, 2}};

    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}