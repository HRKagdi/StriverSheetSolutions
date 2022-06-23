//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1



#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    int minDis(vector<bool>&vis,vector<int>&dis){
        int distance=INT_MAX; int ans=0;
        for(int i=0;i<dis.size();i++){
            if(!vis[i] && dis[i]<=distance){
                distance=dis[i]; ans=i;
            }
        }
        return ans;
    }
    void helper(vector<pair<int,pair<int,int>>>&g,vector<bool>&vis,vector<int>&dis,int S){
        for(int i=0;i<vis.size();i++){
            int m=minDis(vis,dis);
            vis[m]=true; 
            for(int i=0;i<g.size();i++){
                if(g[i].second.first==m){
                    dis[g[i].second.second]=min(dis[g[i].second.second], dis[m]+g[i].first);
                }
            }
        }
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            vector<vector<int>> t=adj[i];
            for(int k=0;k<t.size();k++){
                edges.push_back({t[k][1],{t[k][0],t[k][2]}});
                edges.push_back({t[k][1],{t[k][2],t[k][0]}});

            }
        }
        vector<bool>vis(V,false); vector<int>dis(V,INT_MAX);
        dis[S]=0;
        helper(edges,vis,dis,S);
        return dis;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
