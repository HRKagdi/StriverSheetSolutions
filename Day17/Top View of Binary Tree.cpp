//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
   
    vector<int> topView(Node *root)
    {
        vector<int> ans; queue<pair<Node*,int>>q;
        map<int,int> m; int h=0;
        q.push({root,0});
        while(q.size()>0){
            Node*temp=q.front().first; 
            h=q.front().second; q.pop();
            if(m.find(h)==m.end()){
                m[h]=temp->data;
            }
            if(temp->left!=NULL){
                q.push({temp->left,h-1});
            }
            if(temp->right!=NULL){
                q.push({temp->right,h+1});
            }
        }
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }

};
