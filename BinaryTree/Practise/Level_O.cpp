
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

   void levelOrderTraverse(Node* root){
    if(root== NULL) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int levelsize= q.size();
        for(int i =0; i<levelsize; i++){
            Node* currentNode= q.front();
            q.pop();
            cout<<currentNode->data<<" ";

            if(currentNode->left != NULL){
                q.push(currentNode->left);
            }
            if(currentNode->right != NULL){
                q.push(currentNode->right);
            }
        }
     }
   }

int main(){
   
   Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
   
   levelOrderTraverse(root);

 return 0;  
}