
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node * right;

    Node(int data1){
        this->data= data1;
        this->left= NULL;
        this->right= NULL;
    }
};

   vector<int> It_preorder(Node* root){
    vector<int> preorder;
    
    if(root== NULL) preorder;
    stack<Node*> st;
    st.push(root);
    while (!st.empty())
    {
        Node * temp = st.top();
        st.pop();
        preorder.push_back(temp->data);
        if(temp->right != NULL){
            st.push(temp->right);
        }
        if(temp->left != NULL){
            st.push(temp->left);
        }

    }
    return preorder;
   }

int main(){
   
   Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(7); 
    root->left->left = new Node(3); 
    root->left->right = new Node(4);
    root->left->right->left= new Node(5);
    root->left->right->right= new Node(6);

    // root->right->left = new Node(6); 
    // root->right->right = new Node(7); 
   
   vector<int> result = It_preorder(root);
   for(auto i: result){
    cout<<i<<" ";
   }

 return 0;  
}