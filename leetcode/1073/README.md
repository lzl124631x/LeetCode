# [1073. Adding Two Negabinary Numbers (Medium)](https://leetcode.com/problems/adding-two-negabinary-numbers/)

<p>Given two numbers <code>arr1</code> and <code>arr2</code> in base <strong>-2</strong>, return the result of adding them together.</p>

<p>Each number is given in <em>array format</em>:&nbsp; as an array of 0s and 1s, from most significant bit to least significant bit.&nbsp; For example, <code>arr = [1,1,0,1]</code> represents the number <code>(-2)^3&nbsp;+ (-2)^2 + (-2)^0 = -3</code>.&nbsp; A number <code>arr</code> in <em>array, format</em> is also guaranteed to have no leading zeros: either&nbsp;<code>arr == [0]</code> or <code>arr[0] == 1</code>.</p>

<p>Return the result of adding <code>arr1</code> and <code>arr2</code> in the same format: as an array of 0s and 1s with no leading zeros.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr1 = [1,1,1,1,1], arr2 = [1,0,1]
<strong>Output:</strong> [1,0,0,0,0]
<strong>Explanation: </strong>arr1 represents 11, arr2 represents 5, the output represents 16.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr1 = [0], arr2 = [0]
<strong>Output:</strong> [0]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr1 = [0], arr2 = [1]
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length,&nbsp;arr2.length &lt;= 1000</code></li>
	<li><code>arr1[i]</code>&nbsp;and <code>arr2[i]</code> are&nbsp;<code>0</code> or <code>1</code></li>
	<li><code>arr1</code> and <code>arr2</code> have no leading zeros</li>
</ul>


**Companies**:  
[Grab](https://leetcode.com/company/grab)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

## Solution 1.

When adding two numbers in base `2` I use a variable `carry` to store the carryover.

Assume we are adding two bits `a`, `b` and `carry`. The `sum` can be `0, 1, 2, 3`, and the leftover bit value is `sum % 2` and the new value of `carry` is `sum / 2`.


Let's try the same approach for this problem.

Assume the current bit represents `k = (-2)^n`, (`n >= 0`).

* Consider `carry = 0`, `sum` can be `0, 1, 2`.
  * When `sum = 0` or `1`, `leftover = sum`, `carry = 0`.
  * When `sum = 2`, the value is `2k = -1 * (-2k)`, so it's the same as `leftover = 1, carry = -1`
* Consider `carry = -1`, `sum` can be `-1, 0, 1`.
  * For the new case `sum = -1`, the value is `-k = -2k + k`, so it's the same as `leftover = 1, carry = 1`.
* Consider `carry = 1`, `sum` can be `1, 2, 3`.
  * For the new case `sum = 3`, the value is `3k = -1 * (-2k) + k`, so it's the same as `leftover = 1, carry = -1`.

Now we've considerred all cases. In sum:

sum|leftover|carry|
---|---|---
-1|1|1
0|0|0
1|1|0
2|0|-1
3|1|-1

The pattern is:
```
leftover = (sum + 2) % 2
carry = 1 - (sum + 2) / 2
```
Or
```
leftover = sum & 1
carry = -(sum >> 1)
```

```cpp
// OJ: https://leetcode.com/problems/adding-two-negabinary-numbers/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> addNegabinary(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        for (int i = A.size() - 1, j = B.size() - 1, carry = 0; i >= 0 || j >= 0 || carry;) {
            if (i >= 0) carry += A[i--];
            if (j >= 0) carry += B[j--];
            ans.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

## Solution 2.

Add the two numbers first without any carry over into any array `ans`.

If `ans[i] >= 2`:
* If `ans[i+1] != 0`, we do `ans[i] -= 2` and `ans[i+1]--`
* Otherwise, we do `ans[i] -= 2` and `ans[i+1]++, ans[i+2]++`.

```cpp
// OJ: https://leetcode.com/problems/adding-two-negabinary-numbers/
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
public:
    vector<int> addNegabinary(vector<int>& A, vector<int>& B) {
        int carry = 0;
        vector<int> ans;
        for (int i = A.size() - 1, j = B.size() - 1; i >= 0 || j >= 0;) {
            ans.emplace_back();
            if (i >= 0) ans.back() += A[i--];
            if (j >= 0) ans.back() += B[j--];
        }
        for (int i = 0; i < ans.size(); ++i) {
            if (ans[i] < 2) continue;
            ans[i] -= 2;
            if (i + 1 == ans.size()) ans.emplace_back();
            if (i + 2 == ans.size()) ans.emplace_back();
            if (ans[i + 1]) ans[i + 1]--;
            else ans[i + 1]++, ans[i + 2]++;
        }
        while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```