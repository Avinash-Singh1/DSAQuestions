class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> stack;
        TreeNode* lastVisited = nullptr;

        while (!stack.empty() || root) {
            // Traverse left side of the tree
            if (root) {
                stack.push(root);
                root = root->left;
            } else {
                TreeNode* node = stack.top();
                // Check if we can visit the right child
                if (node->right && lastVisited != node->right) {
                    root = node->right;
                } else {
                    // Visit the node and mark it as visited
                    result.push_back(node->val);
                    lastVisited = node;
                    stack.pop();
                }
            }
        }

        return result;
    }
};
