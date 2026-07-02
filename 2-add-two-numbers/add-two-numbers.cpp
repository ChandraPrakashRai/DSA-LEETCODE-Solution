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

   
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        int carry = 0;
        ListNode* dummyHead = new ListNode(-1);

        ListNode* curr = dummyHead;

        while(l1!=NULL || l2!=NULL|| carry!=0 )
        {
            int digit1 = (l1==NULL)?0:l1->val;
            int digit2 = (l2==NULL)?0:l2->val;

            int sum = digit1 + digit2 + carry;

            carry = sum/10;

            curr->next = new ListNode(sum%10);


              curr = curr->next;

            // Move to next nodes in input lists if they exist
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        return dummyHead->next;
    }
};