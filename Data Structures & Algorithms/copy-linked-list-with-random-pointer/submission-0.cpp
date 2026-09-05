/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* ptr = head;
        while (ptr) {
            Node* nextNode = ptr->next;
            ptr->next = new Node(ptr->val);
            ptr->next->next = nextNode;
            ptr = nextNode;
        }

        ptr = head;
        while (ptr) {
            if (ptr->random) ptr->next->random = ptr->random->next;
            ptr = ptr->next->next;
        }

        ptr = head;
        Node* ans = ptr->next;
        while (ptr) {
            Node* copy = ptr->next;
            Node* nextNode = copy->next;

            copy->next = nextNode ? nextNode->next : NULL;
            ptr->next = nextNode;

            ptr = nextNode;
        }
        return ans;
    }
};
