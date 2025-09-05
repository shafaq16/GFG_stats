/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

// Method 1: SC: O(n) TC:O(2N)
// class Solution {
//   public:
//     Node* segregate(Node* head) {
//         vector<int> st;
//         Node* temp = head;
//         while(temp != NULL){
//             st.push_back(temp->data);
//             temp = temp->next;
//         }
//         sort(st.begin(),st.end());
//         temp = head;
//         int i = 0 ;
//         while(temp!=NULL){
//             temp->data = st[i++];
//             temp = temp -> next;
//         }
//         return head;
//     }
// };





//Method 2:TC: O(2n) Sc:O(1)
// class Solution {
//   public:
//     Node* segregate(Node* head) {
//         Node*temp = head;
//         int cnt0 = 0, cnt1 = 0, cnt2 = 0;
//         while(temp!=NULL){
//             if(temp->data == 0) cnt0++;
//             else if(temp->data == 1) cnt1++;
//             else cnt2++;
//             temp = temp->next;
//         }
//         temp = head;
//         while(temp!=NULL){
//             if(cnt0){
//                 temp->data = 0;
//                 cnt0--;
//             } 
//             else if(cnt1){
//                 temp->data = 1;
//                 cnt1--;
//             }
//             else{
//                 temp->data = 2;
//                 cnt2--;
//             }
//             temp = temp->next;
//         }
//         return head;
//     }
// };




//Method 3.  TC:O(n) SC:O(1)
class Solution {
  public:
    Node* segregate(Node* head) {
        if(head == NULL || head->next == NULL) return head;
        
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        Node* ones = oneHead;
        Node* twos = twoHead;
        Node* zeros = zeroHead;
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == 0){
                zeros->next = temp;
                zeros = zeros->next;
            } 
            else if(temp->data == 1){
                ones->next = temp;
                ones = ones->next;
            }
            else{
                twos->next = temp;
                twos = twos->next;
            }
            temp = temp->next;
        }
        zeros->next = (oneHead->next)? oneHead->next : twoHead->next;
        ones->next = twoHead->next;
        twos->next = NULL;
        
        Node* newHead = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return newHead;
    }
};