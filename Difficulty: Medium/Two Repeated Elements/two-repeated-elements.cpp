class Solution {
  public:
    vector<int> twoRepeated(vector<int>& arr) {
        // code here
       vector<int> ans;
        unordered_map<int,int> mp;
        for(int x: arr){
            if(mp[x]==1){
                ans.push_back(x);
            }
            mp[x]++;
        }
        return ans;
    }
};
