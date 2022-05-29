//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxi(int a,int b){
        if(a>b) return a;
        return b;
    }
    int maxProfit(vector<int>& nums) {
        int minTillnow=nums[0]; int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<minTillnow){
                minTillnow=nums[i];
            }
            if(nums[i]>minTillnow){
                ans=maxi(ans,nums[i]-minTillnow);
            }
        }
        return ans;
    }
};
