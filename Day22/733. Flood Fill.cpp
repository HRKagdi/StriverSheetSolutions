//https://leetcode.com/problems/flood-fill/



class Solution {
public:
    void dfs(vector<vector<int>>& img,int i,int j,int oldc,int newc){
        if(i<0 || j<0 || i>=img.size() || j>=img[0].size() || img[i][j]!=oldc) return;
        oldc=img[i][j];
        img[i][j]=newc;
        if(i-1>=0 && img[i-1][j]==oldc) dfs(img,i-1,j,oldc,newc);
        if(j-1>=0 && img[i][j-1]==oldc) dfs(img,i,j-1,oldc,newc);
        if(i+1<img.size() && img[i+1][j]==oldc) dfs(img,i+1,j,oldc,newc);
        if(j+1<img[0].size() && img[i][j+1]==oldc) dfs(img,i,j+1,oldc,newc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};
