class Solution {
public:
    bool divideArray(vector<int>& nums) {
        bool temp=true;
        unordered_map<int,int> hashMap;
        for(int num : nums){
            hashMap[num]++;
            temp = (hashMap[num] %2 == 0)? true : false;
        }
        return temp;
    }
};
