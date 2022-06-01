///https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> ans(2);
        for(int i=0;i<nums.size();i++) m[nums[i]]=i;
        for(int i=0;i<nums.size();i++){
            if(m[target-nums[i]]!=i && m[target-nums[i]]>0){
                ans[0]=i; ans[1]=m[target-nums[i]]; break;
            }
        }
        return ans;
    }
};
