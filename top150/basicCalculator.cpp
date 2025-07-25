class Solution {
public:
    int calculate(string s) {
        int result=0,sign=1,num=0;
        stack<int> st;

        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }
            else if(c == '+'){
                result += sign * num;
                sign=1;
                num=0;
            }
            else if(c == '-'){
                result += sign * num;
                sign = -1;
                num = 0;
            }
            else if(c == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if(c == ')'){
                result += sign * num;
                num=0;
                int prevSign = st.top();st.pop();
                int prevResult = st.top();st.pop();
                result = prevResult + prevSign * result;
            }
            else if(c == ' '){
                continue;
            }
        }
        result += sign*num;
        return result;
    }
};
