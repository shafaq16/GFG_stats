class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        string ans = "";
        unordered_map<char,int> mp;
        queue<char> q;
    
        for(int i = 0; i<s.size();i++){
           
             mp[s[i]]++;

            // push ONLY when first time
            if(mp[s[i]] == 1) {
                q.push(s[i]);
            }
            while(!q.empty() && mp[q.front()]>1){
                q.pop();
            }
            
            if (!q.empty()) {
                ans += q.front();
            }
            else {
                ans += '#';
            }
        }
        return ans;
    }
};