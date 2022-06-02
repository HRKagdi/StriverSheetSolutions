//https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int k)
{
    int cnt=0; long long int xr=arr[0]; 
    map<long long int,int> m; m[arr[0]]++;
    for(int i=1;i<arr.size();i++){
        xr=xr^arr[i];
        if(xr==k){
            cnt++;
        }
        if(m.find(xr^k)!=m.end()){
            cnt+=m[xr^k];
        }
         m[xr]+=1;
    }
    return cnt;
}
