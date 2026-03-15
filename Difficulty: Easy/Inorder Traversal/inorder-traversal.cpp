/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void helper(Node* node, vector<int>& ans){
        if(node == nullptr) return;
        helper(node->left, ans);
        ans.push_back(node->data);
        helper(node->right,ans);
    }
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};