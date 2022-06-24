//https://www.interviewbit.com/problems/distinct-numbers-in-window/



vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int,int>m; vector<int>ans(A.size()-B+1);
    for(int i=0;i<B;i++){
        m[A[i]]++;
    }
    ans[0]=m.size();  int k=1;
    for(int i=B;i<A.size();i++){
        m[A[i-B]]--; if(m[A[i-B]]==0) m.erase(A[i-B]);
        m[A[i]]++;
        ans[k++]=m.size();
    }
    return ans;
}
