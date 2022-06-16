//https://leetcode.com/problems/symmetric-tree/



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
     void frl(TreeNode* root, vector<int>& v){
        if(root==NULL) {v.push_back(-1);return ;}
        v.push_back(root->val);
        frl(root->right,v);
        frl(root->left,v);
    }
    void flr(TreeNode* root, vector<int>& v){
        if(root==NULL) { v.push_back(-1); return ;}
        v.push_back(root->val);
        flr(root->left,v);
        flr(root->right,v);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> v1,v2;
        flr(root,v1);
        frl(root,v2);
        
        return (v1==v2);
    }
};
