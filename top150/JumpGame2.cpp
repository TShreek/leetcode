/*
  You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i.
In other words, if you are at nums[i], you can jump to any nums[i + j] where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
  */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return 0;
        
        int jumps = 0;
        int maxReached=0;
        int currentEnd=0;
        
        for(int i=0;i<n;i++){
            maxReached = max(i+nums[i],maxReached);
            
            if(i >= currentEnd){
                jumps++;
                currentEnd = maxReached;
                if(currentEnd >= n-1){
                    return jumps;
                }
            }
        }
        return jumps;
        }
};
