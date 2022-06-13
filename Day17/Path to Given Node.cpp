
//https://www.interviewbit.com/problems/path-to-given-node/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode*root,int B,map<int,int>&par){
    if(root==NULL) return;
    if(root->left!=NULL) par[root->left->val]=root->val;
    if(root->right!=NULL) par[root->right->val]=root->val;
    helper(root->left,B,par);
    helper(root->right,B,par);
}
vector<int> Solution::solve(TreeNode* A, int B) {
    map<int,int>par; //par[A->val]=A->val;
    helper(A,B,par);
    vector<int> ans;
    ans.push_back(B);
    int temp=B; 
    while(temp!=A->val){
        temp=par[temp];
        ans.push_back(temp);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
