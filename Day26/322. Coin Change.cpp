//https://leetcode.com/problems/coin-change/



class Solution {
public:
    int f(vector<int>& coins, int amount,int l,vector<vector<int>>&dp){
        if(amount<=0) return 0;
        if(l==0) return INT_MAX-1;
        if(dp[l][amount]!=-1) return dp[l][amount];
        if(coins[l-1]<=amount){
            dp[l][amount]=min(1+f(coins,amount-coins[l-1],l,dp), f(coins,amount,l-1,dp));
        }
        else dp[l][amount]=f(coins,amount,l-1,dp);
        return dp[l][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans=f(coins,amount,coins.size(),dp);
        if(ans==INT_MAX-1) return -1;
        return ans;
    }
};
