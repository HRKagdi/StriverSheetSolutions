//https://leetcode.com/problems/partition-equal-subset-sum/



class Solution {
public:
    bool SS(vector<int>&nums,int sum,int l,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(l==0) return false;
        if(dp[l][sum]!=-1) return dp[l][sum];
        if(nums[l-1]<=sum){
            dp[l][sum]=SS(nums,sum-nums[l-1],l-1,dp) || SS(nums,sum,l-1,dp);
            
        }
        else dp[l][sum]=SS(nums,sum,l-1,dp);
        return dp[l][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum%2==1) return false;
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,-1));
        return SS(nums,sum/2,nums.size(),dp);
    }
};
