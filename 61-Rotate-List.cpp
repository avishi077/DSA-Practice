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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp=head;
        int len=0;
        ListNode* tail=head->next;
        ListNode* prev=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        for(int i=0;i<k%len;i++){
            while(tail->next!=NULL){
                tail=tail->next;
                prev=prev->next;
            }
            tail->next=head;
            prev->next=NULL;
            head=tail;
            tail=head->next;
            prev=head;
        }
        return head;
    }
};