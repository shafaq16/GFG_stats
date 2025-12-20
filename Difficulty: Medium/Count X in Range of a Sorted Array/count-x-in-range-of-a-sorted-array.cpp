class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& q) {
        // code here
        int m = q.size();
         vector<int> ans(m,0);
         for(int i = 0; i<m ; i++){
            
             int sum = 0;
             int l = q[i][0], r = q[i][1], x = q[i][2];
             
             int first=lower_bound(arr.begin(),arr.end(),x) - arr.begin();
             int last=upper_bound(arr.begin(),arr.end(),x) - arr.begin()-1;
             
             if(first > r || last < l){
                ans[i] = (0);
             } 
             else{
                int left=max(first, l);
                int right=min(last, r);
                ans[i] = (right - left + 1);
             }
         }
         return ans;
    }
};