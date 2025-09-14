class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        // code here
         int n = pat.size(), m = tar.size();
        int i = n - 1, j = m - 1;
        
        while (i >= 0 && j >= 0) {
            if (pat[i] == tar[j]) {
                i--;
                j--;
            } else {
                i -= 2;
            }
        }
        return j==-1;
    }
};