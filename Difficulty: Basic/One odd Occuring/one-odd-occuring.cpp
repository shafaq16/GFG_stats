class Solution {
  public:
    int getOddOccurrence(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        for(int i: arr) mp[i]++;
        for(auto& pair: mp){
            if(pair.second % 2 != 0) return pair.first;
        }
        return 0;
    }
};