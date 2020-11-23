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

Let `sum` be the sum of all numbers.

Repeat the following steps:
* Get the largest number `n`. Update `n` to be `next = n % {sum of all other numbers}`, i.e. `next = n % (sum - n)`.
* Decrease `sum` by `n - next`.
* Repeat until the sum of all numbers become `A.size()`.

Some corner cases:
1. If `sum - n == 1`, return `true`.
2. If `n < sum - n`, return `false`.
3. If `n % (sum - n) == 0`, return `false`.

```cpp
// OJ: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool isPossible(vector<int>& A) {
        if (A.size() == 1) return A[0] == 1;
        long sum = accumulate(begin(A), end(A), 0L), N = A.size();
        priority_queue<int> pq(begin(A), end(A));
        while (sum > N) {
            long n = pq.top();
            pq.pop();
            if (sum - n == 1) return true; 
            if (n < sum - n) return false;
            long next = n % (sum - n);
            if (next == 0) return false;
            sum -= n - next;
            pq.push(next);
        }
        return true;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    bool isPossible(vector<int>& A) {
        long sum = accumulate(begin(A), end(A), 0L);
        priority_queue<int> pq(begin(A), end(A));
        while (true) {
            long n = pq.top();
            pq.pop();
            sum -= n;
            if (n == 1 || sum == 1) return true;
            if (n < sum || sum == 0 || n % sum == 0) return false;
            n %= sum;
            sum += n;
            pq.push(n);
        }
    }
};
```