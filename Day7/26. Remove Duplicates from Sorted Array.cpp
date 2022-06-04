
//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x=0; int curr=nums[0]; 
        for(int i=1;i<nums.size();){
            if(nums[i]==curr) i++;
            else{
                nums[++x]=nums[i]; curr=nums[i]; i++; 
            }
        }
        //for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
        return x+1;
    }
};
