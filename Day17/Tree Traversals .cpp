
//https://www.codingninjas.com/codestudio/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
vector<int> inorder,preorder,postorder;
void Inorder(BinaryTreeNode<int> *root){
	if(root!=NULL){
        Inorder(root->left);
        inorder.push_back(root->data);
        Inorder(root->right);
    }
}
void Preorder(BinaryTreeNode<int> *root){
	if(root!=NULL){
        preorder.push_back(root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
void Postorder(BinaryTreeNode<int> *root){
	if(root!=NULL){
        Postorder(root->left);
        Postorder(root->right);
        postorder.push_back(root->data);
    }
}


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> ans;
    
   	Inorder(root); Preorder(root); Postorder(root);
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    inorder.clear(); preorder.clear(); postorder.clear();
    return ans;
    
}
