You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

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
ListNode* findmiddle(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* reverse(ListNode* head){
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(curr!=NULL){
        ListNode* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    return prev;
}
void reorderList(ListNode* head) {
        ListNode*temp1=findmiddle(head);
        ListNode* temp2=temp1->next;
        temp1->next=NULL;
        temp2=reverse(temp2);
        ListNode* curr=head;
        while(curr!=NULL && temp2!=NULL){
            ListNode* curr_next=curr->next;
            ListNode* temp2_next=temp2->next;
            curr->next=temp2;
            temp2->next=curr_next;
            curr=curr_next;
            temp2=temp2_next;

        }
      
    }
};
