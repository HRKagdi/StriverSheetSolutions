//https://leetcode.com/problems/combination-sum/


class Solution {
public:
    void helper(vector<int>&c,int tar,int ind,int n,set<vector<int>>&s,vector<int>v){
        if(n==0 || tar<0) return;
        if(tar==0) {s.insert(v); return;}
        if(c[ind]<=tar){
            v.push_back(c[ind]);
            helper(c,tar-c[ind],ind,n,s,v);
            v.pop_back();
        }
        helper(c,tar,ind+1,n-1,s,v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        set<vector<int>>s; vector<int> v;
        helper(candidates,target,0,candidates.size(),s,v);
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};
