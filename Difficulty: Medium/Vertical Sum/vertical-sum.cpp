/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
// class Solution {
//   public:
//     vector<int> verticalSum(Node* root) {
//         // code here
//         map<int, map<int , multiset<int>>> mp;
//         queue<pair<Node*, pair<int,int>>> q;
//         q.push({root, {0,0}});
//         while(!q.empty()){
//             auto p = q.front();
//             q.pop();
//             Node* node = p.first;
//             int x = p.second.first, y = p.second.second ;
//             mp[x][y].insert(node->data);
//             if(node->left){
//                 q.push({node->left, {x-1, y+1}});
//             }
//             if(node->right){
//                 q.push({node->right, {x+1, y+1}});
//             }
//         }
        
//         vector<int> ans;
//         for(auto x : mp){
//         int sum = 0;
//             for(auto y : x.second){
//                 for(auto val : y.second){
//                     sum += val;
//                 }
//             }
//             ans.push_back(sum);
//         }
//         return ans;
//     }
// };

class Solution {
public:

    void preorder(Node* root, int x, map<int,int>& mp){
        if(root == NULL) return;
        mp[x] += root->data;
        preorder(root->left, x - 1, mp);
        preorder(root->right, x + 1, mp);
    }

    vector<int> verticalSum(Node *root) {
        map<int,int> mp;
        preorder(root, 0, mp);
        vector<int> ans;
        for(auto pair : mp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};