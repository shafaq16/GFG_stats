class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n = mat.size(), m = mat[0].size();
        priority_queue<int, vector<int>,greater<int>> pq;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                pq.push(mat[i][j]);
            }
        }
        for(int i = 1; i<k; i++){
            pq.pop();
        }
        return pq.top();
    }
};
