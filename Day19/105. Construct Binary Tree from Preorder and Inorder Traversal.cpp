//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


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
    TreeNode* helper(vector<int>& preorder,int pl,int pr,
                    vector<int>& inorder,int il,int ir,map<int,int>&m){
        
        if(pl>pr || il>ir) return NULL;
        TreeNode*root=new TreeNode(preorder[pl]);
        int iroot=m[root->val];
        int numleft=iroot-il;
        
        root->left=helper(preorder,pl+1,pl+numleft,inorder,il,iroot-1,m);
        root->right=helper(preorder,pl+numleft+1,pr,inorder,iroot+1,ir,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
    }
};
