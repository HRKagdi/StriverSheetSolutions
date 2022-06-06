//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#


class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n); sort(dep,dep+n);
        int i=1; int j=0; int ans=1; int plt=1;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                plt++; i++;
            }else if(arr[i]>dep[j]){
                plt--; j++;
            }
            ans=max(plt,ans);
        }
        return ans;
    }
};
