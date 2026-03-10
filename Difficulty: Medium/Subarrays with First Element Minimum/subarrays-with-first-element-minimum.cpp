class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        stack<int> st;
        int ans = 0;
        int n = arr.size();
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            int last = (st.empty() ? n : st.top());
            ans += (last - i);
            st.push(i);
        }
        return ans;
    }
};