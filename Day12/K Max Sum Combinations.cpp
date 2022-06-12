//https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


#include<bits/stdc++.h>
using namespace std;
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
       vector<int> ans;
       priority_queue<int> pq;
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               pq.push(a[i]+b[j]);
           }
       }
       for(int i=1;i<=k;i++){
           ans.push_back(pq.top()); pq.pop();
       } 
       return ans;
}
