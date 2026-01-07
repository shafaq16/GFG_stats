class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
        // code here
        int ans = -1;
        unordered_map<int,int> mp;
        for(int i = arr.size()-1; i>=0; i--){
            mp[arr[i]]++;
            if(mp[arr[i]]>1) ans = i+1;
        }
        return ans;
    }
};