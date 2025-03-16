class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> hashMap;
        for(int i =0;i<magazine.length();i++){
            hashMap[magazine[i]] += 1;
        }
        for(int j=0;j<ransomNote.length();j++){
            char c = ransomNote[j];
            if(hashMap[c] > 0 ){
                hashMap[c]--;
            }
            else{
                return false;
            }
        }
    return true;
    }
};
