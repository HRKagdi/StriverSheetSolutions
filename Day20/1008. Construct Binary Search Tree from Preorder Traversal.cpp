//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/



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
    TreeNode* helper(vector<int>& inorder,int il,int ir,vector<int>& preorder,
                    int pl,int pr,map<int,int>&m){
        
        if(il>ir || pl>pr) return NULL;
        TreeNode* root=new TreeNode(preorder[pl]);
        
        int iroot=m[root->val];
        int ileft=iroot-il;
        
        root->left = helper(inorder,il,iroot-1,preorder,pl+1,pl+ileft,m);
        root->right = helper(inorder,iroot+1,ir,preorder,pl+ileft+1,pr,m);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(), inorder.end());
        
        map<int,int> m; 
        for(int i=0;i<inorder.size();i++) m[inorder[i]]=i;
        
        return helper(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,m);
    }
};
