class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n = arr.size();
        if(n<2) return 0;
        int left = 0; int cnt = 0;
        for(int right = 1; right<n; right++){
            if(arr[right]<=arr[right-1]){
                left = right;
            }
            if(right>left){
                cnt += (right-left);
            }
        }
        return cnt;
    }
};
