
//https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         map<int,int> m; vector<int> v;
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        for(auto it:m){
            if(it.second>nums.size()/3) v.push_back(it.first); 
        }
        return v;
    }
};
