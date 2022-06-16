//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void path(TreeNode*root,TreeNode*p,vector<TreeNode*>&v){
        if(root==NULL) return;
        v.push_back(root);
        if(root->val==p->val) return ;
        if(p->val<root->val) path(root->left,p,v);
        else path(root->right,p,v);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2; 
        path(root,p,v1); path(root,q,v2);
        int i=0; int j=0;

        while(i<v1.size() && j<v2.size()){
            if(v1[i]->val!=v2[j]->val) {
                return v1[i-1];
            }else{
                i++; j++;
            }
        }
        return v1[i-1];
    }
};
