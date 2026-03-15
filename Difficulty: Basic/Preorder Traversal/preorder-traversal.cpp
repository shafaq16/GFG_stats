/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void helper(Node* node, vector<int>& ans){
        if(node == nullptr) return;
        ans.push_back(node->data);
        helper(node->left, ans);
        helper(node->right,ans);
    }
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};