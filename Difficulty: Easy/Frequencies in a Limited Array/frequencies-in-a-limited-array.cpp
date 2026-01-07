class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        for(int i: arr){
            mp[i]++;
        }
        vector<int> ans;
        for(int i = 1; i<=arr.size(); i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};
