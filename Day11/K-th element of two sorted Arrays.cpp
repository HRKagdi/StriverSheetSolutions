//https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1


class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int>v(n+m);  int i=0;int j=0; int p=0;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]) {v[p++]=arr1[i]; i++;} 
            else {v[p++]=arr2[j]; j++;}
        }
        while(i<n) v[p++]=arr1[i++];
        while(j<m) v[p++]=arr2[j++];
        return v[k-1];
    }
};
