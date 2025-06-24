class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Put values into a queue
        queue<int> q;
        ListNode* current = head;
        int length = 0;

        while (current) {
            q.push(current->val);
            current = current->next;
            length++;
        }

        // Step 2: Normalize k
        k = k % length;

        // Step 3: Rotate the queue
        for (int i = 0; i < length - k; i++) {
            int front = q.front(); q.pop();
            q.push(front);
        }

        // Step 4: Reassign the values to the list
        current = head;
        while (!q.empty()) {
            current->val = q.front(); q.pop();
            current = current->next;
        }

        return head;
    }
};
