//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1



class Solution
{
    public:
    void inorder(Node*root,vector<int>&v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    int kthLargest(Node *root, int K)
    {
        vector<int> v; 
        inorder(root,v);
        return v[v.size()-K];
        
    }
};
