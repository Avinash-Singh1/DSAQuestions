                            
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



class Solution {
public:
    // Function widthOfBinaryTree to find the 
    // maximum width of the Binary Tree
    int widthOfBinaryTree(TreeNode* root) {
        // If the root is null,
        // the width is zero
        if (!root) {
            return 0;
        }

        // Initialize a variable 'ans'
        // to store the maximum width
        int ans = 0;

        // Create a queue to perform level-order
        // traversal, where each element is a pair
        // of TreeNode* and its position in the level
        queue<pair<TreeNode*, int>> q;
        // Push the root node and its
        // position (0) into the queue
        q.push({root, 0});

        // Perform level-order traversal
        while (!q.empty()) {
            // Get the number of
            // nodes at the current level
            int size = q.size();
            // Get the position of the front
            // node in the current level
            int mmin = q.front().second;
            
            // Store the first and last positions 
            // of nodes in the current level
            int first, last;

            // Process each node
            // in the current level
            for (int i = 0; i < size; i++) {
                // Calculate current position relative
                // to the minimum position in the level
                int cur_id = q.front().second - mmin;
                // Get the current node
                TreeNode* node = q.front().first;
                // Pop the front node from the queue
                q.pop();

                // If this is the first node in the level, 
                // update the 'first' variable
                if (i == 0) {
                    first = cur_id;
                }

                // If this is the last node in the level,
                // update the 'last' variable
                if (i == size - 1) {
                    last = cur_id;
                }

                // Enqueue the left child of the 
                // current node with its position
                if (node->left) {
                    q.push({node->left, cur_id * 2 + 1});
                }

                // Enqueue the right child of the
                // current node with its position
                if (node->right) {
                    q.push({node->right, cur_id * 2 + 2});
                }
            }

            // Update the maximum width by calculating
            // the difference between the first and last
            // positions, and adding 1
            ans = max(ans, last - first + 1);
        }

        // Return the maximum
        // width of the binary tree
        return ans;
    }
};


int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    int maxWidth = sol.widthOfBinaryTree(root);

    cout << "Maximum width of the binary tree is: "
                        << maxWidth << endl;

    return 0;
}
                            
                        