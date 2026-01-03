/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        Node* main = head;
        Node* ref = head;
        
        for(int i = 1 ; i<k ; i++){
            ref = ref->next;
            if(ref == NULL) return -1;
        }
        
        while(ref->next != NULL){
            ref = ref->next;
            main = main->next;
        }
        return main->data;
    }
};