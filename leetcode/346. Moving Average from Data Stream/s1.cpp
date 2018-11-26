// OJ: https://leetcode.com/problems/moving-average-from-data-stream/
// Author: github.com/lzl124631x
// Time:
//     MovingAverage: O(1)
//     next: O(1)
// Space: O(S)
class MovingAverage {
private:
    queue<int> q;
    int size, sum = 0;
public:
    MovingAverage(int size) : size(size) { }
    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return (double)sum / q.size();
    }
};