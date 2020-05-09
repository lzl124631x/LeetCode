// OJ: https://leetcode.com/problems/find-median-from-data-stream/
// Author: github.com/lzl124631x
// Time:
//      MedianFinder: O(1)
//      addNum: O(logN)
//      findMedian: O(1)
// Space: O(N)
class MedianFinder {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> great;
public:
    MedianFinder() {}
    void addNum(int num) {
        if (great.size() && num >= great.top()) {
            great.push(num);
            if (great.size() > small.size() + 1) {
                int n = great.top();
                small.push(n);
                great.pop();
            }
        } else {
            small.push(num);
            if (small.size() > great.size() + 1) {
                int n = small.top();
                great.push(n);
                small.pop();
            }
        }
    }
    double findMedian() {
        return small.size() == great.size() ? (small.top() + great.top()) / 2. : (small.size() > great.size() ? small.top() : great.top());
    }
};