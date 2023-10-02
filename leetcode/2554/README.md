# [2554. Maximum Number of Integers to Choose From a Range I (Medium)](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i)

<p>You are given an integer array <code>banned</code> and two integers <code>n</code> and <code>maxSum</code>. You are choosing some number of integers following the below rules:</p>

<ul>
	<li>The chosen integers have to be in the range <code>[1, n]</code>.</li>
	<li>Each integer can be chosen <strong>at most once</strong>.</li>
	<li>The chosen integers should not be in the array <code>banned</code>.</li>
	<li>The sum of the chosen integers should not exceed <code>maxSum</code>.</li>
</ul>

<p>Return <em>the <strong>maximum</strong> number of integers you can choose following the mentioned rules</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> banned = [1,6,5], n = 5, maxSum = 6
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> You cannot choose any integer while following the mentioned conditions.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> banned = [11], n = 7, maxSum = 50
<strong>Output:</strong> 7
<strong>Explanation:</strong> You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= banned.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= banned[i], n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= maxSum &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[PayPal](https://leetcode.com/company/paypal)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Binary Search](https://leetcode.com/tag/binary-search), [Greedy](https://leetcode.com/tag/greedy), [Sorting](https://leetcode.com/tag/sorting)

**Similar Questions**:
* [First Missing Positive (Hard)](https://leetcode.com/problems/first-missing-positive)
* [Find All Numbers Disappeared in an Array (Easy)](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array)
* [Append K Integers With Minimal Sum (Medium)](https://leetcode.com/problems/append-k-integers-with-minimal-sum)
* [Replace Elements in an Array (Medium)](https://leetcode.com/problems/replace-elements-in-an-array)
* [Maximum Number of Integers to Choose From a Range II (Medium)](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-ii)

**Hints**:
* Keep the banned numbers that are less than n in a set.
* Loop over the numbers from 1 to n and if the number is not banned, use it.
* Keep adding numbers while they are not banned, and their sum is less than k.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i
// Author: github.com/lzl124631x
// Time: O(BlogB + N)
// Space: O(1)
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(begin(banned), end(banned));
        long long ans = 0, sum = 0, i = 0, N = banned.size();
        for (int j = 1; j <= n; ++j) {
            if (i < N && banned[i] == j) {
                while (i < N && banned[i] == j) ++i;
            } else if (sum + j <= maxSum) {
                sum += j;
                ++ans;
            } else break;
        }
        return ans;
    }
};
```