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
    ListNode* sortList(ListNode* head) {
        // base case
        // it may be a chance that there exit only one node or not any node 
        if(head==NULL || head->next==NULL)
        return head;

        // break the list into two seperate list like it become easy to make merge sort
        // use fast and slow pointer 

        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // make two seperate l1 and l2
        // l1 start from head 
        // l2 start from slow->next
        // and make slow->next = none 
        // like break the connection and make two seperate list 
        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = NULL;

        // now recursively sort both halves
        l1 = sortList(l1);
        l2 = sortList(l2);

        // now make a dummy node to manage the empty list
        // so that insertion become simple

        ListNode* dummyNode = new ListNode(0);
        ListNode* tailNode = dummyNode;

        // now insert value into this
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                tailNode->next = l1;
                l1 = l1->next;
            }
            else
            {
                tailNode->next = l2;
                l2 = l2->next;
            }
            tailNode = tailNode->next;
        }
        // if any list l1 or l2 remain then attach with the end of the other one
        tailNode->next = l1 ? l1 : l2;
        // make a new node that point the next node of the dummyNode;
        ListNode* res = dummyNode->next;
        delete dummyNode;
        return res;
    }
};