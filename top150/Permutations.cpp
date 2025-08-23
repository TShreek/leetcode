class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.empty()) return ret;
        vector<int> curr;
        unordered_set<int> visited;
        for(int i=0; i<nums.size(); i++){
            curr.push_back(nums[i]);
            visited.insert(nums[i]);

            backtrack(ret,nums,curr,visited);

            visited.erase(nums[i]);
            curr.pop_back();
        }
        return ret;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& nums, 
                    vector<int>& current,
                        unordered_set<int>& visited){
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }
        for(int j = 0;j<nums.size();j++){
            if(!visited.count(nums[j])){
                current.push_back(nums[j]);
                visited.insert(nums[j]);

                backtrack(result,nums,current,visited);

                visited.erase(nums[j]);
                current.pop_back();
            }
        }
    }
};
