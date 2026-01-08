class Solution {
  public:
    vector<int> remDuplicate(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        for(int x: arr){
            mp[x]++;
        }
        vector<int> ans;
        for(auto& i: mp){
            ans.push_back(i.first);
        }
        return ans;
    }
};