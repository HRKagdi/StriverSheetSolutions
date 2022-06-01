
//https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<long long int,int> m; vector<vector<int>> ans; set<vector<int>> s;
        if(nums.size()<4) return ans;
        long long tar=target;
        for(int i=0;i<nums.size();i++) m[nums[i]]=i;
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                for(int k=j+1;k<nums.size()-1;k++){
                    if(m[tar-nums[i]-nums[j]-nums[k]]>0
                       && m[tar-nums[i]-nums[j]-nums[k]]>k){
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[k]);
                        t.push_back(tar-nums[i]-nums[j]-nums[k]);
                        sort(t.begin(),t.end());
                        s.insert(t);
                    }
                }
            }
        }
        for(auto x:s) ans.push_back(x);
        return ans;
    }
};
