class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> numSet(nums.begin(),nums.end());
        int longest=0;
        for(int num : numSet){
            int n=num;
            int current=0;
            if(numSet.find(n-1) == numSet.end()){
                while(numSet.find(n) != numSet.end()){
                    current++;
                    n+=1;
                }
                longest = max(longest, current);
            }
        }
        return longest;
    }
};
