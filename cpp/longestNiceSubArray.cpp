class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left=0,right=0,bitmask=0,maxS=0;
        while(right<nums.size()){
            while((bitmask & nums[right]) != 0){
                bitmask ^= nums[left];
                left++;
            }
            bitmask |= nums[right];
            maxS = max(right-left+1, maxS);
            right++;
        }
        return maxS;
    }
};
