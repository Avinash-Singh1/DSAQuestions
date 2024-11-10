/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        if(root == nullptr) return postorder;
        stack<TreeNode*>st,st2;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr =st.top();
            st.pop();

            st2.push(curr);
            if(curr->left!=nullptr){
                st.push(curr->left);
            }
             if(curr->right!=nullptr){
                st.push(curr->right);
            }
        }

        while(!st2.empty()){
            TreeNode* curr= st2.top();
            postorder.push_back(curr->val);
            st2.pop();

        }

        return postorder;
    }
};