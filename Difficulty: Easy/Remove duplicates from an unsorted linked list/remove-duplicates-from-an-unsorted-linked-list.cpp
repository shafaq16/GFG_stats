/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
        if (!head || !head->next) return head;
        unordered_map<int, int> mp;
        Node* curr = head;
        Node* prev = nullptr;

        while (curr) {
            mp[curr->data]++;

            if (mp[curr->data] > 1) {
                // duplicate found
                Node* del = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete del;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};