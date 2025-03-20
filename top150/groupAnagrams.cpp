class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> retMap;
        vector<vector<string>> ret;

        for(string str : strs){
            string sorted_str = str;
            sort(sorted_str.begin(),sorted_str.end());
            retMap[sorted_str].push_back(str);
        }

        for(auto& group : retMap){
            ret.push_back(group.second);
        }
        return ret;
    }
};
