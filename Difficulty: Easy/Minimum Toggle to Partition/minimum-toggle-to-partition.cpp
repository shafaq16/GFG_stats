class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int n = arr.size();
        int cnt1 = 0 , ans = 0;
        for(int i = 0; i<n ; i++){
            if(arr[i] == 1)  cnt1++;
            else{
                ans= min(ans+1, cnt1);
            }
        }
        
        return ans;
    }
};