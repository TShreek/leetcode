using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int minLen = INT_MAX, maxLen = 0;
        for(string& w : wordDict){
            minLen = min(minLen, (int)w.size());
            maxLen = max(maxLen, (int)w.size());
        }

        int n = s.size();
        vector<char> dp(n+1,false);
        dp[0]= true;

        for(int i =1; i<= n;i++){
            int jstart = max(0, i-maxLen);
            int jend = i - minLen;
            for(int j = jstart; j <= jend; j++){
                if(!dp[j]) continue;
                if(dict.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
