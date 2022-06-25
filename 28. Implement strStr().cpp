
//https://leetcode.com/problems/implement-strstr/


class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        if(haystack.size()<needle.size()) return -1;
        for(int i=0;i<haystack.size()-needle.size()+1;i++){
            bool b=true;
            for(int j=0;j<needle.size();j++){
                if(haystack[i+j]!=needle[j]) {b=false; break;}
            }
            if(b) return i;
        }
        return -1;
    }
};
