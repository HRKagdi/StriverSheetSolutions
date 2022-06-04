//https://leetcode.com/problems/palindrome-linked-list/


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
        int l=0;
         while(head!=NULL){
             head=head->next; l++;
         }
        return l;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*t=head;
        int l=length(head); int temp=l; l/=2;
        stack<int>s;
        int cnt=0;
        while(cnt!=l){
            s.push(t->val); t=t->next; cnt++;
        } 
        if(temp%2==1) t=t->next;
        while(t!=NULL){
            int x=s.top();   s.pop();
            if(t->val!=x) return false;
            t=t->next;
        }
        return true;
    }
};
