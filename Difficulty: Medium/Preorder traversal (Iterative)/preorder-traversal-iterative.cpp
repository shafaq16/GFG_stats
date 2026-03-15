/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        stack<Node*> st;
        st.push(root);
        vector<int> ans;
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            ans.push_back(node->data);
            
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return ans;
    }
};