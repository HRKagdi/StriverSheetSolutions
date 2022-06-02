//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1


class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        map<int,int> m;
        int sum=0; int maxi=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                maxi=i+1;
            }
            else {
                if(m.find(sum)!=m.end())
                    maxi=max(maxi,i-m[sum]);
                else{
                    m[sum]=i;
                }
            }
        }
        return maxi;
        
    }
};
