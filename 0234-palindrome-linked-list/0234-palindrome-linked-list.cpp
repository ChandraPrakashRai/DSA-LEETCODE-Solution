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
    bool isPalindrome(ListNode* head) {
        // 2 step
        // 1. find middle 
        //2. reverse second half

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

        }

        // slow satnd at middle

        ListNode* prev = NULL;
        ListNode* curr = slow;
        
        while(curr)
        {
            ListNode* temp = curr->next;
          
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // match 
        ListNode* left = head;
        ListNode* right = prev;

        while(right)
        {
            if(left->val != right->val)
            return false;

            left = left->next;
            right = right->next;
        }

        return true;
    }
};