#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    if (!root) return {};
	map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode<int>*, pair<int, int>>> todo;

    todo.push({root, {0, 0}});

    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        TreeNode<int>* temp = p.first;

        int x = p.second.first;  // x coordinate
        int y = p.second.second; // y coordinate (level)

        // Insert the node's data into the appropriate vertical and level
        nodes[x][y].insert(temp->data);

        // Process left child
        if (temp->left) {
            todo.push({temp->left, {x - 1, y + 1}});
        }

        // Process right child
        if (temp->right) {
            todo.push({temp->right, {x + 1, y + 1}});
        }
    }

    vector<int> col;
    // Collect the results in vertical order
    for (auto p : nodes) {
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
    }

    return col;

}