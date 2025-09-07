/*
class Node {
  public:
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
    static bool cmp(Node *first, Node *second)
    {
        return first->data > second->data;
    }
    
    Node* mergeKLists(vector<Node*>& arr) 
    {
        priority_queue<Node *, vector<Node*>, decltype(&cmp)> pq(cmp);
        Node *dummy = new Node(0);
        Node *tail = dummy;
        for(Node *temp: arr)
        {
            if(temp)
                pq.push(temp);    
        }
        while(pq.size())
        {
            Node *smallest = pq.top();
            pq.pop();
            tail->next = smallest;
            tail = tail->next;
            if(smallest->next != NULL)
                pq.push(smallest->next);
        }
        return dummy->next;
    }
};