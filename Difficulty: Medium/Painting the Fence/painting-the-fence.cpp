class Solution {
  public:
    int countWays(int n, int k) {
        // code here
        if(n==1) return k;
        if (n == 2) return k * k;
        
        int same = k, diff = k*(k-1);
        
        for(int i = 3; i<=n ; i++){
            int prevsame = same;
            int prevdiff = diff;

            same = prevdiff;
            diff = (prevsame+prevdiff) * (k-1);
        }
        return same+diff;
    }
};