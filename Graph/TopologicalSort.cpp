
//https://practice.geeksforgeeks.org/problems/topological-sort/1



class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(vector<int>adj[],vector<bool>&vis,vector<int>&order,int V,int start){
	    vis[start]=true;             
	    vector<int> curr=adj[start];
	    for(auto it:curr){
	        if(!vis[it]){
	            dfs(adj,vis,order,V,it);
	        }
	    }
	    order.push_back(start);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>vis(V,false); vector<int>order;
	    for(int i=0;i<V;i++){
	        if(!vis[i]) dfs(adj,vis,order,V,i);
	    }
	    reverse(order.begin(),order.end());
	    return order;
	}
};
