/*
  
  */
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long max = 0;
        unordered_map<int,int> FreqMap;
        long long sum=0;
        for(int i=0, j=0;j< nums.size();j++)
        {
            FreqMap[nums[j]]++;
            sum += nums[j];
            
            while(FreqMap[nums[j]] > 1 || j + 1 - i > k)
            {
                FreqMap[nums[i]]--;
                sum -= nums[i];
                i++;
            }
            if(j - i + 1 == k)
            {
                max = std::max(sum,max);
            }
        }
        return max;
    }
};
