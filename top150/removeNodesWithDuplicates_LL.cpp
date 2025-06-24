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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0,head);
        ListNode* prevN = dummy;
        ListNode* current = head;
        while(current  && current->next){
            if(current->val == current->next->val){
                int preVal = current->val;
                while(current && current->val == preVal){
                    current = current->next;
                }
                prevN ->next = current;
            }
            else{
                prevN =current;
                current=current->next;
            }
        }
        return dummy->next;
    }
};
