class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        int prof = 0;
        int hold = -arr[0];
        for(int i = 1; i<n ; i++){
            int prevProf = prof;
            prof = max(prof , hold+arr[i]-k);
            hold = max(hold , prevProf - arr[i]);
        }
        return prof;
    }
};