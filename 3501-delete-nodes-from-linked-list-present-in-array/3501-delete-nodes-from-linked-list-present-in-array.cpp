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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin()  , nums.end());

        while(head!=NULL && st.find(head->val)!=st.end())
        {
                head = head->next;
        }

        ListNode* curr = head;

        while(curr!=NULL && curr->next!=NULL)
        {
            if(st.count(curr->next->val))
            {
                curr->next = curr->next->next;
                // curr = head;
            }
            else
            {
                curr = curr->next;
            }

        }


        return head;

    }
};