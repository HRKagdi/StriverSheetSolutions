//https://leetcode.com/problems/next-greater-element-i/



class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    int k=j+1; bool b=false;
                    for(;k<nums2.size();k++){
                        if(nums2[k]>nums2[j]) {ans[i]=nums2[k];b=true; break;}
                    }
                    if(b) break;
                }
            }
        }
        return ans;
    }
};
