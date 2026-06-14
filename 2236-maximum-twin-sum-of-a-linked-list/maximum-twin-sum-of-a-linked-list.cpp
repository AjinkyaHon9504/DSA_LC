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
    int pairSum(ListNode* head) {
        vector<int>v;
        ListNode * temp = head;

        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int twinsum=0;
        int n = v.size();
        int samplesize = v.size()/2 - 1;
        for(int i=0;i<=samplesize;i++){
            twinsum = max(twinsum,v[i]+v[n-1-i]);
        }
        return twinsum;
    }
};