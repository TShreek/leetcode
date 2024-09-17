/*
A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.
  */

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
      unordered_map<string, int> wordcount;
        vector<string> result;
        
        auto countWords = [&](string &s){
            stringstream ss(s);
            string word;
            while(ss >> word){
                wordcount[word]++;
            }
        };
        
        countWords(s1);
        countWords(s2);
        
        for(const auto& entry : wordcount){
            if(entry.second == 1){
                result.push_back(entry.first);
            }
        }
        return result;
    }
};
    
