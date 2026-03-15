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
  void dfs(Node* root, int hd, int lvl, map<int, vector<pair<int,int>>>& verticalLines) {
        if (root == nullptr) return;
    
        verticalLines[hd].push_back({root->data, lvl});
        dfs(root->left, hd - 1, lvl + 1, verticalLines);
        dfs(root->right, hd + 1, lvl + 1, verticalLines);
    }
    
    

    vector<vector<int>> verticalOrder(Node *root) {
        // code here
    map<int, vector<pair<int,int>>> verticalLines;

    dfs(root, 0, 0, verticalLines);
    vector<vector<int>> res;

    for (auto& kv : verticalLines) {
        vector<pair<int,int>> lines = kv.second;
        stable_sort(lines.begin(), lines.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<int> line;
        for (auto &node : lines) {
            line.push_back(node.first);
        }
        res.push_back(line);
    }

    return res;
    }
};