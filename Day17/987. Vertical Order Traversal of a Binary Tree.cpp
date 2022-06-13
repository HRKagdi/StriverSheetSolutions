//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/



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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       vector<vector<int>> ans; map<int,vector<int>> m;
        queue<pair<TreeNode*,int>>q; int h=0;
        q.push({root,0});
        while(q.size()>0){
            TreeNode*temp=q.front().first;
            h=q.front().second;
            q.pop();
            m[h].push_back(temp->val);
            if(temp->left!=NULL){
                q.push({temp->left,h-1});
            }
            if(temp->right!=NULL){
                q.push({temp->right,h+1});
            }
        }
        for(auto it:m){
            vector<int> temp=it.second;
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};
