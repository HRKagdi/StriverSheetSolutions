//https://leetcode.com/problems/subsets-ii/


class Solution {
public:
    void helper(vector<int>&nums,int l,vector<int>v,int n,set<vector<int>>&s){
        if(n==0){sort(v.begin(),v.end()); s.insert(v); return;}
        helper(nums,l+1,v,n-1,s);
        v.push_back(nums[l]);
        helper(nums,l+1,v,n-1,s);   
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> v;
        helper(nums,0,v,nums.size(),s);
        vector<vector<int>> ans;
        for(auto it: s){
            ans.push_back(it);
        }
        return ans;
    }
};
