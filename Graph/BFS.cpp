//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1



class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(vector<int>adj[],vector<bool>&vis,vector<int>&ans,int V, int start){
         queue<int> q; q.push(start); vis[start]=true;
         while(q.size()>0){
            int st=q.front(); q.pop();
            ans.push_back(st);
            vector<int> curr=adj[st];
            for(auto it: curr){
                if(!vis[it]){ 
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans; 
        vector<bool> vis(V,false); 
        bfs(adj,vis,ans,V,0);
        return ans;
    }
};
