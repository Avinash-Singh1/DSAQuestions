#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfsResult) {
   vis[node]=1;
   dfsResult.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj, dfsResult);
        }
    }

}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int>vis(V,0);
    int start = 0;
    vector<int> dfsResult; 
    dfs(start,vis,adj,dfsResult);
    return dfsResult;
     
}

int main() {
    int V = 5;  // Number of vertices

    // Adjacency list for the graph
    vector<int> adj[V];

    // Adding edges to the adjacency list (undirected graph)
    adj[0].push_back(1); // 0: {1,2}
    adj[0].push_back(2);
    adj[1].push_back(0); // 1: {0,3}
    adj[1].push_back(3);
    adj[2].push_back(0); // 2: {0,4}
    adj[2].push_back(4);
    adj[3].push_back(1); // 3: {1,}
    adj[4].push_back(2); // 4: {2, }

    // Perform DFS
    vector<int> result = dfsOfGraph(V, adj);

    // Output the DFS traversal result
    cout << "DFS Traversal: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
