class Solution {
  public:
    int findExtra(vector<int>& a, vector<int>& b) {
        // add code here.
        int n = a.size(), m = b.size();
        int i = 0;
        while(i<n && i<m){
            if(a[i]!=b[i]){
                return i;
            }
            i++;
        }
        return i;
    }
};