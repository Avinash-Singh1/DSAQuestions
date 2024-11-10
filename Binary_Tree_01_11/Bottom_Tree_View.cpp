class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(root== NULL) return ans;
        // ind, node
        map<int,int>mpp;
        
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node * node = it.first;
            int ver_index= it.second;
            
            mpp[ver_index]=node->data;
            
            if(node->left){
                q.push({node->left,ver_index-1});
            }
          
            
            if(node->right){
                q.push({node->right,ver_index+1});
            }
        }
        
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        
        return ans;
        
        
    }
};