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
    ListNode* reverse(ListNode* start, ListNode* end) {
    ListNode* prevNode = NULL;
    ListNode* curr = start;
    ListNode* nextNode = end->next;

    while (curr != end) {
        ListNode* temp = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = temp;
    }

    curr->next = prevNode;

    return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* kthnode=head;
        ListNode* nextnode=kthnode->next;
        int cnt=0;
        while(temp!=NULL){
            cnt=0;
            kthnode=temp;
            for(int i=1; i<k; i++){
                if(kthnode == NULL) {
                    if(prev) prev->next=temp;
                    break;
                }
                kthnode = kthnode->next;
            }
            if(kthnode == NULL)
                break;
            nextnode=kthnode->next;
            kthnode->next=NULL;
            reverse(temp, kthnode);
            temp->next = nextnode;
            if(temp==head){
                head=kthnode;
            }
            else{
                prev->next=kthnode;
            }
            prev=temp;
            temp=nextnode;
        }
        return head;
    }
};