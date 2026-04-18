class Solution {
public:
    int maxGain(vector<int>& arr){
        int sum = 0, ans = 0;
        for(int x: arr){
            sum += x;
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        }
        return ans;
    }

    int maxOnes(vector<int>& arr) {
        int oneCnt = 0;

        for(int x: arr)
            if(x == 1) oneCnt++;

        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 1) arr[i] = -1;
            else arr[i] = 1;
        }

        int maxDiff = maxGain(arr);
        return oneCnt + maxDiff;
    }
};