//https://www.codingninjas.com/codestudio/problems/chess-tournament_981299?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0



#include<bits/stdc++.h>
using namespace std;
bool canPut(vector<int>& positions , int n ,  int c,int dist){
    int temp=positions[0]; int cnt=1;
    for(int i=1;i<n;i++){
        if(positions[i]-temp>=dist){
            cnt++; temp=positions[i];
        }
        if(cnt==c) return true;
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
    sort(positions.begin(),positions.end());
    int low=1; int high=positions[n-1]-positions[0];
    int ans;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canPut(positions,n,c,mid)){
            ans=mid; low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}
