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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // easy approCH GO TO algomonster

        // ek line ka concept smjho
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        while(ptrA != ptrB)
        {
            ptrA = (ptrA !=NULL) ? ptrA->next : headB;
            ptrB = (ptrB !=NULL) ? ptrB->next: headA;

        }

        return ptrA;
    }
};