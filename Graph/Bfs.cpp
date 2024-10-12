#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS Function (as defined in the question)
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
 vector<int> vis(V,0);
 vector<int> bfs;
 queue<int> q;

 vis[0]=1;
 q.push(0);

 while(!q.empty())
 {
    int  node =q.front();
    q.pop();
    bfs.push_back(node);

    for(auto it: adj[node])
    {
        if(!vis[it]){
            vis[it]=1;
            q.push(it);
        }
    }
 }
 return bfs;

}

int main() {
    int V = 5;  // Number of vertices

    // Adjacency list for the graph
    vector<int> adj[V];

    // Adding edges to the adjacency list (undirected graph)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);

    // Perform BFS
    vector<int> result = bfsOfGraph(V, adj);

    // Output the BFS traversal result
    cout << "BFS Traversal: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
