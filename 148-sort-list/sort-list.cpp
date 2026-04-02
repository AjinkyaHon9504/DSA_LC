class Solution {
public:

    // returns head of right half
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = NULL; // split here
        return mid;
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* t1 = head1;
        ListNode* t2 = head2;

        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while(t1 && t2){
            if(t1->val < t2->val){
                temp->next = t1;
                t1 = t1->next;
            } else {
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }

        if(t1) temp->next = t1;
        else temp->next = t2;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* mid = findMiddle(head);

        ListNode* left = head;
        ListNode* right = mid;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};