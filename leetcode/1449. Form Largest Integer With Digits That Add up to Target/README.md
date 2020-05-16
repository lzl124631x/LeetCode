# [1449. Form Largest Integer With Digits That Add up to Target (Hard)](https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/)

<p>Given an array of integers <code>cost</code> and an integer <code>target</code>. Return the <strong>maximum</strong> integer you can paint&nbsp;under the following rules:</p>

<ul>
	<li>The cost of painting a&nbsp;digit (i+1) is given by&nbsp;<code>cost[i]</code>&nbsp;(0 indexed).</li>
	<li>The total cost used must&nbsp;be equal to <code>target</code>.</li>
	<li>Integer does not have digits 0.</li>
</ul>

<p>Since the answer may be too large, return it as string.</p>

<p>If there is no way to paint any integer given the condition, return "0".</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> cost = [4,3,2,5,6,7,2,5,5], target = 9
<strong>Output:</strong> "7772"
<strong>Explanation: </strong> The cost to paint the digit '7' is 2, and the digit '2' is 3. Then cost("7772") = 2*3+ 3*1 = 9. You could also paint "997", but "7772" is the largest number.
<strong>Digit    cost</strong>
  1  -&gt;   4
  2  -&gt;   3
  3  -&gt;   2
  4  -&gt;   5
  5  -&gt;   6
  6  -&gt;   7
  7  -&gt;   2
  8  -&gt;   5
  9  -&gt;   5
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> cost = [7,6,5,5,5,6,8,7,8], target = 12
<strong>Output:</strong> "85"
<strong>Explanation:</strong> The cost to paint the digit '8' is 7, and the digit '5' is 5. Then cost("85") = 7 + 5 = 12.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> cost = [2,4,6,2,4,6,4,4,4], target = 5
<strong>Output:</strong> "0"
<strong>Explanation:</strong> It's not possible to paint any integer with total cost equal to target.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> cost = [6,10,15,40,40,40,40,40,40], target = 47
<strong>Output:</strong> "32211"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>cost.length == 9</code></li>
	<li><code>1 &lt;= cost[i] &lt;= 5000</code></li>
	<li><code>1 &lt;= target &lt;= 5000</code></li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

This is a typical knapsack problem.

Let `dp[i + 1][c]` be the maximum string we can form using digits from `1` to `i + 1` and exactly `c` cost.

For `dp[i + 1][c]`, we have the following options:
* Don't use digit `i + 1`. we get `dp[i][c]`.
* Use digit `i + 1` once, we get `string(1, '1' + i) + dp[i][c - A[i]]`
* Use digit `i + 1` twice, we get `string(2, '1' + i) + dp[i][c - 2 * A[i]]`.
* ...
* Use digit `i + 1` `k` times, we get `string(k, '1' + i) + dp[i][c - k * A[i]]`, where `k` is the maximum number satisfying `c - k * A[i] >= 0`.

So we have:
```
dp[i + 1][c] = max(
                    dp[i][c],
                    string(1, '1'+i) + dp[i][c - A[i]],
                    string(2, '1'+i) + dp[i][c - 2 * A[i]],
                    ...
                    string(k, '1'+i) + dp[i][c - k * A[i]]
)
dp[i][0] = ""
```

To get `dp[i + 1][c]`, the time complexity above is `O(k)`.

We can optimize it using `dp[i + 1][c - A[i]]` since:

```
dp[i + 1][c - A[i]] = max(
                    dp[i][c - A[i]],
                    string(1, '1'+i) + dp[i][c - 2 * A[i]],
                    ...
                    string(k-1, '1'+i) + dp[i][c - k * A[i]]
)
```

So
```
dp[i + 1][c] = max(
                dp[i][c],
                string(1, '1'+i) + dp[i + 1][c - A[i]]
)
```

Now we reduce the time complexity of getting `dp[i + 1][c]` to `O(1)`.

Since `N` is just `9`, so both the time and space complexities are `O(T)`.

Note that in implementation, we initialize `dp` in this way:
* `dp[i][0] = ""`. When `c` is `0`, `""` is a valid string that we can get out of it.
* `dp[i][c] = "0"` where `c != 0`. We use `"0"` as a invalid string because we can't use `'0'` in the integer.

So `dp[i + 1][c - A[i]] == "0"` means that we can't form a valid string using digits from `1` to `i+1` with cost `c - A[i]`, and thus we can't add digit `i+1` in front of `dp[i + 1][c - A[i]]`.

```cpp
// OJ: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
// Author: github.com/lzl124631x
// Time: O(T)
// Space: O(T)
class Solution {
    inline bool isGreaterThan(string &a, string &b) {
        return a.size() != b.size() ? a.size() > b.size() : a > b;
    }
public:
    string largestNumber(vector<int>& A, int T) {
        int N = A.size();
        vector<vector<string>> dp(N + 1, vector<string>(T + 1, "0"));
        for (int i = 0; i <= N; ++i) dp[i][0] = "";
        for (int i = 0; i < N; ++i) {
            for (int c = 1; c <= T; ++c) {
                dp[i + 1][c] = dp[i][c];
                if (c < A[i] || dp[i + 1][c - A[i]] == "0") continue;
                auto s = string(1, '1' + i) + dp[i + 1][c - A[i]];
                if (isGreaterThan(s, dp[i + 1][c])) dp[i + 1][c] = s;
            }
        }
        return dp[N][T];
    }
};
```

## Solution 2. DP

Since `dp[i + 1][c]` is only dependent on `dp[i][c]` and `dp[i + 1][c - A[i]]`, we can further reduce the size of the `dp` array from `N * T` to `1 * T`.

```cpp
// OJ: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target
// Author: github.com/lzl124631x
// Time: O(T)
// Space: O(T)
class Solution {
    inline bool isGreaterThan(string &a, string &b) {
        return a.size() != b.size() ? a.size() > b.size() : a > b;
    }
public:
    string largestNumber(vector<int>& A, int T) {
        int N = A.size();
        vector<string> dp(T + 1, "0");
        dp[0] = "";
        for (int i = 0; i < N; ++i) {
            for (int c = 1; c <= T; ++c) {
                if (c < A[i] || dp[c - A[i]] == "0") continue;
                auto s = string(1, '1' + i) + dp[c - A[i]];
                if (isGreaterThan(s, dp[c])) dp[c] = s;
            }
        }
        return dp[T];
    }
};
```