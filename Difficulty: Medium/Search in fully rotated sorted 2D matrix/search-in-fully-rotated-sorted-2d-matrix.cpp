class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size() , m = mat[0].size();
        for(int i= 0; i<n; i++){
            if (mat[i][0] == x || mat[i][m-1] == x) return true;

                int l = 0, r = m-1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    if (mat[i][mid] == x) return true;
    
                    // Left part sorted
                    if (mat[i][l] <= mat[i][mid]) {
                        if (mat[i][l] <= x && x < mat[i][mid]) {
                            r = mid - 1;
                        } else {
                            l = mid + 1;
                        }
                    }
                    // Right part sorted
                    else {
                        if (mat[i][mid] < x && x <= mat[i][r]) {
                            l = mid + 1;
                        } else {
                            r = mid - 1;
                        }
                    }
                }
            }
        return false;
    }
};