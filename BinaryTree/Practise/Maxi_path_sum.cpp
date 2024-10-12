
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
int maxiHelper(Node* root, int& maxi){
    if(root == nullptr){return 0;}
    int lfsum=max(0,maxiHelper(root->left,maxi));
    int rhtsum=max(0,maxiHelper(root->right,maxi));

    maxi =max(maxi,lfsum+rhtsum+root->data);
    return max(lfsum,rhtsum)+ root->data;
}
int maxiPathSum(Node* root){
    int maxi= INT_MIN;
    return maxiHelper(root,maxi);
}

int main(){
   
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    int result = maxiPathSum(root);
    cout << "Maximum path sum is " << result << endl;
   
 return 0;  
}