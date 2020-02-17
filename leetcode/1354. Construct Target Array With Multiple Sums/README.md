# [1354. Construct Target Array With Multiple Sums (Hard)](https://leetcode.com/problems/construct-target-array-with-multiple-sums/)

<p>Given an array of integers&nbsp;<code>target</code>. From a starting array, <code>A</code>&nbsp;consisting of all 1's, you may perform the following procedure :</p>

<ul>
	<li>let <code>x</code> be the sum of all elements currently in your array.</li>
	<li>choose index <code>i</code>, such that&nbsp;<code>0 &lt;= i &lt; target.size</code> and set the value of <code>A</code> at index <code>i</code> to <code>x</code>.</li>
	<li>You may repeat this procedure&nbsp;as many times as needed.</li>
</ul>

<p>Return True if it is possible to construct the <code>target</code> array from <code>A</code> otherwise&nbsp;return False.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> target = [9,3,5]
<strong>Output:</strong> true
<strong>Explanation:</strong> Start with [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> target = [1,1,1,2]
<strong>Output:</strong> false
<strong>Explanation:</strong> Impossible to create target array from [1,1,1,1].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> target = [8,5]
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>N == target.length</code></li>
	<li><code>1 &lt;= target.length&nbsp;&lt;= 5 * 10^4</code></li>
	<li><code>1 &lt;= target[i] &lt;= 10^9</code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Work backwards

From the target, try to reach all `1`s.

Repeat the following steps:
1. Assume the largest number be `m`. If `m == 1`, then return `true`.
2. otherwise, let `n = m - sum({ other numbers })`.
    * if `n < 1`, return `false`.
    * otherwise, replace `m` with `n`.

Case 1: `[3, 5, 9]`
* `[3,5,9]`, `9 - (3 + 5) = 1`, so we can get `[1, 3, 5]`.
* `[1,3,5]`, `5 - (1 + 3) = 1`, so we can get `[1, 1, 3]`.
* `[1,1,3]`, `3 - (1 + 1) = 1`, so we can get `[1, 1, 1]`.

Case 2: `[1,1,1,2]`
* `[1,1,1,2]`, `2 - (1 + 1 + 1) = -1 < 1`, invalid, return false.

Case 3: `[8,5]`
* `[8,5]`, `8 - 5 = 3`, so we can get `[3,5]`
* `[3,5]`, `5 - 3 = 2`, so we can get `[2,3]`
* `[2,3]`, `3 - 2 = 1`, so we can get `[1,2]`
* `[1,2]`, `2 - 1 = 1`, so we can get `[1,1]`.


```cpp
// OJ: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
// Author: github.com/lzl124631x
// Time: O(TlogN) where T is the steps to get to targets, N is the length of targets
// Space: O(N)
typedef long long LL;
class Solution {
public:
    bool isPossible(vector<int>& A) {
        LL sum = accumulate(A.begin(), A.end(), (LL)0);
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
```