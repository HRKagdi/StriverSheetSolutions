
//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1


void helper(Node*root,int l,vector<int>&ans){
    if(root==NULL) return;
    if(l<0) return;
    if(l==0) ans.push_back(root->data);
    helper(root->left,l-1,ans);
    helper(root->right,l-1,ans);
}
int height(Node*root){
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    int h=height(root);
    for(int i=0;i<h;i++){
        helper(root,i,ans);
    }
    return ans;
}
