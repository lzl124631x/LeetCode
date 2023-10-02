# [1014. Best Sightseeing Pair (Medium)](https://leetcode.com/problems/best-sightseeing-pair/)

<p>Given an array <code>A</code> of positive integers, <code>A[i]</code> represents the value of the <code>i</code>-th sightseeing spot, and two&nbsp;sightseeing spots <code>i</code> and <code>j</code>&nbsp;have distance <code>j - i</code>&nbsp;between them.</p>

<p>The <em>score</em>&nbsp;of a pair (<code>i &lt; j</code>) of sightseeing spots is (<code>A[i] + A[j] + i&nbsp;- j)</code> : the sum of the values of the sightseeing spots, <strong>minus</strong> the distance between them.</p>

<p>Return the maximum score of a pair of sightseeing spots.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[8,1,5,2,6]</span>
<strong>Output: </strong><span id="example-output-1">11
<strong>Explanation:</strong> i = 0, j = 2, </span><code>A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11</code>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>2 &lt;= A.length &lt;= 50000</code></li>
	<li><code>1 &lt;= A[i] &lt;= 1000</code></li>
</ol>

**Companies**:  
[Wayfair](https://leetcode.com/company/wayfair)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/best-sightseeing-pair/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        stack<pair<int, int>> s;
        for (int i = A.size() - 1; i >= 0; --i) {
            if (s.empty() || s.top().second < A[i] - i) s.emplace(i, A[i] - i);
        }
        int ans = INT_MIN;
        for (int i = 0; i < A.size() - 1; ++i) {
            if (s.top().first <= i) s.pop();
            ans = max(ans, A[i] + i + s.top().second);
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/best-sightseeing-pair/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxVal = A[0], ans = INT_MIN;
        for (int i = 1; i < A.size(); ++i) {
            ans = max(ans, maxVal + A[i] - i);
            maxVal = max(maxVal, A[i] + i);
        }
        return ans;
    }
};
```