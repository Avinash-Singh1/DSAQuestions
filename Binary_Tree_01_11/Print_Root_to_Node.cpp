class Solution {
  public:
   void f(Node* root,vector<vector<int>> &res, vector<int>&ds){
       
       ds.push_back(root->data);
       if(root->left!=NULL){
           f(root->left,res,ds);
       }
       if(root->right!=NULL){
           f(root->right,res,ds);
       }
       
      if(root->left==NULL && root->right == NULL) res.push_back(ds);
       ds.pop_back();
   }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>res;
        if(root == NULL) return res;
        vector<int>ds
        f(root,res,ds);
        return res;
    }
};