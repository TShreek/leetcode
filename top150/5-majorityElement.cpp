/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. - WHERE N is size of array
You may assume that the majority element always exists in the array.
  */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int,int> countMap;
        int majority=nums.size()/2;
        
        for(int num : nums){
            countMap[num]++;
            if(countMap[num] > majority)
                return num;
            
        }
        return -1;
    }
};
