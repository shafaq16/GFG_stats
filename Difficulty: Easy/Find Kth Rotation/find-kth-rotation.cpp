class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int ans = 0;
        for(int i = 1; i<arr.size(); i++){
            if(arr[i]<arr[i-1]){
                ans = i;
            }
        }
        return ans;
    }
};
