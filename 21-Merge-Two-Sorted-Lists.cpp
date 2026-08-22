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
        if(list1==NULL && list2==NULL) return list1;
        else if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* head=NULL;
        if(temp1->val>=temp2->val){
            head=temp2;
            temp2=temp2->next;
        }
        else{
            head=temp1;
            temp1=temp1->next;
        }

        ListNode* tail=head;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val>=temp2->val){
                tail->next=temp2;
                tail=tail->next;
                temp2=temp2->next;
            }
            else{
                tail->next=temp1;
                tail=tail->next;
                temp1=temp1->next;
            }
        }
        if(temp1==NULL){
            tail->next=temp2;
        }
        else{
            tail->next=temp1;
        }
        return head;
    }
};