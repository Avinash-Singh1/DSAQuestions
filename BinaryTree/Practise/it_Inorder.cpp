
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

   vector<int> It_Inorder(Node* root){
    vector<int> Inorder;
    
    if(root== NULL) Inorder;
    stack<Node*> st;
    Node* temp = root;
    while (true)
    {
        if(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()) break;
            temp = st.top();
            st.pop();
            Inorder.push_back(temp->data);
            temp = temp->right;
        }
    }
    return Inorder;
   }

int main(){
   
   Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);
    root->left->right->left= new Node(6);
    root->left->right->right= new Node(7);

    // root->right->left = new Node(6); 
    // root->right->right = new Node(7); 
   
   vector<int> result = It_Inorder(root);
   for(auto i: result){
    cout<<i<<" ";
   }

 return 0;  
}