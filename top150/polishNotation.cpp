class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token : tokens){
            if(token == "/" || token =="*" || token =="-" || token == "+"){
                int a = st.top();st.pop();
                int b = st.top();st.pop();
                
                if (token == "+") st.push(b + a);
                else if (token == "-") st.push(b - a);
                else if (token == "*") st.push(b * a);
                else if (token == "/") st.push(b / a);  // assuming integer division
            } else {
                st.push(stoi(token));  // convert number string to int
            }
        }
        return st.top();
    }
};
