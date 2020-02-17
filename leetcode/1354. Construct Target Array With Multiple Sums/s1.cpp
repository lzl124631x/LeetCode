// OJ: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
// Author: github.com/lzl124631x
// Time: O(TlogN) where T is the steps to get to targets, N is the length of targets
// Space: O(N)
typedef long long LL;
class Solution {
public:
    bool isPossible(vector<int>& A) {
        LL sum = accumulate(A.begin(), A.end(), 0LL);
        priority_queue<LL> pq(A.begin(), A.end());
        while (pq.top() != 1) {
            LL n = pq.top();
            pq.pop();
            LL rest = sum - n;
            if (n - rest < 1) return false;
            pq.push(n - rest);
            sum -= rest;
        }
  
        return true;
    }
};