class Solution {
public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();

        vector<vector<int>> diag(2*n - 1);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                diag[i + j].push_back(mat[i][j]);
            }
        }
        for(int i = 0; i < 2*n - 1; i++){
            for(int val : diag[i]){
                ans.push_back(val);
            }
        }

        return ans;
    }
};