/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* curr = head;
        Node* head1 = new Node(curr->val);
        Node* tail = head1;
        curr = curr->next;
        while (curr != NULL) {
            Node* n = new Node(curr->val);
            tail->next = n;
            tail = n;
            curr = curr->next;
        }
        curr = head;
        Node* r = head1;
        while (curr != NULL) {
            if (curr->random == NULL) {
                r->random = NULL;
            }
            else {
                Node* p = head1;
                Node* temp = head;
                while (temp != NULL) {
                    if (temp == curr->random) {
                        r->random = p;
                        break;
                    }
                    temp = temp->next;
                    p = p->next;
                }
            }
            curr = curr->next;
            r = r->next;
        }
        return head1;
    }
};
