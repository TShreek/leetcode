class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()){
            return true;
        }
        int p1=0;
        for(int i=0;i<t.length();i++){
            if(t[i] == s[p1]){
                p1++;
            }
            if(p1 == s.length()){
                return true;
            }
        }
        return (p1 == s.length());
    }
};
