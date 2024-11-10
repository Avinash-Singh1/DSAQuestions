class Solution {
public:
    bool isSameTree(TreeNode* node1, TreeNode* node2) {
         if(node1 == NULL && node2 == NULL){
            return true;
        }
      
        if( node1== NULL || node2==NULL){
            return false;
        }
        
        return ((node1->val == node2->val)
            && isSameTree(node1->left, node2->left)
                && isSameTree(node1->right, node2->right));
    }
};