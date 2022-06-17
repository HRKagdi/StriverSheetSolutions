//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bs(TreeNode*root,int target){
        if(root==NULL) return NULL;
        if(root->val==target) return root;
        else if(root->val>target) return bs(root->left,target);
        return bs(root->right,target);
    }
    bool helper(TreeNode*root,TreeNode*curr,int K){
        if(curr==NULL) return false;
        TreeNode*temp=bs(root,K-curr->val);
        if(temp!=NULL && curr!=temp) return true;
        return helper(root,curr->left,K) || helper(root,curr->right,K);
    }
    bool findTarget(TreeNode* root, int k) {
        return helper(root,root,k);
    }
};
