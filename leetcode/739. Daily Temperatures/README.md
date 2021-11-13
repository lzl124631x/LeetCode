# [739. Daily Temperatures (Medium)](https://leetcode.com/problems/daily-temperatures/)

<p>Given an array of integers <code>temperatures</code> represents the daily temperatures, return <em>an array</em> <code>answer</code> <em>such that</em> <code>answer[i]</code> <em>is the number of days you have to wait after the</em> <code>i<sup>th</sup></code> <em>day to get a warmer temperature</em>. If there is no future day for which this is possible, keep <code>answer[i] == 0</code> instead.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> temperatures = [73,74,75,71,69,72,76,73]
<strong>Output:</strong> [1,1,4,2,1,1,0,0]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> temperatures = [30,40,50,60]
<strong>Output:</strong> [1,1,1,0]
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> temperatures = [30,60,90]
<strong>Output:</strong> [1,1,0]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;temperatures.length &lt;= 10<sup>5</sup></code></li>
	<li><code>30 &lt;=&nbsp;temperatures[i] &lt;= 100</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple), [Zillow](https://leetcode.com/company/zillow), [Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg), [Adobe](https://leetcode.com/company/adobe), [Microsoft](https://leetcode.com/company/microsoft), [Uber](https://leetcode.com/company/uber), [DE Shaw](https://leetcode.com/company/de-shaw)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Stack](https://leetcode.com/tag/stack/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/)

**Similar Questions**:
* [Next Greater Element I (Easy)](https://leetcode.com/problems/next-greater-element-i/)
* [Online Stock Span (Medium)](https://leetcode.com/problems/online-stock-span/)

## Solution 1. Monotonic Stack

Scan from right to left, use a stack `s` to track the index of large numbers.

For `A[i]`, keep popping `s` if `A[s.top()] <= A[i]`. Then the answer for `A[i]` is `s.top() - i` if `s` is not empty; otherwise `0`. Push `i` into the stack and repeat the process.

```cpp
// OJ: https://leetcode.com/problems/daily-temperatures/
// Author: github.com/lzl124631x
// Time: O(T)
// Space: O(T)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& A) {
        stack<int> s;
        vector<int> ans(A.size());
        for (int i = A.size() - 1; i >= 0; --i) {
            while (s.size() && A[s.top()] <= A[i]) s.pop();
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
    vector<int> dailyTemperatures(vector<int>& A) {
        vector<int> ans(A.size());
        stack<int> s;
        for (int i = 0; i < A.size(); ++i) {
            while (s.size() && A[s.top()] < A[i]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
```