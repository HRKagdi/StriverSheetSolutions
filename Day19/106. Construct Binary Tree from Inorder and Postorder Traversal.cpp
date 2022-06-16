//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


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
    TreeNode* helper(vector<int>& postorder,int pl,int pr,vector<int>& inorder,
                     int il,int ir,map<int,int>&m){
        
        if(il>ir || pl>pr) return NULL;
        TreeNode* root=new TreeNode(postorder[pr]);
        
        int iroot=m[root->val];
        int numsLeft=iroot-il;
        
          root->left=helper(postorder,pl,pl+numsLeft-1,inorder,il,iroot-1,m);
          root->right=helper(postorder,pl+numsLeft,pr-1,inorder,iroot+1,ir,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;
        return helper(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,m);
    }
};
