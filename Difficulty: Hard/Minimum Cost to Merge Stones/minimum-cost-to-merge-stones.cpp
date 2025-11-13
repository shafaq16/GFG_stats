class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;

        // compute prefix sums
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + stones[i];
        }

        const int INF = INT_MAX / 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, INF)));

        // base case
        for (int i = 0; i < n; i++) {
            dp[i][i][1] = 0;
        }

        // length from 2 to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                for (int m = 2; m <= k; m++) {
                    for (int t = i; t < j; t += (k-1)) {
                        dp[i][j][m] = min(dp[i][j][m], dp[i][t][1] + dp[t+1][j][m-1]);
                    }
                }
                // then merge into 1 pile if possible
                if (dp[i][j][k] < INF) {
                    dp[i][j][1] = dp[i][j][k] + (prefix[j+1] - prefix[i]);
                }
            }
        }

        int ans = dp[0][n-1][1];
        return (ans >= INF ? -1 : ans);
    }
};
