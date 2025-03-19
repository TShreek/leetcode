class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> sToP;
        unordered_map<char,string> pToS;
        vector<string> words;
        stringstream ss(s);
        string word;
        
        while(ss >> word){
            words.push_back(word);
        }
        if(pattern.length()!= words.size()){
            return false;
        }
        for(int i=0;i<pattern.length();i++){
            string cS = words[i];
            char cP = pattern[i];
            if((sToP.count(cS) && sToP[cS] != cP) || (pToS.count(cP) && pToS[cP] != cS) ){
                return false;
            }
            else{
                sToP[cS]= cP;
                pToS[cP] = cS;
            }
        }
        return true;
    }
};
