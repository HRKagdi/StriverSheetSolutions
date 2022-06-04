
//160. Intersection of Two Linked Lists

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;
        ListNode*t1=headA; ListNode*t2=headB;
        while(t1!=NULL){
            s.insert(t1);
            t1=t1->next;
        }
        while(t2!=NULL){
            if(s.find(t2)!=s.end()) return t2;
            t2=t2->next;
        }
        return NULL;
    }
};
