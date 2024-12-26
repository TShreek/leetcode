using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        
        unordered_map<char, int> charCount;
        int start=0,longest=0;
        
        for(int i = 0; i<s.length() ;i++){
            charCount[s[i]]++;
            
            if(charCount[s[i]] > 1){
               while(charCount[s[i]] > 1){
                charCount[s[start]]--;
                start++;
               }
            }
            
            longest = max(longest, i-start+1);
        }
        
        return longest;
    }
};
