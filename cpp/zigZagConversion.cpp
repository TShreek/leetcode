class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows > s.length()){
            return s;
        }
        vector<string> row(numRows);
        int currentRow=0;
        bool goDown= false;
        
        for(char c : s){
            row[currentRow]+= c;
            
            if(currentRow == 0 || currentRow == numRows-1){
                goDown = !goDown;
            }
            
            currentRow += goDown? 1: -1;
        }
        
        string res = "";
        for(auto x : row){
            res+= x;
        }
        return res;
    }
};
