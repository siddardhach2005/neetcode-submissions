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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* curr=head;
        vector<int> a;
        int count=0;
        while(curr!=NULL){
            count+=1;
            curr=curr->next;
        }
        int m=(count+1)/2;
        curr=head;
        for(int i=1;i<m;i++){
            curr=curr->next;
        }
        ListNode* l1=head;
        ListNode* l2=curr->next;
        curr->next=NULL;
        ListNode* prev = NULL;
        while(l2 != NULL) {
            ListNode* next = l2->next;
            l2->next = prev;
            prev = l2;
            l2 = next;
        }
        l2=prev;
        while(l1!=NULL && l2!=NULL){
            ListNode* n1=l1->next;
            ListNode* n2=l2->next;
            l1->next=l2;
            l2->next=n1;
            l1=n1;
            l2=n2;
        }
    }
};
