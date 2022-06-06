//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans=0; vector<pair<double,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]=make_pair(arr[i].value/arr[i].weight,i);
        }
        sort(v.rbegin(),v.rend()); int i=0;
        while(i<n && W>0){
            if(W>=arr[v[i].second].weight){W-=arr[v[i].second].weight; ans+=arr[v[i].second].value; i++;}
            else{ans+=v[i].first*W;
            i++; break;}
        }
        return ans;
    }
        
};
