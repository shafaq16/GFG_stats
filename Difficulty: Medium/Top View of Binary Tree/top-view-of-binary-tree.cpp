/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        vector<int> ans;
        q.push({root,0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int hd = p.second;
            if(mp.count(hd)==0)
                mp[hd] = node->data;
                
            if(node->left)
                q.push({node->left, hd-1});
            if(node->right)
                q.push({node->right, hd+1});
        }
        for(auto &i : mp)
            ans.push_back(i.second);
      return ans;
    }
};