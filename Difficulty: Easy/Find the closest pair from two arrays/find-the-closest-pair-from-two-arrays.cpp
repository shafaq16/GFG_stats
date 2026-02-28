class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
         int n = arr1.size(), m = arr2.size();
        int mini = INT_MAX;
        vector<int> ans(2);

      
        for(int i = 0; i < n; i++) {
            int l = 0, r = m-1;
            while(l<=r) {
                int m = l+(r-l)/2;
                int sum = arr1[i] + arr2[m];
                if(sum>x){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
                int diff = abs(x - sum);
                if(diff < mini) {
                    mini = diff;
                    ans[0] = arr1[i];
                    ans[1] = arr2[m];
                }
            }
        }
        return ans;
    }
};


/// ----------RUNTIME ERRROR ----------------
// class Solution {
// public:
//     vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
//         int n = arr1.size(), m = arr2.size();
//         int mini = INT_MAX;
//         vector<int> ans(2);

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 int sum = arr1[i] + arr2[j];
//                 int diff = abs(x - sum);
//                 if(diff < mini) {
//                     mini = diff;
//                     ans[0] = arr1[i];
//                     ans[1] = arr2[j];
//                 }
//             }
//         }
//         return ans;
//     }
// };