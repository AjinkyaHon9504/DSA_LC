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
        //if fast->next == slow then or 
        if(!head || !head->next) return NULL;
        ListNode * slow = head;
        ListNode * fast = head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                //find starting pt
                ListNode * open = head;

                while(open!=slow){
                      open= open->next;
                      slow=slow->next;

                      
                }

                return open;
              
            }

        
    }
    return NULL;}
};