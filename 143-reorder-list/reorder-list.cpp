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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;

        }

        ListNode *sec = slow->next;
        slow->next=nullptr;
        ListNode* prev= nullptr;

        while(sec){
            ListNode* tmp = sec->next;
            sec->next=prev;
            prev=sec;
            sec=tmp;
        }

        ListNode* first = head;
        sec=prev;
        while(sec){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = sec->next;

            first->next = sec;
            sec->next=tmp1;

            first = tmp1;
            sec= tmp2;
        }
    }
};
