class Solution {
public:
    string reverseWords(string s) {
        string ret;
        stack<string> wordstack;
        string word;
        stringstream ss(s);

        while(ss >> word){
            wordstack.push(word);
        }
        while(!wordstack.empty()){
            ret += wordstack.top();
            wordstack.pop();
            if(!wordstack.empty()){
                ret+= " ";
            }
        }
        return ret;
    }
};
