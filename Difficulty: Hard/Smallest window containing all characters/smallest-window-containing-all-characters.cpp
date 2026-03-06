class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        int n = p.size(), m = s.size();
        if(m<n) return "";
        
        unordered_map<char,int> freqP;
        unordered_map<char,int> freqS;
        
        for(int ch: p){
            freqP[ch]++;
        }
        
        int cnt = 0, min_len = INT_MAX, start = 0 , start_idx = -1;
        
        for(int i = 0; i<m ; i++){
            freqS[s[i]]++;
            
            if(freqP[s[i]] != 0 && freqS[s[i]] <= freqP[s[i]]){
                cnt++;
            }
            
            if(cnt == n){ 
                while(freqS[s[start]] > freqP[s[start]] || freqP[s[start]] == 0){
                    if(freqS[s[start]] > freqP[s[start]]){
                        freqS[s[start]]--;
                    }
                    start++;
                }

                int len = i - start + 1;

                if(len < min_len){
                    min_len = len;
                    start_idx = start;
                }
            }
        }

        if(start_idx == -1) return "";

        return s.substr(start_idx, min_len);
    }
};