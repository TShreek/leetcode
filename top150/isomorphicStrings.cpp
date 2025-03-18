class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> hashS,hashT;
        if(s.length() != t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            char cS=s[i],cT=t[i];
            if((hashS.count(s[i]) && hashS[s[i]] != t[i]) || hashT.count(t[i]) && hashT[t[i]] != s[i]){
                return false;
            }
            hashS[s[i]] = t[i];
            hashT[t[i]] = s[i];
        }
        return true;
    }
};
