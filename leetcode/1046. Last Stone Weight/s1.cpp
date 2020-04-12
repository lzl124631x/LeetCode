// OJ: https://leetcode.com/problems/last-stone-weight/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int lastStoneWeight(vector<int>& A) {
        priority_queue<int> pq(begin(A), end(A));
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a - b);
        }
        return pq.top();
    }
};