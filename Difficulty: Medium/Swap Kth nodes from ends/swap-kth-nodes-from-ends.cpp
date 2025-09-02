/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        if (head == NULL) return NULL;
        Node* temp = head;
        int n = 0;
        while(temp){
            temp = temp->next;
            n++;
        }

        
        temp = head;
       
        Node* start = NULL;
        Node* end = NULL;
        int i = 0;
        while(temp){
            if(i==k-1) start = temp;
            if(i== n-k) end = temp;
            i++;
            temp = temp->next;
        }

        if(start && end){
            swap(start -> data, end -> data);
        }
        return head;
    }
};