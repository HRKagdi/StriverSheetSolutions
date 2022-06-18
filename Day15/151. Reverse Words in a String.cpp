//https://leetcode.com/problems/reverse-words-in-a-string/



class Solution {
public:
    string reverseWords(string s) {
        string ans=""; string temp=""; 
        int i=s.size()-1;
        while(s[i]==' ') i--;
        for(;i>=0;i--){
            if(s[i]==' '){
                reverse(temp.begin(),temp.end());
                ans+=temp; ans+=" "; temp="";
                while(i>=0 && s[i]==' ') i--;
                i++;
            }else{
                temp+=s[i];
            }
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        if(ans[ans.size()-1]==' '){
            ans.erase(ans.size()-1,1);
        }
        return ans;
    }
};
