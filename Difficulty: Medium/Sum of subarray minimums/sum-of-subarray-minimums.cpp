class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n = arr.size();
        int ans = 0;
        // for(int i = 0; i<n ; i++){
        //     int mini = arr[i];
        //     for(int j = i; j<n ; j++){
        //         mini = min(mini,arr[j]);
                
        //         ans += mini;
        //     }
        // }
        
        stack<int>s;
        vector<int>nse(n,-1);
        vector<int>pse(n,0);
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                nse[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            
            if(nse[i]==-1){
                pse[i] = (i+1)*arr[i];
            }
            else{
                int k = i-nse[i];
                pse[i]=arr[i]*k;
                pse[i]+=pse[nse[i]];
            }
            
            ans += pse[i];
        }
        return ans;
    }
};