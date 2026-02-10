class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {

        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long total_hour = 0;

            for (int i = 0; i < arr.size(); i++) {
                total_hour += ceil((double)arr[i] / mid);  
                
                
                // ceil(5/2)=2 but it should be 3 so we have to use double for floating point represnt
            }

            if (total_hour <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
