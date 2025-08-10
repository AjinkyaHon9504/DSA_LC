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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // 0 or 1 node

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // keep start of even list

        while (even && even->next) {
            odd->next = even->next;   // link odd to next odd
            odd = odd->next;          // move odd pointer
            even->next = odd->next;   // link even to next even
            even = even->next;        // move even pointer
        }

        odd->next = evenHead; // connect odd list to even list
        return head;
    }
};
