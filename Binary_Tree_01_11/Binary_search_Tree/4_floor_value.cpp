class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        if(root == NULL) return 0;
        int floor=-1;
        while(root!=NULL){
            if(root->data == x) return root->data;
            else{
                if(root->data <x){
                    floor= root->data;
                    root= root->right;
                }
                else{
                    // floor= root->data;
                    root= root->left;
                }
            }
        }
        return floor;
    }
};