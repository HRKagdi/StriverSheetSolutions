//https://leetcode.com/problems/set-matrix-zeroes/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                   v.push_back(make_pair(i,j));
                }
            }
        }
        for(int i=0;i<v.size();i++){
            int r=v[i].first; int c=v[i].second;
            for(int j=0;j<matrix.size();j++){
                matrix[j][c]=0;
            }
            for(int j=0;j<matrix[0].size();j++){
                matrix[r][j]=0;
            }
        }
    }
};
