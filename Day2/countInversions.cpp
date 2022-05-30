//https://www.codingninjas.com/codestudio/problems/count-inversions_615


#include<bits/stdc++.h>
using namespace std;
long long int ans=0;
int merge(long long *arr,int l,int m,int r){
    vector<long long int>v1,v2;
     for(int i=0;i<=m;i++) v1.push_back(arr[i]);
     for(int j=m+1;j<=r;j++) v2.push_back(arr[j]);
     vector<long long int> v(r-l+1);
     int i=0; int j=0; int k=0;
     while(i<v1.size() && j<v2.size()){
        if(v1[i]>v2[j]){
            ans+=m-i-1; v[k++]=v2[j++];
        }else{
            v[k++]=v1[i++];
        }
    }
    while(i<v1.size()) v[k++]=v1[i++];
    while(j<v2.size()) v[k++]=v2[j++];
    for(int i=0;i<v.size();i++) arr[i]=v[i];
    return ans;
}
void mergeSort(long long *arr,int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
long long getInversions(long long *arr, int n){
    mergeSort(arr,0,n);
    return ans;
}
