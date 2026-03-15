/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
       return traverse(root);
    }
private:
    int traverse(Node* node) {
        if (node == nullptr) return 0;
        if ((node->left == nullptr && node->right == nullptr)) return 1;
      
        return traverse(node->left) + traverse(node->right);
    }
};