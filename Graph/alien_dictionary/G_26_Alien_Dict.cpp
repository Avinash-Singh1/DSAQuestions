
class Solution {
  public:
    vector<int> toposort(int V,vector<int> adj[]){
        int indegree[V];
        
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        
        for(int i=0;i<V;i++){
            
               if(indegree[i]==0)q.push(i);
        }
        
        vector<int>topo;
        
        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return topo;
    }
    string findOrder(string dict[], int n, int k) {
        // code here
        vector<int> adj[k];
         // adj build start
        for(int i=0;i<n-1;i++){
            string s1 =dict[i];
            string s2 =dict[i+1];
            int len= min(s1.size(),s2.size());
            
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        // adj build end
        
        vector<int>topo= toposort(k,adj);
        string ans = "";
		for (auto it : topo) {
			ans = ans + char(it + 'a');
		}
		return ans;
        
	
        
    }
};