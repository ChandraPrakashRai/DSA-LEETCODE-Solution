/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    void deleteNode(ListNode* node) {
    
        //     // Copy value from next node
        // node->val = node->next->val;
        // // Skip over the next node
        // node->next = node->next->next;
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
        
    

    }
};