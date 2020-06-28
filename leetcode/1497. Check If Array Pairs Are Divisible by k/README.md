# [1497. Check If Array Pairs Are Divisible by k (Medium)](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/)

<p>Given an array of integers <code>arr</code> of even length <code>n</code> and an integer <code>k</code>.</p>

<p>We want to divide the array into exactly <code>n /&nbsp;2</code> pairs such that the sum of each pair is divisible by <code>k</code>.</p>

<p>Return <em>True</em> If you can find a way to do that or <em>False</em> otherwise.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,3,4,5,10,6,7,8,9], k = 5
<strong>Output:</strong> true
<strong>Explanation:</strong> Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,3,4,5,6], k = 7
<strong>Output:</strong> true
<strong>Explanation:</strong> Pairs are (1,6),(2,5) and(3,4).
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,3,4,5,6], k = 10
<strong>Output:</strong> false
<strong>Explanation:</strong> You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> arr = [-10,10], k = 2
<strong>Output:</strong> true
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> arr = [-1,1,-2,2,-3,3,-4,4], k = 3
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>arr.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>n</code> is even.</li>
	<li><code>-10^9 &lt;= arr[i] &lt;= 10^9</code></li>
	<li><code>1 &lt;= k &lt;= 10^5</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

Use a map to store the frequencies of remainders and check if each remainder satisfies the requirement.

1. If there are odd number `0` remainders, return false
1. For `1 <= i < k / 2`, if `m[i] != m[k - i]`, return false.

If `k` is an even number, we can return false if `m[k / 2] % 2 != 0` but it's not needed because if `m[k / 2]` is odd, one of the above conditions above must be false.

```cpp
// OJ: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
// Author: github.com/lzl124631x
// Time: O(N + K)
// Space: O(K)
class Solution {
public:
    bool canArrange(vector<int>& A, int k) {
        unordered_map<int, int> m;
        for (int n : A) m[(n % k + k) % k]++;
        if (m[0] % 2) return false;
        for (int i = 1; i < k / 2; ++i) {
            if (m[i] != m[k - i]) return false;
        }
        return true;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
class Solution {
public:
    bool canArrange(vector<int>& A, int k) {
        unordered_map<int, int> m;
        for (int &n : A) {
            n = (n % k + k) % k;
            m[n]++;
        }
        for (int n : A) {
            if ((n == 0 && m[n] % 2) || (n && m[n] != m[k - n])) return false;
        }
        return true;
    }
};
```