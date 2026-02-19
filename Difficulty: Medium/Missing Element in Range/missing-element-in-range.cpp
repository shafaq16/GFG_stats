class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        sort(arr.begin(), arr.end());
        vector<int> ans;

        int n = arr.size();
        int i = 0, j = n - 1;
        int idx = n;

        while (i <= j) {
            int m = i + (j - i) / 2;
            if (arr[m] >= low) {
                idx = m;
                j = m - 1;
            } else {
                i = m + 1;
            }
        }

       
        int curr = low;
        while (curr <= high) {
          
            while (idx < n && arr[idx] < curr) {
                idx++;
            }
           
            if (idx < n && arr[idx] == curr) {
                while (idx < n && arr[idx] == curr) {
                    idx++;
                }
            } else {
                ans.push_back(curr);
            }
            curr++;
        }

        return ans;
    }
};
