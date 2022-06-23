//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1



#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int parent(vector<int>&par,int w){
        int temp=w;
        while(temp!=par[temp]){
            temp=par[temp];
        }
        return temp;
    }
    void unionFind(vector<int>&par,int a,int b){
        int t1=parent(par,a);
        int t2=parent(par,b);
        par[t2]=par[t1];
    }
	int kruskal(vector<pair<int,pair<int,int>>>&edges,int V){
	    int ans=0;
	    vector<int>par(V);
	    for(int i=0;i<V;i++) par[i]=i;
	    for(int i=0;i<edges.size();i++) {
	        if(parent(par,edges[i].second.first)!=parent(par,edges[i].second.second)){
	            ans+=edges[i].first;
	            unionFind(par,parent(par,edges[i].second.first),parent(par,edges[i].second.second));
	        }
	    }
	    return ans;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            vector<vector<int>> t=adj[i];
            for(int k=0;k<t.size();k++)
                edges.push_back(make_pair(t[k][1], make_pair(i,t[k][0])));
        }
        sort(edges.begin(),edges.end());
        return kruskal(edges,V);
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
