class Solution {
  public:
    string findLargest(vector<int> &arr) {
        
        vector<string> st;
        for(int x: arr){
            st.push_back(to_string(x));
        }
        
        sort(st.begin(), st.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        
        if (!st.empty() && st[0] == "0") return "0";
            
        string s;
        for (auto& x : st) s += x;
        return s;
    }
};