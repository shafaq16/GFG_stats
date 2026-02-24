class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        int n = a1.size();
        int ans = 0;
        vector<int> diff(2*n+1, -1);
        int pSum1 = 0, pSum2= 0;
         
        for(int i = 0 ; i<n ; i++){
            pSum1 += a1[i];
            pSum2 += a2[i];
            
            int currDiff = pSum1-pSum2;
            int idx = currDiff+n;
            
            if(currDiff == 0){
                ans = max(ans, i+1);
            }
            else if(diff[idx] != -1){
                ans = max(ans , i - diff[idx]);
            }
            else{
                diff[idx] = i;
            }
            
        }
        return ans;
    }
};



///----- Run time Error : test case 1110

// class Solution {
//   public:
//     int equalSumSpan(vector<int> &a1, vector<int> &a2) {
//         // code here
//         int n = a1.size();
//         int ans = 0;
//         for(int i = 0 ; i<n ; i++){
//             int pSum1 = 0, pSum2= 0;
//             for(int j = i; j<n; j++){
//                 pSum1 += a1[j];
//                 pSum2 += a2[j];
                
//                 if(pSum1 == pSum2){
//                     ans = max(ans, j-i+1);
//                 }
//             }
//         }
//         return ans;
//     }
// };