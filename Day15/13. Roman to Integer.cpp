
//https://leetcode.com/problems/roman-to-integer/


class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans=0; int i;
        for(i=0;i<s.size()-1;i++){
            if(s[i]=='I' && s[i+1]=='V') {ans+=4; i++;}
            else if(s[i]=='I' && s[i+1]=='X'){ans+=9; i++;}
            else if(s[i]=='X' && s[i+1]=='L'){ans+=40; i++;}
            else if(s[i]=='X' && s[i+1]=='C'){ans+=90;i++;}
            else if(s[i]=='C' && s[i+1]=='D'){ans+=400; i++;}
            else if(s[i]=='C' && s[i+1]=='M'){ans+=900; i++;}
            else ans+=m[s[i]];
        }
        if(i==s.size()-1) ans+=m[s[i]];
        return ans;
    }
};
