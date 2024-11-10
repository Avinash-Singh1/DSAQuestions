int helper(BinaryTreeNode<int> *root,int &maxi){
    if(root==NULL) return 0;
    int l_s = max(0,helper(root->left,maxi));
    int r_s = max(0,helper(root->right,maxi));
    maxi=max(maxi,l_s+r_s+root->data);
    return  max(r_s,l_s)+root->data;

}
int maxPathSum(BinaryTreeNode<int> *root)
{
    // Write your code here4
     int maxi=INT_MIN;
    helper(root,maxi);
    return maxi;

}