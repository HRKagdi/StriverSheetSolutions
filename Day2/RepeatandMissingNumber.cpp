//https://www.codingninjas.com/codestudio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1


#include<bits/stdc++.h>
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int,int> p;
    sort(arr.begin(),arr.end());
    int temp=arr[0]; 
    long long sum=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]==arr[i-1]) p.second=arr[i];
        sum+=arr[i];
    }sum+=arr[0];
    long long ns=(n*(n+1))/2;
    long long a=abs(ns-sum);
    if(ns>sum) p.first=p.second+a;
    else p.first=p.second-a;
    return p;
}
