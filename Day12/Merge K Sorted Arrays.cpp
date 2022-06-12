//https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> ppi;
vector<int> mergeKSortedArrays(vector<vector<int>>&Arrays, int k)
{
    vector<int> ans;
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    for(int i=0;i<Arrays.size();i++){
        pq.push(make_pair(Arrays[i][0], make_pair(i,0)));
    }
    while(pq.size()>0){
        ppi top=pq.top(); pq.pop();
        
        int row=top.second.first;
        int col=top.second.second;
        
        ans.push_back(top.first);
        
        if(col+1<Arrays[row].size()){
            pq.push(make_pair(Arrays[row][col+1], make_pair(row,col+1)));
        }
    }
    return ans;
}
