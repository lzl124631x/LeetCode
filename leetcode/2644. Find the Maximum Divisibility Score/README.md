# [2644. Find the Maximum Divisibility Score (Easy)](https://leetcode.com/problems/find-the-maximum-divisibility-score)

<p>You are given two <strong>0-indexed</strong> integer arrays <code>nums</code> and <code>divisors</code>.</p>
<p>The <strong>divisibility score</strong> of <code>divisors[i]</code> is the number of indices <code>j</code> such that <code>nums[j]</code> is divisible by <code>divisors[i]</code>.</p>
<p>Return <em>the integer</em> <code>divisors[i]</code> <em>with the maximum divisibility score</em>. If there is more than one integer with the maximum score, return the minimum of them.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [4,7,9,3,9], divisors = [5,2,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The divisibility score for every element in divisors is:
The divisibility score of divisors[0] is 0 since no number in nums is divisible by 5.
The divisibility score of divisors[1] is 1 since nums[0] is divisible by 2.
The divisibility score of divisors[2] is 3 since nums[2], nums[3], and nums[4] are divisible by 3.
Since divisors[2] has the maximum divisibility score, we return it.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [20,14,21,10], divisors = [5,7,5]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The divisibility score for every element in divisors is:
The divisibility score of divisors[0] is 2 since nums[0] and nums[3] are divisible by 5.
The divisibility score of divisors[1] is 2 since nums[1] and nums[2] are divisible by 7.
The divisibility score of divisors[2] is 2 since nums[0] and nums[3] are divisible by 5.
Since divisors[0], divisors[1], and divisors[2] all have the maximum divisibility score, we return the minimum of them (i.e., divisors[2]).
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [12], divisors = [10,16]
<strong>Output:</strong> 10
<strong>Explanation:</strong> The divisibility score for every element in divisors is:
The divisibility score of divisors[0] is 0 since no number in nums is divisible by 10.
The divisibility score of divisors[1] is 0 since no number in nums is divisible by 16.
Since divisors[0] and divisors[1] both have the maximum divisibility score, we return the minimum of them (i.e., divisors[0]).
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length, divisors.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], divisors[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[DE Shaw](https://leetcode.com/company/de-shaw)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Binary Prefix Divisible By 5 (Easy)](https://leetcode.com/problems/binary-prefix-divisible-by-5/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-the-maximum-divisibility-score
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int maxDivScore(vector<int>& A, vector<int>& D) {
        int mxScore = 0, ans = D[0];
        for (int d : D) {
            int score = 0;
            for (int n : A) {
                score += n % d == 0;
            }
            if (score > mxScore) {
                mxScore = score;
                ans = d;
            } else if (score == mxScore && d < ans) ans = d;
        }
        return ans;
    }
};
```