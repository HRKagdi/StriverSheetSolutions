//https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website



#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void sortStack(stack<int> &s){
    stack<int> stk; int l=s.size();
    for(int i=0;i<l;i++){
        int mini=INT_MAX;
        while(s.size()>i){
            mini=min(mini,s.top());
            stk.push(s.top()); s.pop();
        }
        s.push(mini);
        while(stk.size()>0){
            if(stk.top()==mini){stk.pop();}
            else{
                s.push(stk.top()); stk.pop();
            }
        }
    }
}
