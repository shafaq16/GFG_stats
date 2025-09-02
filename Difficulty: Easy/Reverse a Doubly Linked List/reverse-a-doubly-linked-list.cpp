/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(head == NULL || head->next == NULL) return head;
        Node* back = NULL; //back
        Node* curr = head;
        while(curr != NULL){
            back = curr->prev;
            curr->prev = curr->next;
            curr->next = back;
            curr = curr->prev;
        }
        return back->prev;
    }
};