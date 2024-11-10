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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            // long long position= q.front().second;   --- position
            long long first ,last;



            for(int i =0;i<size;i++){
                // long long cur_ind= q.front().second - position;  -- no use of position
                long long cur_ind= q.front().second;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0){
                    first =cur_ind;
                }
                if(i==size-1){
                    last =cur_ind;
                }
                if(node->left) q.push({node->left,cur_ind * 2+ 1});
                if(node->right) q.push({node->right,cur_ind * 2+ 2});
            }

            ans = max(ans, static_cast<int>(last - first + 1));
        }
        return ans;
    }
};