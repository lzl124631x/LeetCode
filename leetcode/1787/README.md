# [1787. Make the XOR of All Segments Equal to Zero (Hard)](https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/)

<p>You are given an array <code>nums</code>​​​ and an integer <code>k</code>​​​​​. The <font face="monospace">XOR</font> of a segment <code>[left, right]</code> where <code>left &lt;= right</code> is the <code>XOR</code> of all the elements with indices between <code>left</code> and <code>right</code>, inclusive: <code>nums[left] XOR nums[left+1] XOR ... XOR nums[right]</code>.</p>

<p>Return <em>the minimum number of elements to change in the array </em>such that the <code>XOR</code> of all segments of size <code>k</code>​​​​​​ is equal to zero.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,0,3,0], k = 1
<strong>Output:</strong> 3
<strong>Explanation: </strong>Modify the array from [<u><strong>1</strong></u>,<u><strong>2</strong></u>,0,<u><strong>3</strong></u>,0] to from [<u><strong>0</strong></u>,<u><strong>0</strong></u>,0,<u><strong>0</strong></u>,0].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,4,5,2,1,7,3,4,7], k = 3
<strong>Output:</strong> 3
<strong>Explanation: </strong>Modify the array from [3,4,<strong><u>5</u></strong>,<strong><u>2</u></strong>,<strong><u>1</u></strong>,7,3,4,7] to [3,4,<strong><u>7</u></strong>,<strong><u>3</u></strong>,<strong><u>4</u></strong>,7,3,4,7].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,4,1,2,5,1,2,6], k = 3
<strong>Output:</strong> 3
<strong>Explanation: </strong>Modify the array from [1,2,<strong><u>4,</u></strong>1,2,<strong><u>5</u></strong>,1,2,<strong><u>6</u></strong>] to [1,2,<strong><u>3</u></strong>,1,2,<strong><u>3</u></strong>,1,2,<strong><u>3</u></strong>].</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 2000</code></li>
	<li><code>​​​​​​0 &lt;= nums[i] &lt; 2<sup>10</sup></code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)


## Thoughts

First turn the array `A` into the XOR results. Let `v[i] = A[i] ^ A[i + 1] ^ ... ^ A[i + k - 1]`

Example:

```
A = [3,4,5,2,1,7,3,4,7]
v = [2,3,6,4,5,0,0]
```

To turn `v[0]` to `0`, we have `k` options.

* We change `A[0]` to `A[0] ^ v[0]`, then only `v[0]` becomes `0`.
* We change `A[1]` to `A[1] ^ v[0]`, then `v[0]` becomes `0`, `v[1]` becomes `v[1] ^ v[0]`.
* We change `A[2]` to `A[2] ^ v[0]`, then `v[0]` becomes `0`, `v[1]` becomes `v[1] ^ v[0]`, `v[2]` becomes `v[2] ^ v[0]`.
* ...
* We change `A[k - 1]` to `A[k - 1] ^ v[0]`, then `v[0]` becomes `0`, `v[1]` becomes `v[1] ^ v[0]`, ..., `v[k - 1]` becomes `v[k - 1] ^ v[0]`.

From these `k` options, we select the optimal one.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
public:
    int minChanges(vector<int>& v, int k) {
        int n = v.size();
        // freq[i][x] = frequency of the number x at position i where i in [0, k - 1]
        vector<vector<int> > freq(k, vector<int>(1024, 0));
        /* dp[i][j] = minimum total number of elements we need to change from index 0 to i so that
           the xor of the subarray from index 0 to i is equal to j */
        vector<vector<int> > dp(k, vector<int>(1024, n + 1));
        // numsAtPosition[i] = set of unique numbers at position i where i in [0, k - 1]
        unordered_set<int> numsAtPosition[k];
        for(int i = 0; i < n; i++) {
            int position = i % k;
            freq[position][v[i]]++;
            numsAtPosition[position].insert(v[i]);
        }
        int bestUptoLast = 0;
        for(int i = 0; i < k; i++) { // this loop runs k times
            // how many i indices exist in the array
            int cntOfPos = n / k + (((n % k) > i) ? 1 : 0);
            // will track best value at i
            int bestAti = n + 1;
            // find the best way to make the xor sum equal to j from index 0 to i
            for(int j = 0; j < 1024; j++) { // this loop runs 1024 times
                if(i == 0) {
                    dp[i][j] = cntOfPos - freq[i][j];
                }
                else {
                    // iterate over all numbers that occur at index i
                    for(auto x : numsAtPosition[i]) { // this loop runs n/k times
                        dp[i][j] = min(dp[i][j], dp[i - 1][j ^ x] + cntOfPos - freq[i][x]);
                    }
                    // this will do for all the numbers that don't occur at index i
                    // we are changing all the numbers at index i with an arbitrary number that gives best result
                    dp[i][j] = min(dp[i][j], bestUptoLast + cntOfPos);
                }
                bestAti = min(bestAti, dp[i][j]);
            }
            bestUptoLast = bestAti;
        }
        return dp[k - 1][0];
    }
};
```