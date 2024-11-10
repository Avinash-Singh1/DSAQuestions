                            
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to perform zigzag level
    // order traversal of a binary tree
    vector<vector<int>> ZigZagLevelOrder(Node* root){
        // Vector to store the
        // result of zigzag traversal
        vector<vector<int>> result;
        
        if(root == NULL){
            return result;
        }
       
        queue<Node*> nodesQueue;
        nodesQueue.push(root);
        
    
        bool leftToRight = true;
        
     
        while(!nodesQueue.empty()){
           
            int size = nodesQueue.size();
            
            vector<int> row(size);
            
          
            for(int i = 0; i < size; i++){
              
                Node* node = nodesQueue.front();
                nodesQueue.pop();
                
               
                int index = leftToRight ? i : (size - 1 - i);
                
              
                row[index] = node->data;
                
                // Enqueue the left and right
                // children if they exist
                if(node->left){
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }
            }
            
            // Switch the traversal
            // direction for the next level
            leftToRight = !leftToRight;
            
            // Add the current level's
            // values to the result vector
            result.push_back(row);
        }
        
        // Return the final result of
        // zigzag level order traversal
        return result;
    }
};



// Helper function to print the result
void printResult(const vector<vector<int>>& result) {
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the zigzag level order traversal
    vector<vector<int>> result = solution.ZigZagLevelOrder(root);

    // Print the result
    printResult(result);

    return 0;
}
                            
                        