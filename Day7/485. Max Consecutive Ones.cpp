//https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0; int t=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                t=1; i++;
                while(i<nums.size() && nums[i]==1) {i++; t++;}
                ans=max(ans,t);
            }else{
                t=0;
            }
        }
        ans=max(ans,t);
        return ans;
    }
};
