class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> positions = {-1,-1};
        int recent=-1;
        bool found = false;
        for(int i =0;i< nums.size();i++){
            if(nums[i] == target){
                if(!found) {positions[0] = i; found = true;}
                recent = i;
            }
        }
        positions[1] = recent;
        return positions;
    }
};
