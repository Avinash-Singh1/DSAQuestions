// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Structure of the
// node of a binary tree
struct Node {
	int data;
	struct Node *left, *right;

	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

// Function to print all nodes of a
// binary tree in Preorder, Postorder
// and Inorder using only one stack
void allTraversal(Node* root)
{

    
	vector<int>pre,in,post;
    stack<pair<Node*,int>>st;
    st.push({root,1});

    while(!st.empty()){
            auto it = st.top();
            st.pop();

            if(it.second==1){

                pre.push_back(it.first->data);
                it.second=2;
                st.push(it);
                if(it.first->left!=NULL){
                    st.push({it.first->left,1});
                }  
            }
            else if(it.second==2){

                in.push_back(it.first->data);
                it.second=3;
                                st.push(it);

                if(it.first->right!=NULL){
                    st.push({it.first->right,1});
                }  
            }
            else{
                post.push_back(it.first->data);
                // st.pop();
            }

    }

	cout << "Preorder Traversal: ";
	for (int i = 0; i < pre.size(); i++) {
		cout << pre[i] << " ";
	}
	cout << "\n";

	// Printing Inorder
	cout << "Inorder Traversal: ";

	for (int i = 0; i < in.size(); i++) {
		cout << in[i] << " ";
	}
	cout << "\n";

	// Printing Postorder
	cout << "Postorder Traversal: ";

	for (int i = 0; i < post.size(); i++) {
		cout << post[i] << " ";
	}
	cout << "\n";
}

// Driver Code
int main()
{

	// Creating the root
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	// Function call
	allTraversal(root);

	return 0;
}
