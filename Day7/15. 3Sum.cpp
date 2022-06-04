//https://leetcode.com/problems/3sum/


class Solution {
public:
   
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m; set<vector<int>> s;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++; if(nums[i]==0) cnt++;
        }
        if(cnt==nums.size()){
            vector<int>t(3); ans.push_back(t);
            return ans;
        }
        for(int i=0;i<nums.size();i++){
            m[nums[i]]--;
            for(int j=i+1;j<nums.size();j++){
                m[nums[j]]--;
                int target=-1*(nums[i]+nums[j]);
                if(m[target]>0){
                    vector<int> v(3); v[0]=nums[i]; v[1]=nums[j];
                    v[2]=target; sort(v.begin(),v.end());
                    s.insert(v);
                }
                m[nums[j]]++;
            }
            m[nums[i]]++;
        }
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};
