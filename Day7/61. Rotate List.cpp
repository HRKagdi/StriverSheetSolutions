//https://leetcode.com/problems/rotate-list/description/


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
    int length(ListNode*head){
        int ans=0;
        while(head!=NULL){
            ans++; head=head->next;
        }
        return ans;
    }
    ListNode* rotateRight(ListNode* head, int k) {
    
        int l=length(head);
        if(l==0) return NULL;
        k=k%l;
        l-=k;
        ListNode*temp=head;
        for(int i=1;i<l;i++) temp=temp->next;
        ListNode*last=head;
        while(last->next!=NULL) last=last->next;
        last->next=head;
    
        ListNode*ans=temp->next;
        temp->next=NULL;
        return ans;
    }
};
