class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i: a) 
            mp[i]++;
        for(int j: b)
            mp[j]++;
        
    
        for(auto &pair: mp){
             ans.push_back(pair.first);
        }
        return ans;
    }
};