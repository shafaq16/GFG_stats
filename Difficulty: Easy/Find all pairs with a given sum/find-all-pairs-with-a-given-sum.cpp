class Solution {
  public:
    // Function to find all pairs with given sum.
    vector<pair<int, int>> allPairs(int target, vector<int> &a, vector<int> &b) {
        // Code here
        vector<pair<int,int>> ans;
        unordered_map<int,int> freq;
        for(int x : a) {
            freq[x]++; 
        }
        for(int y : b) {
            int x = target - y;
            if(freq.find(x) != freq.end()) {
                int countX = freq[x];
                while(countX--) {
                    ans.push_back({x, y});
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};