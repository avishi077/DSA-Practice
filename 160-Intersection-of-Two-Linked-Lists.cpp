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
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int cnt1=0;
        int cnt2=0;
        int len=0;
        while(temp1!=NULL){
            cnt1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            cnt2++;
            temp2=temp2->next;
        }
        temp1=headA;
        temp2=headB;
        if(cnt1<cnt2){
            while(temp2!=NULL && cnt2!=cnt1){
                temp2=temp2->next;
                cnt2--;
            }
        }
        else if(cnt2<cnt1){
            while(temp1!=NULL && cnt2!=cnt1){
                temp1=temp1->next;
                cnt1--;
            }
        }
        while(temp1 != NULL && temp2 != NULL && temp1 != temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
    }
};