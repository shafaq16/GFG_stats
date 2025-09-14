class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int sum1 = 0, sum2 = 0; //total gas and cost.
       
        for(int i =0 ; i<n;i++){
            sum1 += gas[i];
            sum2 += cost[i];
        }
        if(sum1<sum2) return -1;
        
        int fill = 0, start = 0;
        for(int i =0 ; i<n;i++){
            fill += (gas[i]-cost[i]);
            if(fill<0){
                fill = 0;
                start = i+1;
            }
        }
        return start;
    }
};