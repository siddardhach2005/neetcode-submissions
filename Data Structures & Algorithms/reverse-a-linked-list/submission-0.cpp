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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return 0;
        ListNode* temp=head;
        ListNode* front=head->next;
        ListNode* back=NULL;
        while(front!=NULL){
            temp->next=back;
            back=temp;
            temp=front;
            front=front->next;
        }
        temp->next=back;
        return temp;
    }
};
