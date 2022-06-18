//https://leetcode.com/problems/longest-common-prefix/



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int l=INT_MAX;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<l){
                l=strs[i].size();
            }
        }
        int i;
        for(i=0;i<l;i++){
            char ch=strs[0][i]; bool b=true;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=ch){
                    b=false; break;
                }
            }
            if(!b) break;
        }
        return strs[0].substr(0,i);
    }
};
