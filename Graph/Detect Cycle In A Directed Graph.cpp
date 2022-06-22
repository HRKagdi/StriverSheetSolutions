//https://www.codingninjas.com/codestudio/problems/1062626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website



bool dfs(vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&dfsvis,int start){
    vis[start]=true;
    dfsvis[start]=true;
    vector<int> v=adj[start];
    for(auto it:v){
        if(!vis[it]){
            if(dfs(adj,vis,dfsvis,it)) return true;
        }else if(vis[it] && dfsvis[it]) return true;
    }
    dfsvis[start]=false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<bool>vis(n+1,false),dfsvis(n+1,false);
      vector<vector<int>> adj(n+1);
      for(int i=0;i<edges.size();i++){
          adj[edges[i].first].push_back(edges[i].second);
      }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(adj,vis,dfsvis,i)) return 1;
        }
    }
    return 0;
}
