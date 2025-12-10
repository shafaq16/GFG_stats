class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();

        long long S = n * (n + 1) / 2;                     
        long long P = n * (n + 1) * (2*n + 1) / 6;         

        long long S1 = 0, P1 = 0;
        for (long long x : arr) {
            S1 += x;
            P1 += x * x;
        }

        long long A = S1 - S;
        long long B = P1 - P;          

        long long sum_xy = B / A;      // x + y

        long long x = (A + sum_xy) / 2;    // repeating number
        long long y = x - A;               // missing number

        return {(int)x, (int)y};
    }
};
