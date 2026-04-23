// class Solution {
//   public:
//     bool canSplit(vector<int>& arr) {
//         // code here
//         int total = 0;
//         for(int x : arr) total += x;
//         if(total%2 != 0) return false;
//         int n = arr.size();
//         if(n==1) return false;
//         int i = 0, j = n-1;
//         int sum1 = arr[i], sum2 = arr[j];
//         while(i<j){
//             if(sum1<sum2){
//                 sum1 += arr[i++];
//             }
//             else{
//                 sum2 += arr[j--];
//             }
//         }
//         return sum1==sum2;
//     }
// };

class Solution {
public:
    bool canSplit(vector<int>& arr) {
        int total = 0;
        for(int x : arr) total += x;

        if(total % 2 != 0) return false;

        int curr = 0;
        for(int i = 0; i < arr.size(); i++){
            curr += arr[i];
            if(curr == total / 2) return true;
        }

        return false;
    }
};