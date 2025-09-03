class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int total =0;
       int maxSum = INT_MIN, curMax = 0;
       int minSum = INT_MAX, curMin = 0;

       for(int num : nums){
        total += num;

        curMax = max(num, curMax + num);
        maxSum = max(curMax, maxSum);

        curMin = min(num, curMin + num);
        minSum = min(minSum, curMin);
       }

       if(maxSum < 0) return maxSum;

       return max(maxSum, total - minSum);
    }
};


//Kadane 2
