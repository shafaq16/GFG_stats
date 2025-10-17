class Solution {
  public:
    int sum = 0; 
    void transformTree(Node* root) {
        if (!root) return;
        transformTree(root->right);
        int temp = root->data;
        root->data = sum;
        sum += temp;
        transformTree(root->left);
    }
};
