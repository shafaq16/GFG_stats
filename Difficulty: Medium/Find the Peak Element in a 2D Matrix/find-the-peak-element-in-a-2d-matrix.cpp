// class Solution {
//   public:
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
//         // code here
//         int n = mat.size(), m = mat[0].size();
        
//         for(int i = 0; i<n; i++){
//             for(int j = 0; j<m; j++){
//                 //agar neighbour greater then skip
//                 if(i > 0 && (mat[i-1][j] > mat[i][j])) continue;
//                 if(i < n-1 && (mat[i+1][j] > mat[i][j])) continue;
//                 if(j > 0 && (mat[i][j-1] > mat[i][j])) continue;
//                 if(j < m-1 && (mat[i][j+1] > mat[i][j])) continue;

//                 return {i, j};
//             }
//         }
//         return {-1,-1};
//     }
// };


class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
  
        int top = 0, bottom = mat.size() - 1;

        while (top < bottom) {
            int mid = (top + bottom) / 2;
            // find index of max element in row mid
            int maxCol = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();

            // compare with next row at that column
            if (mat[mid][maxCol] > mat[mid+1][maxCol]) {
                bottom = mid;
            } else {
                top = mid + 1;
            }
        }

        // now top == bottom, find peak column
        int peakCol = max_element(mat[top].begin(), mat[top].end()) - mat[top].begin();
        return {top, peakCol};
    }
};
