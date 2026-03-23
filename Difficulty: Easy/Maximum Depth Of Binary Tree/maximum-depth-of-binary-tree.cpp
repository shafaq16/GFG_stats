/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    /*You are required to complete this method*/
    int maxDepth(Node *root) {
        // Your code here
        if(!root) return 0;
        queue<Node*> q;
        int h = 0;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i<len ; i++){
                Node* node = q.front();
                q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
                h++;
        }
        return h;
    }
};
