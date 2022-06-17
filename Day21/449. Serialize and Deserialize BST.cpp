//https://leetcode.com/problems/serialize-and-deserialize-bst/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(TreeNode*root,string &str){
        if(root==NULL) return;
        str+=to_string(root->val)+",";
        preorder(root->left,str);
        preorder(root->right,str);
    }
    string serialize(TreeNode* root) {
        string str=""; preorder(root,str);
        return str;
    }

    TreeNode* helper(vector<int>&ino,int il,int ir,vector<int>&pre,int pl,int pr,map<int,int>&m){
        if(il>ir || pl>pr) return NULL;
        
        TreeNode*temp=new TreeNode(pre[pl]);
        int iroot=m[temp->val];
        int ileft=iroot-il;
        
        temp->left=helper(ino,il,iroot-1,pre,pl+1,pl+ileft,m);
        temp->right=helper(ino,iroot+1,ir,pre,pl+ileft+1,pr,m);
        return temp;
        
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> pre,ino;
        string temp="";
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                int x=stoi(temp); 
                pre.push_back(x);
                temp="";
            }else{
                temp+=data[i];
            }
        }
        ino=pre; sort(ino.begin(),ino.end());
        map<int,int> m;
        for(int i=0;i<ino.size();i++) m[ino[i]]=i;
        
        return helper(ino,0,ino.size()-1,pre,0,pre.size()-1,m);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
