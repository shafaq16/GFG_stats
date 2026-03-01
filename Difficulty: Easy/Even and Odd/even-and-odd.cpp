// User function Template for C++

class Solution {
  public:
    void reArrange(int arr[], int n) {
        // code here
        int o = 1, e = 0;
        while(e<n && o<n){
            if(arr[e]%2 != 0 && arr[o]%2  == 0){
                swap(arr[e],arr[o]);
                o += 2;
                e += 2;
            }
            else{
                if(arr[o]%2 != 0) o+=2;
                if(arr[e]%2 ==0) e += 2;
            }
        }
    }
};