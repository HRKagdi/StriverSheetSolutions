//https://leetcode.com/problems/ones-and-zeroes/



int dp[605][105][105];
class Solution {
public:
    pair<int,int> count(string s){
        int c0,c1; c0=c1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]-'0'==0) c0++;
            else c1++;
        }
        return {c0,c1};
    }
    int f(vector<string>& strs, int m, int n,int l){
        if(l==0) return 0;
        if(m==0 && n==0) return 0;
        if(dp[l][m][n]!=-1) return dp[l][m][n];
        pair<int,int>p=count(strs[l-1]);
        
        if(p.first<=m && p.second<=n){
            dp[l][m][n]=max(1+f(strs,m-p.first,n-p.second,l-1), f(strs,m,n,l-1));
        }
        else dp[l][m][n]=f(strs,m,n,l-1);
        return dp[l][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof dp);
        return f(strs,m,n,strs.size());
    }
};
