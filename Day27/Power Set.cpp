//https://practice.geeksforgeeks.org/problems/power-set4302/1#



class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string>ans; int n=s.size();
		    for(int i=0;i<pow(2,n);i++){
		        string temp="";
		        for(int j=0;j<n;j++){
		            if((1<<j)&i){
		                temp+=s[j];
		            }
		        }
		        if(temp.size()>0) ans.push_back(temp);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
