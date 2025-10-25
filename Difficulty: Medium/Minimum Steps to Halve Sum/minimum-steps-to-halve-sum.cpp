#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& arr) {

        double sum = 0;
        for (int x : arr) sum += x;
        double target = sum / 2.0;

        priority_queue<double> pq;
        for (int x : arr) {
            pq.push((double)x);
        }

        int ops = 0;
        double reducedSum = sum;
        while (reducedSum > target) {
            double x = pq.top();
            pq.pop();
            double half = x / 2.0;
            reducedSum -= half;
            pq.push(half);
            ops++;
        }
        return ops;
    }
};
