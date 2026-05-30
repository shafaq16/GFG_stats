class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n<3) return -1;
        int first = 0, sec = 0, third = 0;
        for(int i = 0; i<n ; i++){
            if(arr[i] >= first){
                third = sec;
                sec = first;
                first = arr[i];
            }
            else if(arr[i] < first && arr[i] >= sec){
                third = sec;
                sec = arr[i];
            }
            else if(arr[i] < first && arr[i]<sec && arr[i]>=third){
                third = arr[i];
            }
        }
        return third;
    }
};