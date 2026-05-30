

class Solution {
  public:
    int findMissing(vector<int>& arr1, vector<int>& arr2) {
        // your code
        int sum1 = 0, sum2 = 0;
        for(int x: arr1) sum1 += x;
        for(int x: arr2) sum2 += x;
        return sum1-sum2;
    }
};