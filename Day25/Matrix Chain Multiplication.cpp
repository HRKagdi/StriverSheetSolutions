//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1



int dp[105][105];
class Solution{
public:
    int MCM(int arr[],int i,int j){
        if(i>=j){return 0;}
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp=MCM(arr,i,k)+MCM(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            ans=min(ans,temp);
        }
        dp[i][j]=ans;
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof dp);
        int i=1; int j=N-1;
        return MCM(arr,i,j);
    }
};
