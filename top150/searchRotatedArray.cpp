class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int rot = -1;
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1]){
                rot = i;
                break;
            }
        }
        if(rot == -1) return binarySearch(nums,target,0,nums.size()-1);

        int retA = binarySearch(nums,target,0,rot);
        if(retA != -1) return retA;

        return binarySearch(nums,target,rot+1,nums.size()-1);
    }

    int binarySearch(vector<int>& nums, int target, int left, int right){
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
};
