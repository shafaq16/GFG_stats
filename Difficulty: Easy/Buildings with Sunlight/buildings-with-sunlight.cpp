class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int n = arr.size(), cnt = n;
        int maxi = arr[0];
        for(int i = 1; i< n ; i++){
            if(arr[i]<maxi) cnt--;
            maxi = max(maxi, arr[i]);
        }
        return cnt;
    }
};