//https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0; int r=matrix.size()*(matrix[0].size())-1;
        int a=matrix.size(); int b=matrix[0].size();
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target==matrix[mid/b][mid%b]) return true;
            else if(target>matrix[mid/b][mid%b]) l=mid+1;
            else r=mid-1;
        }
        return false;
    }
};
