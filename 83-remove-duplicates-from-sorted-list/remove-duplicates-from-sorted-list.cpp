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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
         ListNode* nayi = head;

         while(nayi && nayi->next){
            if(nayi->val == nayi->next->val){
                ListNode* temp =nayi->next;
                nayi->next=nayi->next->next;
                delete temp;
            }
            else{
                nayi=nayi->next;
            }

         }
         return head;
    }
};