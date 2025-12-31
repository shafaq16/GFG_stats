class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long n = arr.size();
        long long ogSum = (n+1)*(n+2)/2;
        
        long long sum = 0;
        for(int i: arr){
            sum += i;
        }
        return (int)(ogSum - sum);
    }
};