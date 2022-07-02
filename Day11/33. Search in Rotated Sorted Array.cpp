//https://leetcode.com/problems/search-in-rotated-sorted-array/



class Solution {
public:
    int findMaximum(vector<int>&arr, int n) {
	    if(n==1) return arr[0];
	    int l=0; int r=n-1;
	    while(l<=r){
	        int mid=l+(r-l)/2;
	        if(mid>0 && mid<n-1){
	            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
	            else if(arr[mid]<arr[mid-1]) r=mid-1;
	            else l=mid+1;
	        }else if(mid==0){
	            if(arr[0]>arr[1]) return 0;
	            else return 1;
	        }
	        else if(mid==n-1){
	            if(arr[n-1]>arr[n-2]) return n-1;
	            else return n-2;
	        }
	        
	    }
	    return arr[n-1];
	}
    int BS(vector<int>&arr,int l,int r,int tar){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==tar) return mid;
            else if(arr[mid]>tar) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            else return -1;
        }
        int pivot=findMaximum(nums,nums.size());
        int i1=BS(nums,0,pivot,target);
        if(i1!=-1) return i1;
        int i2=BS(nums,pivot+1,nums.size()-1,target);
        return i2;
    }
};
