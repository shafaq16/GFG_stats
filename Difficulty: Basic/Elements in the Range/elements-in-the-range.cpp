class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        bool check = false;
        int j = start;
        for(int i = 0; i < arr.size() && j <= end; i++) {
            if(arr[i] == j) {
                j++;
            }
        }
        return (j > end);
    }
};
