class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n = arr.size();
        // for(int i = 0; i<n-1; i++){
        //     for(int j = 0; j < n-i-1; j++){
        //         if(arr[j]==0){
        //             swap(arr[j],arr[j+1]);
        //         }
        //     }
        // }
        
        int j = 0;
        for(int i = 0; i<n; i++){
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }
};