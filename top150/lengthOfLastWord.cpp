class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0){
            return 0;
        }
        int length=0;
        int tempLen=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                if(tempLen > 0){
                    length=tempLen;
                }
                tempLen=0;
            }
            else{
                tempLen++;
            }
        }
        return tempLen>0? tempLen : length;
    }
};
