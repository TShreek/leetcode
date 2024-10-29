class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        vector<int> ret;
        for(int num : nums1)
        {
            
            map[num]++;
        }
        for(int num : nums2)
        {
            if(map[num]>0)
            {
                ret.push_back(num);
                map[num] = 0;
            }
        }
        return ret;
    }
};
