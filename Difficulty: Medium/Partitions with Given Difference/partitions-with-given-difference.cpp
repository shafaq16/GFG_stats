class Solution {
  public:
    int countSubsets(int i, int currSum, int target, vector<int> &arr, vector<vector<int>> &dp){
        int n = arr.size();
        if (i == n)
            return (currSum == target) ? 1 : 0;
    
        if (dp[i][currSum] != -1)
            return dp[i][currSum];
        int exclude = countSubsets(i + 1, currSum, target, arr, dp);
    
        int include = 0;
        if (currSum + arr[i] <= target)
            include = countSubsets(i + 1, currSum + arr[i], target, arr, dp);
    
        return dp[i][currSum] = include + exclude;
    }
    
    int countPartitions(vector<int> &arr, int diff){
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if ((sum + diff) % 2 != 0 || sum < diff)
            return 0;
    
        int target = (sum + diff) / 2;
        vector<vector<int>> dp(arr.size() + 1, vector<int>(target + 1, -1));
        return countSubsets(0, 0, target, arr, dp);
    }
};