
//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans; map<int,vector<int>>m;
        queue<pair<Node*,int>>q; int h=0;
        q.push({root,0});
        while(q.size()>0){
            Node*temp=q.front().first;
            h=q.front().second;
            q.pop();
            m[h].push_back(temp->data);
            if(temp->left){
                q.push({temp->left,h-1});
            }
            if(temp->right){
                q.push({temp->right,h+1});
            }
        }
        for(auto it:m){
            vector<int> temp=it.second;
            ans.push_back(temp[temp.size()-1]);
        }
        return ans;
    }
};
