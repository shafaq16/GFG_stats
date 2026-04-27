class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        bool zero = false, one = false, two = false;
        int oneidx = 0 , twoidx = 0 , zeroidx = 0;
        int ans = INT_MAX;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='0'){
                zero = true;
                zeroidx = i;
            }
            else if(s[i]=='1'){
                one = true;
                oneidx = i;
            }
            else if(s[i]=='2'){
                two = true;
                twoidx = i;
            }
            
            if(zero && one && two){
                ans = min(ans , max ({zeroidx, oneidx, twoidx}) - min({zeroidx, oneidx, twoidx}));
            }
        }
        return ans == INT_MAX ? -1 : ans+1;
    }
};
