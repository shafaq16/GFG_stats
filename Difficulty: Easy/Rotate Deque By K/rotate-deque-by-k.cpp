#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0) return;
        k = k % n;  // Optimize for large k
        if (k == 0) return;

        if (type == 1) {
            // Right rotation -> rotate left by (n - k)
            rotate(dq.begin(), dq.end() - k, dq.end());
        } else {
            // Left rotation -> rotate left by k
            rotate(dq.begin(), dq.begin() + k, dq.end());
        }
    }
};
