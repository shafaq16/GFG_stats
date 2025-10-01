class Solution {
public:
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        dfs(n, k, 1, comb, ans);
        return ans;
    }
    
    void dfs(int target, int k, int start,
             vector<int>& comb, vector<vector<int>>& ans) {
        if (k == 0) {
            if (target == 0) {
                ans.push_back(comb);
            }
            return;
        }
        // Prune: minimal sum of k numbers starting from start is start + (start+1) + … etc
        for (int x = start; x <= 9; x++) {
            if (x > target) break;  // no point going further
            comb.push_back(x);
            dfs(target - x, k - 1, x + 1, comb, ans);
            comb.pop_back();
        }
    }
};
