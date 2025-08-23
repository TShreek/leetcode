class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(1, n, k, curr, res);
        return res;
    }
    void backtrack(int start, int n, int k,
                   vector<int>& curr,
                   vector<vector<int>>& res) {
        // Base case: picked k numbers
        if ((int)curr.size() == k) {
            res.push_back(curr);
            return;
        }

        int need = k - (int)curr.size();               // how many more to pick
        // Prune: ensure enough numbers remain to finish
        for (int i = start; i <= n - need + 1; ++i) {
            curr.push_back(i);                          // choose
            backtrack(i + 1, n, k, curr, res);         // explore
            curr.pop_back();                            // un-choose
        }
    }
};
