//https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1



int dp[505][505];
class Solution{
public:
    bool isPalindrome(string& s,int l,int r){
        while(l<=r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    int PP(string &str,int i,int j){
        if(i>=j) return 0;
        if(isPalindrome(str,i,j)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int temp=1+PP(str,i,k)+PP(str,k+1,j);
            ans=min(ans,temp);
        }
        dp[i][j]=ans;
        return ans;
    }
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof dp);
        int i=0; int j=str.size()-1;
        return PP(str,i,j);
    }
};
