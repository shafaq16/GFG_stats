class Solution {
  public:
    string genPalindrome(int n){
        string s = "";
        while(n > 0){
            int rem = n % 2;
            n /= 2;
            s += (rem + '0');
        }
        return s;
    }

    bool isBinaryPalindrome(int n) {
        string ans = genPalindrome(n);
        int len = ans.size();

        for(int i = 0; i < len; i++){
            if(ans[i] != ans[len - i - 1]) return false;
        }
        return true;
    }
};