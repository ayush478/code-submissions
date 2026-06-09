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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto& x : lists) {
            ListNode* temp = x;
            while (temp) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode* ans = new ListNode(-1);
        ListNode* dummy = ans;
        
        while (!pq.empty()) {
            dummy->next = new ListNode(pq.top());
            dummy=dummy->next;
            pq.pop();
        }
        return ans->next;
    }
};
