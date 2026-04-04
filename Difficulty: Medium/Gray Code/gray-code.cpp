class Solution {
  public:
  
    vector<string> graycode(int n) {
        // code here
        vector<string> ans;
        ans.push_back("0");
        
        if(n==0) return ans;
        ans.push_back("1");
        
        int power = 1;
        for(int i = 2; i<=n ; i++){
            int size = ans.size();
            for(int j = size - 1; j >= 0; j--){
                ans.push_back("1" + ans[j]);
            }
            for(int j = 0; j < size; j++){
                ans[j] = "0" + ans[j];
            }
        }
        return ans;
    }
};