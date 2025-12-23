class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &q) {
        // code here
        int m = q.size();
         vector<int> ans(m,0);
         
         sort(arr.begin(),arr.end());
         
         for(int i = 0; i<m ; i++){
            
             int sum = 0;
             int l = q[i][0], r = q[i][1];
             
             int first=lower_bound(arr.begin(),arr.end(),l) - arr.begin();
             int last=upper_bound(arr.begin(),arr.end(),r) - arr.begin()-1;
             
           
            ans[i] = (last-first+1);
             
         }
         return ans;
    }
};