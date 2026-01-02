/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *compute(Node *head) {
    
    if (!head || !head->next) return head;

        // reverse
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev; // head of reversed list

        // filter: keep nodes >= maxSeen
        Node* maxNode = head;
        curr = head->next;
        while (curr) {
            if (curr->data < maxNode->data) {
                // remove curr
                maxNode->next = curr->next;
                delete curr;
                curr = maxNode->next;
            } else {
                maxNode = curr;
                curr = curr->next;
            }
        }

        // reverse back
        prev = nullptr;
        curr = head;
        while (curr) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev; // new head
    }
};