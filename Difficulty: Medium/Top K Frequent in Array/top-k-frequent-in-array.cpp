class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        
        for(auto it:mp){
            pq.push({it.second,it.first}); //freq pehle
        }
        
        vector<int> ans;
        
        while(ans.size()<k){
            auto it = pq.top();pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};
