/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/
class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k , nums.end());
    }
};
