class WordDictionary {
private:
    struct Node{
        array<unique_ptr<Node>,26> child{};
        bool isEnd = false;
    };

    unique_ptr<Node> root;

    static int toInt(char c){
        if(c >= 'a' && c <= 'z') return c - 'a';
        return -1;
    }


    bool dfs(const string& word, int index, const Node* node) const {
        if(!node) return false;
        if(index == word.size()) return node->isEnd;

        char ch = word[index];
        if(ch == '.'){
            for(const auto& next : node->child){
                if (next && dfs(word, index+1, next.get())) return true;
            }
            return false;
        }
        else{
            int chIndex = toInt(ch);
            if(chIndex < 0) return false;
            const auto& next = node->child[chIndex];
            if(!next) return false;
            return dfs(word,index+1,next.get());            
        }
    }
public:
    WordDictionary() {
        root = make_unique<Node>();
    }
    
    void addWord(string word) {
        Node* cur = root.get();
        for(char ch : word){
            int index = toInt(ch);
            if(index < 0 ) return;
            if(!cur->child[index]) cur->child[index] = make_unique<Node>();
            cur = cur->child[index].get();
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word,0,root.get());
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
