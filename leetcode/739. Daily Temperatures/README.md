# [739. Daily Temperatures (Medium)](https://leetcode.com/problems/daily-temperatures/)

<p>
Given a list of daily temperatures <code>T</code>, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature.  If there is no future day for which this is possible, put <code>0</code> instead.
</p><p>
For example, given the list of temperatures <code>T = [73, 74, 75, 71, 69, 72, 76, 73]</code>, your output should be <code>[1, 1, 4, 2, 1, 1, 0, 0]</code>.
</p>

<p><b>Note:</b>
The length of <code>temperatures</code> will be in the range <code>[1, 30000]</code>.
Each temperature will be an integer in the range <code>[30, 100]</code>.
</p>

## Solution 1. Monotonic Stack

Scan from right to left, use a stack `s` to track the index of large numbers.

For `T[i]`, keep popping `s` if `T[s.top()] <= T[i]`. Then the answer for `T[i]` is `s.top() - i` if `s` is not empty; otherwise `0`. Push `i` into the stack and repeat the process.

```cpp
// OJ: https://leetcode.com/problems/daily-temperatures/
// Author: github.com/lzl124631x
// Time: O(T)
// Space: O(T)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> ans(T.size());
        for (int i = T.size() - 1; i >= 0; --i) {
            while (s.size() && T[s.top()] <= T[i]) s.pop();
            ans[i] = s.size() ? s.top() - i : 0;
            s.push(i);
        }
        return ans;
    }
};
```

## Solution 2. Monotonic Stack

Same idea as in [496. Next Greater Element I (Easy)](https://leetcode.com/problems/next-greater-element-i/).

```cpp
// OJ: https://leetcode.com/problems/daily-temperatures/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size());
        stack<int> s;
        for (int i = 0; i < T.size(); ++i) {
            while (s.size() && T[s.top()] < T[i]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
```