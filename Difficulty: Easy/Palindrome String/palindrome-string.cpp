class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
        int n = s.size();
        int l = 0, r = n-1;
        while(l<=r){
            if(s[l]==s[r]){
                l++; r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};