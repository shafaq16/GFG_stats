class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        int ans = 0 , cnt = 0;
       unordered_map<int,int> mp;
        
        for(int i = 0; i<n; i++){
            if(arr[i]>k) cnt ++;
            else cnt--;

            if(cnt>0){
                ans = max(ans, i+1);
            }
            if(mp.find(cnt-1) != mp.end()){
                ans = max(ans, i-mp[cnt-1]);
            }
            if(mp.find(cnt) == mp.end()){
                mp[cnt] = i;
            }
        }
        return ans;
    }
};