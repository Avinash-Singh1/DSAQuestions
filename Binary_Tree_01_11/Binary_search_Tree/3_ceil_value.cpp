
int findCeil(BinaryTreeNode<int> *root, int x){
    // Write your code here.
    if(root == NULL) return 0;
    int ceil=-1;
    while(root!=NULL){

        if(root->data == x){
            ceil=root->data;
            return ceil;
        }else{
            if(root->data <x){
                root =root->right;
            }
            else{
                ceil =root->data;
                root= root->left;
            }
        }
    }
    return ceil;
}

// arr[] = {1, 2, 5, 7, 8, 9}, key = 3.
// The closest integer greater than 3 in the given array is 5.
//  So, its ceil value in the given array is 5.