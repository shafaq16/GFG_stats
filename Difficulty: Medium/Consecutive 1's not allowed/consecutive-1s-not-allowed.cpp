class Solution {
  public:
    int countStrings(int n) {
        // code here
        int a = 1, b = 1;
        for(int i = 0; i<n ; i++){
            int sum = a+b;
            a = b;
            b = sum;
        }
        return b;
    }
};