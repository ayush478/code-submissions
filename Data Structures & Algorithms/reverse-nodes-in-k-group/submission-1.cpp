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
        ListNode* cursor = head;

        for (int i = 0; i < k; i++) {  // check if k nodes exist
            if (cursor == NULL) {
                return head;
            }
            cursor = cursor->next;
        }

        ListNode *curr = head, *prev = NULL, *nxt = NULL;

        for (int i = 0; i < k; i++) {  // reverse exactly k nodes
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        head->next = reverseKGroup(curr, k);  // head is now the tail of this group
        return prev;                          // prev is the new head of this group
    }
};
