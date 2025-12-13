//-----------------TLE-----------------
// class Solution {
//   public:
//     vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &q) {
//         // code here
        
//         vector<int> ans;
//         for(int i = 0; i<q.size() ; i++){
//             int sum = 0;
//             int n = q[i][2];
//             int m = q[i][3];
//             for(int j = q[i][0]; j<=n ; j++){
//                 for(int k = q[i][1]; k<=m; k++){
//                     sum += mat[j][k];
//                 }
//             }
//             ans.push_back(sum);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &q) {
        int n = mat.size(), m = mat[0].size();
        
        // Build 2D prefix sum array
        vector<vector<long long>> pref(n+1, vector<long long>(m+1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                pref[i][j] = pref[i-1][j] + pref[i][j-1]
                             - pref[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        vector<int> ans;

        for(auto &qr : q){
            int r1 = qr[0], c1 = qr[1];
            int r2 = qr[2], c2 = qr[3];
            
            long long sum = pref[r2+1][c2+1]
                          - pref[r1][c2+1]
                          - pref[r2+1][c1]
                          + pref[r1][c1];
            
            ans.push_back(sum);
        }
        return ans;
    }
};

