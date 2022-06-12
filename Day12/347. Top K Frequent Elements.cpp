//https://leetcode.com/problems/top-k-frequent-elements/

typedef pair<int,int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        for(auto it:mp){
            pq.push(make_pair(it.second,it.first));
            if(pq.size()>k) pq.pop();
        }
        for(int i=1;i<=k;i++){
            ans.push_back(pq.top().second); pq.pop();
        }
        return ans;
    }
};
