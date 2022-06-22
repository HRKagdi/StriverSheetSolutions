//https://leetcode.com/problems/is-graph-bipartite/



class Solution {
public:
    bool dfs(vector<vector<int>>&g,vector<int>&color,int s){
        if(color[s]==-1) color[s]=1;
        vector<int>adj=g[s];
        for(auto it:adj){
            if(color[it]==-1){
                color[it]=1-color[s];
                if(!dfs(g,color,it)) return false;
            }
            else{
                if(color[it]==color[s]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!dfs(graph,color,i)) return false;
            }
        }
        return true;
    }
};
