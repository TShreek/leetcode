class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;

        unordered_map<char,string> numMap = {
            {'2',"abc"},{'3',"def"},{'4',"ghi"},
            {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
            {'8',"tuv"},{'9',"wxyz"}
        };

        string current ="";
        int index =0;
        backtrack(index,res,digits,numMap,current);
        return res;
    }

    void backtrack(int index, vector<string>& res, string& digits, unordered_map<char,string>& numMap, string current){
        if(index == digits.size()){
            res.push_back(current);
            return;
        }

        char ch = digits[index];
        string letters = numMap[ch];
        for(char c : letters){
            current.push_back(c);
            backtrack(index+1,res,digits,numMap,current);
            current.pop_back();
        }
    }
};
