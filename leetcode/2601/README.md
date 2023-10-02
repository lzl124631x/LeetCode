# [2601. Prime Subtraction Operation (Medium)](https://leetcode.com/problems/prime-subtraction-operation)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code>.</p>

<p>You can perform the following operation as many times as you want:</p>

<ul>
	<li>Pick an index <code>i</code> that you haven&rsquo;t picked before, and pick a prime <code>p</code> <strong>strictly less than</strong> <code>nums[i]</code>, then subtract <code>p</code> from <code>nums[i]</code>.</li>
</ul>

<p>Return <em>true if you can make <code>nums</code> a strictly increasing array using the above operation and false otherwise.</em></p>

<p>A <strong>strictly increasing array</strong> is an array whose each element is strictly greater than its preceding element.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,9,6,10]
<strong>Output:</strong> true
<strong>Explanation:</strong> In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
After the second operation, nums is sorted in strictly increasing order, so the answer is true.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [6,8,11,12]
<strong>Output:</strong> true
<strong>Explanation: </strong>Initially nums is sorted in strictly increasing order, so we don&#39;t need to make any operations.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,8,3]
<strong>Output:</strong> false
<strong>Explanation:</strong> It can be proven that there is no way to perform operations to make nums sorted in strictly increasing order, so the answer is false.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code><font face="monospace">nums.length == n</font></code></li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Math](https://leetcode.com/tag/math), [Binary Search](https://leetcode.com/tag/binary-search), [Greedy](https://leetcode.com/tag/greedy), [Number Theory](https://leetcode.com/tag/number-theory)

**Hints**:
* Think about if we have many primes to subtract from nums[i]. Which prime is more optimal?
* The most optimal prime to subtract from nums[i] is the one that makes nums[i] the smallest as possible and greater than nums[i-1].

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/prime-subtraction-operation
// Author: github.com/lzl124631x
// Time: O(NP) where N is the length of `A` and `P` is the number of primes within 1000
// Space: O(P)
class Solution {
public:
    bool primeSubOperation(vector<int>& A) {
        bool prime[1001] = {[0 ... 1000] = true};
        vector<int> primes;
        for (int i = 2; i <= 1000; ++i) {
            if (!prime[i]) continue;
            primes.push_back(i);
            int j = i * i;
            for (; j <= 1000; j += i) prime[j] = false;
        }
        for (int i = 0; i < A.size(); ++i) {
            int prev = i == 0 ? -1 : A[i - 1], j = lower_bound(begin(primes), end(primes), A[i]) - begin(primes) - 1;
            while (j >= 0 && A[i] - primes[j] <= prev) --j;
            if (j >= 0) A[i] -= primes[j];
            if (A[i] <= prev) return false;
        }
        return true;
    }
};
```

Or use binary search to find the optimal prime number directly.

```cpp
// OJ: https://leetcode.com/problems/prime-subtraction-operation
// Author: github.com/lzl124631x
// Time: O(NlogP)
// Space: O(P)
class Solution {
public:
    bool primeSubOperation(vector<int>& A) {
        bool prime[1001] = {[0 ... 1000] = true};
        vector<int> primes{0};
        for (int i = 2; i <= 1000; ++i) {
            if (!prime[i]) continue;
            primes.push_back(i);
            int j = i * i;
            for (; j <= 1000; j += i) prime[j] = false;
        }
        for (int i = 0; i < A.size(); ++i) {
            int prev = i == 0 ? -1 : A[i - 1], L = 0, R = primes.size() - 1;
            while (L <= R) {
                int M = (L + R) / 2;
                if (primes[M] < A[i] && A[i] - primes[M] > prev) L = M + 1;
                else R = M - 1;
            }
            if (R < 0) return false;
            A[i] -= primes[R];
        }
        return true;
    }
};
```