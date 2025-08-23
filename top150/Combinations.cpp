class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(1, n, k, path, res);
        return res;
    }

private:
    void dfs(int start, int n, int k,
             vector<int>& path,
             vector<vector<int>>& res) {
        // Base case: picked k numbers
        if ((int)path.size() == k) {
            res.push_back(path);
            return;
        }
        // Base case: ran out of numbers to pick
        if (start > n) return;

        // Try every next number i from start..n (no pruning)
        for (int i = start; i <= n; ++i) {
            path.push_back(i);           // choose
            dfs(i + 1, n, k, path, res); // explore
            path.pop_back();             // un-choose
        }
    }
};
