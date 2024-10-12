
#include <bits/stdc++.h>
using namespace std;
class solution{
    public: 
    vector<int> bfsOfGraph(int v,vector<int> adj[]){
        int vis[v]={0};
        vis[0]=1;
        queue<int> q;

        q.push(0);
        vector<int>result;

        while(!q.empty()){
            int  node =q.front();
            q.pop();
            result.push_back(node);

            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return result;
    }
};
void addedge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
int main(){
   
 vector<int> adj[6];

 addedge(adj,0,1);
 addedge(adj,1,2);
 addedge(adj,1,3);
 addedge(adj,0,4);
 solution obj;
 vector<int> ans= obj.bfsOfGraph(5,adj);
 printAns(ans);

   
 return 0;  
}