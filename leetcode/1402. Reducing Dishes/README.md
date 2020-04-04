# [1402. Reducing Dishes (Hard)](https://leetcode.com/problems/reducing-dishes/)

<p>A chef&nbsp;has collected data on the <code>satisfaction</code> level of his&nbsp;<code>n</code> dishes.&nbsp;Chef can cook any dish in 1 unit of time.</p>

<p><em>Like-time coefficient</em>&nbsp;of a dish is defined as&nbsp;the time taken to cook that dish including previous dishes multiplied by its satisfaction level &nbsp;i.e.&nbsp; <code>time[i]</code>*<code>satisfaction[i]</code></p>

<p>Return&nbsp;the maximum sum of&nbsp;<em>Like-time coefficient </em>that the chef can obtain after dishes preparation.</p>

<p>Dishes can be prepared in <strong>any </strong>order and the chef can discard some dishes to get this maximum value.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> satisfaction = [-1,-8,0,5,-9]
<strong>Output:</strong> 14
<strong>Explanation: </strong>After Removing the second and last dish, the maximum total <em>Like-time coefficient</em> will be equal to (-1*1 + 0*2 + 5*3 = 14). Each dish is prepared in one unit of time.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> satisfaction = [4,3,2]
<strong>Output:</strong> 20
<strong>Explanation:</strong> Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> satisfaction = [-1,-4,-5]
<strong>Output:</strong> 0
<strong>Explanation:</strong> People don't like the dishes. No dish is prepared.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> satisfaction = [-2,5,-1,0,3,-3]
<strong>Output:</strong> 35
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == satisfaction.length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>-10^3 &lt;=&nbsp;satisfaction[i] &lt;= 10^3</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/reducing-dishes/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
    typedef long long LL;
public:
    int maxSatisfaction(vector<int>& A) {
        int N = A.size();
        sort(A.begin(), A.end());
        LL ans = 0;
        for (int i = 0; i < N; ++i) {
            LL sum = 0;
            for (int j = i; j < N; ++j) sum += A[j] * (j - i + 1);
            ans = max(ans, sum);
        }
        return ans;
    }
};
```

## Solution 2. Prefix Sum

If array is sorted in descending order. The answer is one of the following:

* B[0] = A[0] * 1
* B[1] = A[0] * 2 + A[1] * 1
* B[2] = A[0] * 3 + A[1] * 2 + A[2] * 1
* ...

And we have

* B[0] = Sum(0)
* B[1] = B[0] + Sum(1)
* B[2] = B[1] + Sum(2)
* ...

Where `Sum(i) = A[0] + ... + A[i]`, i.e. prefix sum of `A`.

* B[0] = Sum(0)
* B[1] = Sum(0) + Sum(1)
* B[2] = Sum(0) + Sum(1) + Sum(2)
* ...

And thus `B` is the prefix sum of prefix sum of `A`.

```cpp
// OJ: https://leetcode.com/problems/reducing-dishes/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxSatisfaction(vector<int>& A) {
        sort(begin(A), end(A), greater<int>());
        partial_sum(begin(A), end(A), begin(A));
        partial_sum(begin(A), end(A), begin(A));
        return max(0, *max_element(begin(A), end(A)));
    }
};
```