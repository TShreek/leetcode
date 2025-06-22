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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;
        ListNode* current = head;

        int pos =1;
        stack<int> st;
        while(pos < left){
            current = current->next;
            pos++;
        }
        ListNode* temp = current;
        while(pos <= right){
            st.push(temp->val);
            temp = temp->next;
            pos++;
        }

        while(!st.empty()){
            current->val = st.top(); st.pop();
            current= current->next;
        }
        return head;
    }
};
