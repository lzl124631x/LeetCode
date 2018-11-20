// OJ: https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Author: github.com/lzl124631x
// Time:
//     KthLargest: O(NlogK)
//     add: O(logK)
// Space: O(N)
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
public:
    KthLargest(int k, vector<int> nums): k(k) {
        for (int n : nums) {
            q.push(n);
            if (q.size() > k) q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > k) q.pop();
        return q.top();
    }
};