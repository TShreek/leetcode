class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.empty()) return result;
        
        vector<int> current;

        for(int i= 0;i<candidates.size();i++){
            int num = candidates[i];
            if(num <= target){
            current.push_back(num);
            backtrack(candidates,current,result,target,num,i);
            current.pop_back();
            }
        }

        return result;
    }

    void backtrack(vector<int>& candidates, vector<int>& current, vector<vector<int>>& result ,const int& target, int sum, int index){
        if(sum == target){
            result.push_back(current);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(sum + candidates[i] <= target){
                sum += candidates[i];
                current.push_back(candidates[i]);
                backtrack(candidates,current,result,target,sum,i);
                current.pop_back();
                sum-= candidates[i];
            }
        }
        return;
    }
};
