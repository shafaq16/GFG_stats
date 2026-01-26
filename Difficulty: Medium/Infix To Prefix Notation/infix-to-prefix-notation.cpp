class Solution {
  public:
  int prior(char c){
      if(c == '^') return 3;
      else if(c == '/' || c == '*') return 2;
      else if(c == '+' || c == '-') return 1;
      else return -1;
  }
    void reverseS(string &s) { 
        reverse(s.begin(),s.end());
        // Flip parentheses after the full reverse to avoid double-flipping
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') s[i] = ')';
            else if (s[i] == ')') s[i] = '(';
        }
    }
    string infixToPrefix(string &s) {
        // code here
        reverseS(s);
        int i = 0; 
        stack<char> st;
        string ans = "";
        while(i<s.size()){
            char c = s[i];
            
            if(isalnum(c)) ans += c;
            else if(c == '(')  st.push(c);
            else if(c == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
               if(!st.empty()) st.pop();
            }
            else{
                if(c == '^'){
                    while(!st.empty() && prior(c) <= prior(st.top())){
                        ans += st.top();
                        st.pop();
                    } 
                }
                else{
                     while(!st.empty() && prior(c) < prior(st.top())){
                        ans += st.top();
                        st.pop();
                    } 
                }
            
                st.push(c);
            }
            i++;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverseS(ans);
        return ans;
    }
};
