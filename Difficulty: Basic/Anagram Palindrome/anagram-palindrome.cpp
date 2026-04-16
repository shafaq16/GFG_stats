class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        unordered_map<char,int> mp;
        for(char ch: s){
            mp[ch]++;
        }
        int cnt = 0;
        for(auto& pair: mp){
            if(pair.second%2 != 0){
                cnt++;
            }
        }
        return cnt>1? false: true;
    }
};