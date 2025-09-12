// User function Template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
       sort(arr.begin(), arr.end());
       int mini = arr[0] + k , maxi = arr[n-1]-k;
       int ans = arr[n-1] - arr[0];
       
       for(int i = 0; i<n-1; i++){
            int minimum = min(mini, arr[i+1] - k);
            int maximum = max(maxi, arr[i] +k);
            ans = min(ans,maximum-minimum);
       }
        return ans;
    }
};