/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* current=head;
        unordered_map<Node*, Node*> hashM;
        while(current != nullptr){
            hashM[current] = new Node(current->val);
            current = current->next;
        }
        
        current = head;
        while( current != nullptr){
            hashM[current]->next = hashM[current->next];
            hashM[current]->random = hashM[current -> random];
            current = current->next;
        }
        return hashM[head];
    }
};
