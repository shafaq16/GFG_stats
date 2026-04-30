class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i = 0; i<=(n-2)/2; i++){
            int left = 2*i+1;
            int right = 2*i+2;
            if((arr[i] < arr[left]) || (right<n && arr[i]<arr[right]))
                return false;
        }
        return true;
    }
};
