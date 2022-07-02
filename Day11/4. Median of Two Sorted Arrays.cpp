//https://leetcode.com/problems/median-of-two-sorted-arrays/



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double>v(nums1.size()+nums2.size()); int i,j,k; i=j=k=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]) v[k++]=nums1[i++];
            else v[k++]=nums2[j++];
        }
        while(i<nums1.size()) v[k++]=nums1[i++];
        while(j<nums2.size()) v[k++]=nums2[j++];
        if(v.size()%2==1) return v[v.size()/2];
        return (v[(v.size())/2-1]+v[v.size()/2])/2.0;
    }
};
