//https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int gl,cl; gl=cl=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1) { cl++;}
            else if(nums[i]==nums[i-1]){
                continue;
            }else{
                gl=max(gl,cl); cl=1;
            }
        }
        gl=max(gl,cl);
        return gl;
    }
};
