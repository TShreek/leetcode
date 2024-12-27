using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> RomanValues{
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int num=0;
        int len = s.length();
        for(int i=0; i< len; i++){
            if(i < len - 1 && RomanValues[s[i]] < RomanValues[s[i+1]]){
                num -= RomanValues[s[i]];
            }
            else{
                num += RomanValues[s[i]];
            }
        }
        return num;
    }
};
