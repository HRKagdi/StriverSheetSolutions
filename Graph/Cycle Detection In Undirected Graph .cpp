
//https://www.codingninjas.com/codestudio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


#include<bits/stdc++.h>
using namespace std;
bool bfs(vector<vector<int>>&adj,vector<bool>&vis,int par,int start){
    queue<pair<int,int>>q; q.push({start,par});
    while(q.size()>0){
        pair<int,int> curr=q.front(); q.pop();
        vector<int> t=adj[curr.first];
        for(auto it:t){
            if(!vis[it]) {vis[it]=true;q.push({it,curr.first});}
            else{
                if(it!=curr.second) return true;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
      vector<bool>vis(n+1,false);
      vector<vector<int>> adj(n+1);
      for(int i=0;i<m;i++){
          adj[edges[i][0]].push_back(edges[i][1]);
          adj[edges[i][1]].push_back(edges[i][0]);
      }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(bfs(adj,vis,-1,i)) return "Yes";
        }
    }
    return "No";
}
