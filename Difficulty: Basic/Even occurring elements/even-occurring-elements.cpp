class Solution {
  public:
    vector<int> findEvenOccurrences(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        for(int num: arr) mp[num]++;
        
        vector<int> ans;
        for(int num : arr){
            if(mp[num] % 2 == 0){
                ans.push_back(num);
                mp[num] = -1; // mark as already added
            }
        } 
        return ans.empty() ? vector<int>{-1} : ans;
    }
};
