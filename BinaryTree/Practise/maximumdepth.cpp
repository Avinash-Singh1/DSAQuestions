
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

int maxdepth(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    int lh = maxdepth(root->left);
    int rh = maxdepth(root->right);
    return 1+max(lh,rh);

}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(5);

    int result = maxdepth(root);
    cout<<"Result: "<<result<<endl;
    
   
   
   
 return 0;  
}