class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minH;
        int n = arr.size();
        int idx = 0;
        for(int i = 0; i < (k+1); i++) {
            minH.push(arr[i]);
        }
        for(int i = k+1; i < n; i++) {
            arr[idx++] = minH.top();
            minH.pop();
            minH.push(arr[i]);
        }

        while(!minH.empty()) {
            arr[idx++] = minH.top();
            minH.pop();
        }
    }
};