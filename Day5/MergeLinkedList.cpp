//https://leetcode.com/problems/merge-two-sorted-lists/


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val>list2->val){
            ListNode* temp=new ListNode(list2->val);
            ans=temp; list2=list2->next;
        }else{
            ListNode* temp=new ListNode(list1->val);
            ans=temp; list1=list1->next;
        }
        ListNode* t=ans;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                ListNode* temp=new ListNode(list1->val);
                t->next=temp; list1=list1->next; t=t->next;
            }else{
                ListNode* temp=new ListNode(list2->val);
                t->next=temp; list2=list2->next; t=t->next;

            }
        } 
        while(list1!=NULL){
                ListNode* temp=new ListNode(list1->val);
                t->next=temp; list1=list1->next; t=t->next;

        }
        while(list2!=NULL){
                ListNode* temp=new ListNode(list2->val);
                t->next=temp; list2=list2->next; t=t->next;

        }
        return ans;
    }
};
