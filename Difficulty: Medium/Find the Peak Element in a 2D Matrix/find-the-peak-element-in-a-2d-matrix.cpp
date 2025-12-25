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
  
        int row = mat.size(), col = mat[0].size();
        
        for(int i = 0; i < row; i++){
            
            int l = 0 , r = col-1;
            while(l<=r){
                int m = l+(r-l)/2; //mid colm 
                
                int left  = (m-1 < 0)      ? INT_MIN : mat[i][m-1];
                int right = (m+1 >= col)   ? INT_MIN : mat[i][m+1];
                int up    = (i-1 < 0)      ? INT_MIN : mat[i-1][m];
                int down  = (i+1 >= row)   ? INT_MIN : mat[i+1][m];

                
                if(mat[i][m] >= left && mat[i][m] >= right && 
                  mat[i][m] >= up && mat[i][m] >= down){
                    return {i,m};
                }
                
                else if(mat[i][m] < left){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
        }
        return {-1,-1};
    }
};
