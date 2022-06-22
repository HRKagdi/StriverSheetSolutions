//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1



class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int>adj[],int V,vector<bool>&vis,vector<int> &ans,int start){
        vis[start]=true;
        vector<int> v=adj[start];
        for(int i=0;i<v.size();i++){
            if(!vis[v[i]]){
                ans.push_back(v[i]); dfs(adj,V,vis,ans,v[i]);
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans; vector<bool> vis(V,false);
        ans.push_back(0);
        dfs(adj,V,vis,ans,0);
        return ans;
    }
};
