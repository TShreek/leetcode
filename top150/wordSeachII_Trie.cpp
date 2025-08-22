class Solution {
private:
    struct Node{
        array<unique_ptr<Node>,26> child{};
        bool isEnd = false;
        string word;
    };

    unique_ptr<Node> root;

    static int toInt(char c){
        return (c >= 'a' && c <= 'z')? c - 'a' : -1;
    }

    void addWord(const string& word){
        Node* cur = root.get();
        for(char ch : word){
            int chIndex = toInt(ch);
            if(chIndex < 0) return;
            if(!cur->child[chIndex]){ cur->child[chIndex] = make_unique<Node>(); }
            cur = cur->child[chIndex].get(); 
        }    
        cur->isEnd = true;
        cur->word = word;
    }

    void boardDfs(vector<vector<char>>& board, int r, int c, Node* node, vector<string>& out){
        char ch = board[r][c];
        int chIndex = toInt(ch);
        if(chIndex < 0 || !node->child[chIndex]) return;

        node = node->child[chIndex].get();
        if(node->isEnd){
            out.push_back(node->word);
            node->isEnd = false;
        }

        board[r][c] = '#';

        int m = board.size(), n = board[0].size();

        if(r > 0 && board[r-1][c] != '#') boardDfs(board,r-1,c,node,out);
        if(r < m-1 && board[r+1][c] != '#') boardDfs(board,r+1,c,node,out);
        if(c > 0 && board[r][c-1] != '#') boardDfs(board,r,c-1,node,out);
        if(c < n-1 && board[r][c+1] != '#') boardDfs(board,r,c+1,node,out);

        board[r][c] = ch; 
    }

public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = make_unique<Node>();
        for(const auto& w : words) addWord(w);
        
        vector<string> result;
        result.reserve(words.size());

        if(board.empty() || board[0].empty()) return result;

        int m = board.size();
        int n = board[0].size();

        for(int i =0;i<m;i++){
            for(int j = 0;j <n;j++){
                boardDfs(board,i,j,root.get(),result);
            }
        }
        return result;
    }
};
