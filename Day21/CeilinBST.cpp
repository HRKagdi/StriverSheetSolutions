//https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos




int findCeil(BinaryTreeNode<int> *node, int x){
	int ans=-1;
    while(node!=NULL){
        if(node->data==x) return x;
        if(node->data<x){
            node=node->right;
        }
        else{
            ans=node->data;
            node=node->left;
        }
    }
    return ans;
}
