using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left =0;
        int right=0;
        int minimum=INT_MAX;
        int sum=0;
        for(right = 0; right< nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                minimum = min(minimum,right-left+1);
                sum -= (nums[left]);
                left++;
            }
        }
        return (minimum != INT_MAX)? minimum : 0;
    }
};
