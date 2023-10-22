# [2355. Maximum Number of Books You Can Take (Hard)](https://leetcode.com/problems/maximum-number-of-books-you-can-take)

<p>You are given a <strong>0-indexed</strong> integer array <code>books</code> of length <code>n</code> where <code>books[i]</code> denotes the number of books on the <code>i<sup>th</sup></code> shelf of a bookshelf.</p>

<p>You are going to take books from a <strong>contiguous</strong> section of the bookshelf spanning from <code>l</code> to <code>r</code> where <code>0 &lt;= l &lt;= r &lt; n</code>. For each index <code>i</code> in the range <code>l &lt;= i &lt; r</code>, you must take <strong>strictly fewer</strong> books from shelf <code>i</code> than shelf <code>i + 1</code>.</p>

<p>Return <em>the <strong>maximum</strong> number of books you can take from the bookshelf.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> books = [8,5,2,7,9]
<strong>Output:</strong> 19
<strong>Explanation:</strong>
- Take 1 book from shelf 1.
- Take 2 books from shelf 2.
- Take 7 books from shelf 3.
- Take 9 books from shelf 4.
You have taken 19 books, so return 19.
It can be proven that 19 is the maximum number of books you can take.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> books = [7,0,3,4,5]
<strong>Output:</strong> 12
<strong>Explanation:</strong>
- Take 3 books from shelf 2.
- Take 4 books from shelf 3.
- Take 5 books from shelf 4.
You have taken 12 books so return 12.
It can be proven that 12 is the maximum number of books you can take.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> books = [8,2,3,7,3,4,0,1,4,3]
<strong>Output:</strong> 13
<strong>Explanation:</strong>
- Take 1 book from shelf 0.
- Take 2 books from shelf 1.
- Take 3 books from shelf 2.
- Take 7 books from shelf 3.
You have taken 13 books so return 13.
It can be proven that 13 is the maximum number of books you can take.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= books.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= books[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Stack](https://leetcode.com/tag/stack), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack)

**Similar Questions**:
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence)
* [Maximum Ascending Subarray Sum (Easy)](https://leetcode.com/problems/maximum-ascending-subarray-sum)
* [Beautiful Towers II (Medium)](https://leetcode.com/problems/beautiful-towers-ii)
* [Beautiful Towers I (Medium)](https://leetcode.com/problems/beautiful-towers-i)

**Hints**:
* Create a dp array where dp[i] is the maximum number of books you can take if you can only take books from bookshelves 0 to i and you must take books from bookshelf i.
* Keep taking as many books as you can (i.e. starting from bookshelf i and going backwards, you take arr[i], arr[i] - 1, arr[i] - 2, … books).
* You may reach an index j where arr[j] < arr[i] - (i - j). Have we already found the maximum number of books you can take from bookshelves 0 to j? How do we quickly find such an index j?
* Keep a stack of possible indices for j. If x is the number at the top of the stack, keep popping from the stack while arr[x] ≥ arr[i] - (i - x). This is because if the inequality mentioned before is true, x will never be an index j as index i will run out of items first.

## Solution 1. Stack

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-books-you-can-take
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long maximumBooks(vector<int>& A) {
        long long N = A.size(), sum = 0, ans = 0;
        stack<long long> idx, val;
        for (int i = 0; i < N; ++i) {
            while (idx.size() && i - idx.top() >= A[i] - A[idx.top()]) {
                idx.pop();
                sum -= val.top();
                val.pop();
            }
            long long prev = idx.size() ? idx.top() : -1, len = min(i - prev, (long long)A[i]);
            idx.push(i);
            long long s = A[i] * len - len * (len - 1) / 2;
            sum += s;
            ans = max(ans, sum);
            val.push(s);
        }
        return ans;
    }
};
```