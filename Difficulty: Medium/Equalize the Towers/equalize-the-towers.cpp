class Solution {
  public:
    long long getCost(int H, vector<int>& heights, vector<int>& cost) {
        long long total = 0;
        for (int i = 0; i < heights.size(); i++) {
            total += 1LL * abs(heights[i] - H) * cost[i];
        }
        return total;
    }

    int minCost(vector<int>& heights, vector<int>& cost) {
        int low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            long long c1 = getCost(mid, heights, cost);
            long long c2 = getCost(mid + 1, heights, cost);

            if (c1 <= c2) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return (int)getCost(low, heights, cost);
    }
};
