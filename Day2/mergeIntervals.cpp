//https://leetcode.com/problems/merge-intervals/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i+1][0]=min(intervals[i][0],intervals[i+1][0]);
                intervals[i+1][1]=max(intervals[i][1],intervals[i+1][1]);
                intervals[i][0]=intervals[i][1]=-1;
            }
        }
        for(int i=0;i<intervals.size();i++){
            vector<int> temp(2); temp[0]=intervals[i][0];
            temp[1]=intervals[i][1];
            if(temp[0]!=-1) ans.push_back(temp);
        }
        return ans;
    }
};
