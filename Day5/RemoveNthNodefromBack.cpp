//https://leetcode.com/problems/remove-nth-node-from-end-of-list/


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        ListNode* temp=head; int c=0;
        while(temp!=NULL){
            temp=temp->next; c++;
        }
        if(c==n){head=head->next; return head;}
        c-=n+1;
        int a=0;temp=head;
        while(a!=c){
            temp=temp->next; a++;
        }
        temp->next=temp->next->next;
        return head;
    }
};
