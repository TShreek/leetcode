/*
Given a string expression of numbers and operators, 
return all possible results from computing all the different possible ways to group numbers and operators.
You may return the answer in any order.
The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104
  */
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') {
                            result.push_back(l + r);
                        } else if (c == '-') {
                            result.push_back(l - r);
                        } else if (c == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }
        
        if (result.empty()) {
            result.push_back(stoi(expression));
        }
        
        return result;
    }
};
