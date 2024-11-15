/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
  */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n,1); 
        
        int left = 1;
        for(int i=0;i< n;i++){
            ret[i] = left;
            left *= nums[i];
        }
        
        int right = 1;
        for(int i = n-1; i>=0; i--){
            ret[i] *= right;
            right *= nums[i];
        }
        
        
        return ret;
    }
};
