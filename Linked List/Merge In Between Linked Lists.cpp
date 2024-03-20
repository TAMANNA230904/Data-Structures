You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:


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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1=list1;
        int cnt=0;
        while(cnt<a-1){
            cnt++;
            temp1=temp1->next;
            
        }

        ListNode* temp2=list1;
        cnt=0;
        while(cnt!=b+1){
            cnt++;
            temp2=temp2->next;
        }
        ListNode* temp3=list2;
        while(temp3->next!=NULL){
            temp3=temp3->next;
        }
        temp1->next=list2;
        temp3->next=temp2;
        return list1;
    }
};
