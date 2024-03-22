Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.

class Solution {
public:
ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL)
    return head;

    ListNode* curr=head;
    ListNode* prev=NULL;
    while(curr!=NULL){
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

    ListNode* rev=reverse(slow);
    while(rev!=NULL){
        if(head->val!=rev->val)
        return false;

        head=head->next;
        rev=rev->next;
    }  
    return true;
    }
};

