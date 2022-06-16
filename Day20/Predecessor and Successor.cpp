//https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1



void findPred(Node*root,Node*&pre){
    Node*temp=root->left;
    while(temp->right) temp=temp->right;
    pre=temp;
}
void findSucc(Node*root,Node*&suc){
    Node*temp=root->right;
    while(temp->left) temp=temp->left;
    suc=temp;
}
Node* helper(Node*root,int key){
    if(root==NULL) return NULL;
    if(root->key==key) return root;
    if(root->key<key) return helper(root->right,key);
    return helper(root->left,key);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    //Assumption: key is present in BST.
    Node*temp=helper(root,key);
   if(temp) findPred(temp,pre);
   if(temp) findSucc(temp,suc);
}
