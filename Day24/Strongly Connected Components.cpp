//https://www.codingninjas.com/codestudio/problems/985311?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website



void topSort(vector<vector<int>>&edges,int start,vector<bool>&vis,vector<int>&order){
    vis[start]=true;
    for(int i=0;i<edges.size();i++){
        if(edges[i][0]==start && !vis[edges[i][1]]){
            topSort(edges,edges[i][1],vis,order);
        }
    }
    order.push_back(start);
}
void dfs(vector<vector<int>> &edges, vector<bool>&vis,vector<int>&temp,int s){
    vis[s]=true;
    temp.push_back(s);
    for(int i=0;i<edges.size();i++){
        if(edges[i][0]==s && !vis[edges[i][1]]){
            dfs(edges,vis,temp,edges[i][1]);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    //Kosaraju's Algo
    //Step 1: Topological Sort.
    vector<bool>vis(n,false); vector<int>order;
    for(int i=0;i<edges.size();i++){
        if(!vis[edges[i][0]]){
            topSort(edges,edges[i][0],vis,order);
        }
        if(!vis[edges[i][1]]){
            topSort(edges,edges[i][1],vis,order);
        }
    }
    reverse(order.begin(),order.end());
    //Step 2: Transposing of graph.
    for(int i=0;i<edges.size();i++){
        int temp=edges[i][0]; edges[i][0]=edges[i][1]; edges[i][1]=temp;
    }
    
    //Step 3: DFS Traversal
    for(int i=0;i<vis.size();i++) vis[i]=false;
    for(int i=0;i<order.size();i++){
        if(!vis[order[i]]){
            vector<int> temp;
            dfs(edges,vis,temp,order[i]);
            ans.push_back(temp);
        }
    }
    return ans;
}
