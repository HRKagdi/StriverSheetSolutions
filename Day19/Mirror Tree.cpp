//https://practice.geeksforgeeks.org/problems/mirror-tree/1



class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        if(root==NULL) return;

        if(root->left!=NULL && root->right!=NULL){
            Node*temp=root->left; root->left=root->right; root->right=temp;
        }
        else if(root->left==NULL && root->right!=NULL){
            root->left=root->right; root->right=NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            root->right=root->left; root->left=NULL;
        }
        mirror(root->left);
        mirror(root->right);
        
    }
};
