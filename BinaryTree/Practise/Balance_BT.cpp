
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
     int data;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int data1){
        this->data=data1;
        this->left=nullptr;
        this->right=nullptr;
     }
};
int checkHelper(TreeNode* root){
    if(root == NULL) return 0;

    int lh = checkHelper(root->left);
        if(lh== -1) return -1;

    int rh = checkHelper(root->right);

    if(rh== -1) return -1;
    if(abs(lh-rh)>1) return -1;
    return max(lh,rh)+1;
}
bool Check(TreeNode* root){
    return checkHelper(root) !=-1;
}

int main(){
   
  TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(30);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->left->right->right->right = new TreeNode(7);


     // Checking if the tree is balanced
    // if (Check(root)) {
    //     cout << "The tree is balanced." << endl;
    // } else {
    //     cout << "The tree is not balanced." << endl;
    // }
    cout<<Check(root)<<endl;


   
 return 0;  
}