class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node,vector<int> adj[],int vis[],stack<int> &st){
	    vis[node]=1;
	    
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   
	   // int vis[V]={0};
	   // stack<int>st;
	   // for(int i=0;i<V;i++){
	   //     if(!vis[i]){
	   //         dfs(i,adj,vis,st);
	   //     }
	   // }
	    
	   // vector<int>ans;
	   // while(!st.empty()){
	   //     ans.push_back(st.top());
	   //     st.pop();
	   // }
	   // return ans;
	    
	   // khans algo solution 
	   
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
	   return ans;
	   
	  
	}
};