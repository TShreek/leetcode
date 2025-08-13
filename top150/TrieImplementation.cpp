using namespace std;

class Trie final{
private:
    struct Node{
        array<unique_ptr<Node> ,26> child{};
        bool isEnd = false;
    };

    unique_ptr<Node> root_;

    static int toInt(char ch){
        if(ch >= 'a' && ch <= 'z') return ch - 'a';
        return -1;
    }

    const Node* traverse(const string& s){
        const Node* cur = root_.get();
        for(char c : s){
            int idx = toInt(c);
            if(idx < 0 || !cur->child[idx]) return nullptr;
            cur = cur->child[idx].get();
        }
        return cur;
    }
public:
    Trie() : root_(make_unique<Node>()) {}

    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;
    Trie(Trie&&) = default;
    Trie& operator=(Trie&&) = default;
    
    void insert(string word) {
        Node* cur = root_.get();
        for(char ch : word){
            int idx = toInt(ch);
            if(idx < 0 ) return;
            if(!cur->child[idx]) {
                cur->child[idx] = make_unique<Node>();
            }
            cur = cur->child[idx].get();
        }
        cur->isEnd = true;
    }
    // Returns true if word was previously inserted
    bool search(string word) {
        const Node* node = traverse(word);
        return node && node->isEnd;
    }
    // Returns true if any inserted word starts with prefix
    bool startsWith(string prefix) {
        return traverse(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
