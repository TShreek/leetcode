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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;

        stack<int> st;
        int count =0;

        ListNode* left = head;
        ListNode* right = head;

        while(right != nullptr){
            while(right != nullptr && count<k){
                st.push(right->val);
                right=right->next;
                count++;
            }
            if(count <k) break;
            while(left != right){
                left->val = st.top();
                st.pop();
                left=left->next;
            }
            count=0;
        }
        return head;
    }
};
