# [456. 132 Pattern (Medium)](https://leetcode.com/problems/132-pattern)

<p>Given an array of <code>n</code> integers <code>nums</code>, a <strong>132 pattern</strong> is a subsequence of three integers <code>nums[i]</code>, <code>nums[j]</code> and <code>nums[k]</code> such that <code>i &lt; j &lt; k</code> and <code>nums[i] &lt; nums[k] &lt; nums[j]</code>.</p>
<p>Return <code>true</code><em> if there is a <strong>132 pattern</strong> in </em><code>nums</code><em>, otherwise, return </em><code>false</code><em>.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no 132 pattern in the sequence.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,1,4,2]
<strong>Output:</strong> true
<strong>Explanation:</strong> There is a 132 pattern in the sequence: [1, 4, 2].
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [-1,3,2,0]
<strong>Output:</strong> true
<strong>Explanation:</strong> There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Stack](https://leetcode.com/tag/stack/), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack/), [Ordered Set](https://leetcode.com/tag/ordered-set/)


## Solution 1. Multiset

For a given middle element `A[i]`, we'd want to use the minimum element to the left of `A[i]` (denote as `a`), and then find the greatest elemnt to the right of `A[i]` which is smaller than `A[i]` (denote as `b`).

For `a` it's easy: we can just use a single variable to keep track of the minimum elemenent we've seen thus far. 

For `b`, we can use a multiset to hold all the values to the right of `A[i]` in descending order, and use binary search to find the greatest element that is smaller than `A[i]`.

```cpp
// OJ: https://leetcode.com/problems/132-pattern/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool find132pattern(vector<int>& A) {
        multiset<int, greater<int>> s(begin(A), end(A));
        int mn = INT_MAX;
        for (int n : A) {
            mn = min(mn, n);
            s.erase(s.find(n));
            auto it = s.upper_bound(n);
            if (it != s.end() && mn < *it) return true;
        }
        return false;
    }
};
```

## Solution 2. Monotonic Stack

Assume the sequence is `a, b, c` (`a < c < b`).

We scan from the right to the left. Keep a monotonically decreasing stack `s` storing candidate value of `b`, and keep track of the last popped value as the best candidate of `c` in a variable `right`.

The best candidate of `c` must be monotonically increasing because the moment we find that the current element is `< c`, we've found a valid sequence.

As for the stack `s`, we pop all the elements that are smaller than `A[i]`, store the last popped element in `right`, and then push `A[i]` into the stack. Thus `s.top()` and `right` forms a best candidate `b, c` sequence.

Once we find `A[i] < right`, we can return `true`.

```cpp
// OJ: https://leetcode.com/problems/132-pattern/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/132-pattern/discuss/94071/Single-pass-C%2B%2B-O(n)-space-and-time-solution-(8-lines)-with-detailed-explanation.
class Solution {
public:
    bool find132pattern(vector<int>& A) {
        stack<int> s;
        int right = INT_MIN;
        for (int i = A.size() - 1; i >= 0; --i) {
            if (A[i] < right) return true;
            while (s.size() && s.top() < A[i]) {
                right = s.top();
                s.pop();
            }
            s.push(A[i]);
        }
        return false;
    }
};
```