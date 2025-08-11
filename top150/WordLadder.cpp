class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 0;

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;

        static const char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'};

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        if(dict.count(beginWord)) dict.erase(beginWord);

        while(!q.empty()){
            auto [curr, len] = q.front(); q.pop();
            if(curr == endWord) return len;
            for(int i = 0; i<curr.length() ;i++){
                char c = curr[i];

                for(char a : letters){
                    if(c == a) continue;
                    curr[i] = a;
                    if(dict.count(curr)){
                        dict.erase(curr);
                        q.push({curr,len+1});
                    }
                }
                curr[i] = c;
            }
        }
        return 0;
    }
};
