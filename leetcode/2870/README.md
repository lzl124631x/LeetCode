# [2870. Minimum Number of Operations to Make Array Empty (Medium)](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty)

<p>You are given a <strong>0-indexed</strong> array <code>nums</code> consisting of positive integers.</p>

<p>There are two types of operations that you can apply on the array <strong>any</strong> number of times:</p>

<ul>
	<li>Choose <strong>two</strong> elements with <strong>equal</strong> values and <strong>delete</strong> them from the array.</li>
	<li>Choose <strong>three</strong> elements with <strong>equal</strong> values and <strong>delete</strong> them from the array.</li>
</ul>

<p>Return <em>the <strong>minimum</strong> number of operations required to make the array empty, or </em><code>-1</code><em> if it is not possible</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,3,2,2,4,2,3,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can apply the following operations to make the array empty:
- Apply the first operation on the elements at indices 0 and 3. The resulting array is nums = [3,3,2,4,2,3,4].
- Apply the first operation on the elements at indices 2 and 4. The resulting array is nums = [3,3,4,3,4].
- Apply the second operation on the elements at indices 0, 1, and 3. The resulting array is nums = [4,4].
- Apply the first operation on the elements at indices 0 and 1. The resulting array is nums = [].
It can be shown that we cannot make the array empty in less than 4 operations.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,1,2,2,3,3]
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is impossible to empty the array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


## Solution 1.

Find pattern

cnt|#|operations
---|---|---
1|-1|
2|1|2
3|1|3
4|2|22
5|2|23
6|2|33
7|3|223
8|3|233
9|3|333
10|4|2233

So, if the frequency `cnt` of a unique number is:
* 1, return -1
* `cnt % 3 == 0`, add answer by `cnt / 3`
* otherwise, add answer by `cnt / 3 + 1`

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
public:
    int minOperations(vector<int>& A) {
        unordered_map<int, int> m;
        for (int n : A) m[n]++;
        int ans = 0;
        for (auto &[n, cnt] : m) {
            if (cnt == 1) return -1;
            if (cnt % 3 == 0) ans += cnt / 3;
            else ans += cnt / 3 + 1;
        }
        return ans;
    }
};
```