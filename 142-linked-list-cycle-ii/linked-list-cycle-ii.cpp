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
    ListNode *detectCycle(ListNode *head) {
        //** Using Slow and Fast Pointer  **//

       ListNode* slow = head;
       ListNode* fast = head;


       while(fast && fast->next)
       {
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast)
            {
                ListNode* p = head;
                 
                while(p!=slow)
                {
                   p = p->next;
                slow = slow->next;
                }
                return p;
               
            }

          
           
       }

       return NULL;
    }
};