class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string> ans;
    for (int i = 1; i <= n; ++i) {
        string bin = "";
        int num = i;
        while (num > 0) {
            bin = char((num % 2) + '0') + bin; // prepend 0 or 1
            num /= 2;
        }
        ans.push_back(bin);
    }
    return ans;
    }
};