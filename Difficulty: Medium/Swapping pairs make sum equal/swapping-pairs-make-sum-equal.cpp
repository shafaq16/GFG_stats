class Solution {

  public:
  
    bool findSwapValues(vector<int>& a, vector<int>& b) {
        // Your code goes here
        long long sum1 = accumulate(a.begin(), a.end(), 0LL);
        long long sum2 = accumulate(b.begin(), b.end(), 0LL);

        long long diff = sum2 - sum1;

        // If the difference isn't even, no possible integer swap
        if (diff % 2 != 0) return false;

        long long target = diff / 2;

        unordered_set<long long> st;
        for (long long x : a) {
            st.insert(x);
        }

        for (long long y : b) {
            long long xNeeded = y - target;
            if (st.find(xNeeded) != st.end()) {
                return true;
            }
        }
        return false;
    }
};