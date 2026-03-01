// User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr, int n) {
        // code here
        if(arr[n-1] < 9){
            arr[n-1]++;
            return arr;
        }

        int carry = 0;
        for(int i = n-1; i>= 0 ; i--){
            if(arr[n-1] == 9){
                arr[i] = 0;
                carry = 1;
                continue;
            }
            if(carry == 1 && arr[i]==9){
                arr[i] = 0;
                carry = 1;
                continue;
            }
            else if(carry == 1){
                arr[i]++;
                carry = 0;
                break;
            }
        }
        if(carry != 1){
            return arr;
        }
        else{
            arr[0] = 1;
            arr.push_back(0);
        }
        return arr;
    }
};