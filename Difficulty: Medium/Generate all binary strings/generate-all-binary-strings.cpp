class Solution {
  public:
  void gen(int n, string curr, vector<string>& ans){
      if(n==1){
          string zero = curr + '0';
          string one = curr + '1';
          ans.push_back(zero);
          ans.push_back(one);
          return;
      }
      gen(n-1, curr + '0', ans);
      gen(n-1, curr + '1', ans);
      return;
  }
    vector<string> binstr(int n) {
        // code here
        
        vector<string> ans;
        gen(n,{},ans);
        return ans;
    }
};