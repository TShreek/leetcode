class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(hashMap.count(num)>0){
                return {i,hashMap[num]};
            }
            hashMap[target-num]=i;
        }
        return {};
    }
};
