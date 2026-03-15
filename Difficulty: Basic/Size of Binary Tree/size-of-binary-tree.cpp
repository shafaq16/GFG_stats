/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int getSize(Node* node) {
        // code here
        int ans = 0;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            ans ++;
            Node* currNode = q.front();
            q.pop();
          
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
            
        }
        return ans;
    }
};