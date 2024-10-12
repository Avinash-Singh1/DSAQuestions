#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V]={0};
        vis[0]=1;
        queue<int> q;
        q.push(0);
        vector<int>ans;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return ans;
        
    }
    vector<int> dfs(int V,vector<int> adj[]){
        int vis[V]={0};
        vector<int>ans;
        int start =0;
        dfs_helper(start,vis,ans,adj);
        return ans;
    }
    vector<int>dfs_helper(int start,int vis[],vector<int>&ans,vector<int> adj[]){
        vis[start]=1;
        ans.push_back(start);
        for(auto it: adj[start]){
            if(!vis[it])
            {
                dfs_helper(it,vis,ans,adj);
            }
        }
        return ans;
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}


int main() 
{
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);

    vector<int>answer=obj.dfs(5, adj);
    cout<<"\n";
    for(auto it: answer)
    {
        cout<<it<<" ";
    }



    return 0;
}