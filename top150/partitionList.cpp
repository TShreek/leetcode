/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        queue<int> less;
        queue<int> gE;

        ListNode* current = head;
        while(current != nullptr){
            if(current->val < x){
                less.push(current->val);
            }
            else{
                gE.push(current->val);
            }
            current=current->next;
        }
        current=head;
        while(!less.empty()){
            current->val = less.front();
            less.pop();
            current=current->next;
        }
        while(!gE.empty()){
            current->val = gE.front();
            gE.pop();
            current=current->next;
        }

        return head;
    }
};
