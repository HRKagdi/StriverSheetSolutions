//https://leetcode.com/problems/linked-list-cycle-ii/


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
        ListNode*slow,*fast; slow=fast=head;
        while(true){
            if(fast==NULL || fast->next==NULL || slow->next==NULL)return NULL;
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {
                ListNode* temp=head;
                while(slow!=temp){
                    slow=slow->next;
                    temp=temp->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};
