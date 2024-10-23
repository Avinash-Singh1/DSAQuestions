class Solution {
  public:
    bool dfs(int node,int vis[],int path[],vector<int> adj[]){
        vis[node]=1; path[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
               if(dfs(it,vis,path,adj)==true)return true;
            }else if(path[it]){
                return true;
            }
        }
        path[node]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // DFS code here
        // int vis[V]={0}; int path[V]={0};
        
        // for(int i =0;i<V;i++){
        //     if(!vis[i]){
        //       if(dfs(i,vis,path,adj)==true)return true;
        //     }
        // }
        // return false;
        
        // DFS code ends here
         
         // BFS code ends here
           // khans algo solution  BFS start
	   
	   int indegree[V]={0};
	   for(int i =0;i<V;i++){
	       for(auto it: adj[i]){
	           indegree[it]++;
	       }
	   }
	   
	   queue<int>q;
	     for(int i =0;i<V;i++){
	      if(indegree[i]==0){
	          q.push(i);
	      }
	   }
	   vector<int> ans;
	   
	   while(!q.empty()){
	       
	       int node = q.front();
	       q.pop();
	       ans.push_back(node);
	       for(auto it: adj[node]){
	           indegree[it]--;
	           if(indegree[it]==0){
	               q.push(it);
	           }
	       }
	       
	   }
	   if(ans.size()==V) return false;
	   return true;
	   	   // khans algo solution  BFS ends
        
    }
};