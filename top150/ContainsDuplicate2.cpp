class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        for(int i=0;i<nums.size();i++){
            if(hashMap.count(nums[i])>0){
                if(i - hashMap[nums[i]] <= k){
                    return true;
                }
            }
            hashMap[nums[i]]=i;
            if(hashMap.size()>k){
                hashMap.erase(nums[i-k]);
            }
        }
        return false;
    }
};
