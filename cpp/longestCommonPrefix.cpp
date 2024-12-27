using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        string ret = strs[0];
        for(int i=1; i< strs.size(); i++){
            while(strs[i].find(ret) != 0){
                ret.pop_back();
                if(ret.empty()){
                    return "";
                }
            }
        }
        return ret;
    }
};
