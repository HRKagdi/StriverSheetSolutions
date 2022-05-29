https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n0,n1,n2; n0=n1=n2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) n0++;
            else if(nums[i]==1) n1++;
            else n2++;
        }
        for(int i=0;i<n0;i++) nums[i]=0;
        for(int i=n0;i<n1+n0;i++) nums[i]=1;
        for(int i=n0+n1;i<nums.size();i++) nums[i]=2;
    }
};


