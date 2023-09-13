# [1482. Minimum Number of Days to Make m Bouquets (Medium)](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)

<p>Given an integer array <code>bloomDay</code>, an integer <code>m</code> and an integer <code>k</code>.</p>

<p>We need to make <code>m</code>&nbsp;bouquets. To make a bouquet,&nbsp;you need to use <code>k</code> <strong>adjacent flowers</strong> from the garden.</p>

<p>The garden consists of <code>n</code> flowers, the <code>ith</code> flower will bloom in the <code>bloomDay[i]</code>&nbsp;and then can be used in&nbsp;<strong>exactly one</strong> bouquet.</p>

<p>Return <em>the minimum number of days</em> you need to wait to be able to make <code>m</code> bouquets from the garden. If it is impossible to make <code>m</code> bouquets return <strong>-1</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> bloomDay = [1,10,3,10,2], m = 3, k = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> Let's see what happened in the first three days. x means flower bloomed and _ means flower didn't bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> bloomDay = [1,10,3,10,2], m = 3, k = 2
<strong>Output:</strong> -1
<strong>Explanation:</strong> We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
<strong>Output:</strong> 12
<strong>Explanation:</strong> We need 2 bouquets each should have 3 flowers.
Here's the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> bloomDay = [1000000000,1000000000], m = 1, k = 1
<strong>Output:</strong> 1000000000
<strong>Explanation:</strong> You need to wait 1000000000 days to have a flower ready for a bouquet.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> bloomDay = [1,10,2,9,3,8,4,7,5,6], m = 4, k = 2
<strong>Output:</strong> 9
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>bloomDay.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>1 &lt;= bloomDay[i] &lt;= 10^9</code></li>
	<li><code>1 &lt;= m &lt;= 10^6</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Binary Answer

* we can detect whether a given day `A[i]` can form the required output in `O(N)` time.
* we can try out each unique day in ascending order. The first one that satisfies the requirement is the answer.

But this would require `O(N^2)` time complexity.

Instead of trying each unique data linearly, we can binary search on those unique days to reduce the time complexity.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Author: github.com/lzl124631x
// Time: O(NlogU) where U is the count of unique days
// Space: O(N)
class Solution {
    bool valid(vector<int> &A, int n, int m, int k) {
        int N = A.size(), cnt = 0, j = 0;
        while (j < N) {
            int i = j;
            while (j < N && j - i < k && A[j] <= n) ++j; 
            if (j - i == k) ++cnt;
            if (cnt >= m) return true;
            while (j < N && A[j] > n) ++j;
        }
        return false;
    }
public:
    int minDays(vector<int>& A, int m, int k) {
        if (A.size() < m * k) return -1;
        set<int> s(begin(A), end(A));
        vector<int> u(begin(s), end(s));
        int L = 0, R = u.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(A, u[M], m, k)) R = M - 1;
            else L = M + 1;
        }
        return u[L];
    }
};
```

## Solution 2. Binary Answer

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Author: github.com/lzl124631x
// Time: O(Nlog(max(A)))
// Space: O(1)
// Ref: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/discuss/686316/JavaC%2B%2BPython-Binary-Search
class Solution {
public:
    int minDays(vector<int>& A, int m, int k) {
        int N = A.size(), L = 1, R = 1e9;
        if (N < m * k) return -1;
        while (L <= R) {
            int M = (L + R) / 2, cnt = 0, cur = 0;
            for (int j = 0; j < N; ++j) {
                if (A[j] > M) cur = 0;
                else if (++cur >= k) {
                    ++cnt;
                    cur = 0;
                }
            }
            if (cnt < m) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};
```