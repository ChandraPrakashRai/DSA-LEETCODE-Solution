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
        // Base case: if list is empty or left == right, no need to reverse
        if (!head || left == right) return head;

        // Step 1: Dummy node banate hai for safe edge case handling
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        // Step 2: 'prev' ko left-1 position pe le jao
        for (int i = 1; i < left; i++) {
            if (!prev) return nullptr;  // precaution
            prev = prev->next;
        }

        // Step 3: curr points to node at 'left'
        ListNode* curr = prev->next;

        // Step 4: Reverse nodes between left and right
        for (int i = 0; i < right - left; i++) {
            if (!curr || !curr->next) break;  // precaution
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        // Step 5: Return new head
        return dummy->next;
    }
};
