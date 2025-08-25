class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n < 1) return result;
        string path;
        dfs(result,path,n,0,0);
        return result;
    }

    void dfs(vector<string>& result, string& path, const int& n, int open, int close){
        if(path.size() == 2 * n){
            result.push_back(path);
            return;
        }
        if(open < n){
            path.push_back('(');
            dfs(result,path,n,open+1,close);
            path.pop_back();
        }
        if(close < open){
            path.push_back(')');
            dfs(result,path,n,open,close+1);
            path.pop_back();
        }
    }
};
