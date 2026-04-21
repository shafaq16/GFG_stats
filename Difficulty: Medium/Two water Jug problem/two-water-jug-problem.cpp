class Solution {
  public:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int minSteps(int m, int n, int d) {
        // Code here
        if(d> max(m,n))return -1;
        if(d % gcd(m,n) != 0) return -1;
        
        int ans1 = pour(m,n,d);
        int ans2 = pour(n,m,d);
        return min(ans1,ans2);
    }
    
    int pour(int m, int n, int d){
        int from = m;
        int to = 0;
        int step = 1;
        
        while(from != d && to != d){
            int temp = min(from, n-to);
            to += temp ;
            from -= temp;
            step++;
            
            if(from == d || to == d){
                break;
            }
            if(from == 0){
                from = m;
                step++;
            }
            if(to == n){
                to = 0;
                step++;
            }
        }
        return step;
    }
};