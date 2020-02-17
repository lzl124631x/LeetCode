// OJ: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/510263/JavaC%2B%2BPython-Priority-Queue
class Solution {
public:
    int maxEvents(vector<vector<int>>& A) {
        sort(A.begin(), A.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int N = A.size(), i = 0, day = A[0][0], ans = 0;
        while (i < N || pq.size()) {
            if (pq.empty()) day = A[i][0];
            while (i < N && A[i][0] == day) pq.push(A[i++][1]);
            pq.pop();
            ++ans;
            ++day;
            while (pq.size() && pq.top() < day) pq.pop();
        }
        return ans;
    }
};