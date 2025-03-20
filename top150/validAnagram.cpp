class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hashMap;
        if(s.length() != t.length()){
            return false;
        }
        for(char c : s){
            hashMap[c]++;
        }
        for(char c : t){
            hashMap[c]--;
            if(hashMap[c] < 0){
                return false;
            }
        }
        return true;
    }
};
