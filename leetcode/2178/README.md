# [2178. Maximum Split of Positive Even Integers (Medium)](https://leetcode.com/problems/maximum-split-of-positive-even-integers/)

<p>You are given an integer <code>finalSum</code>. Split it into a sum of a <strong>maximum</strong> number of <strong>unique</strong> positive even integers.</p>

<ul>
	<li>For example, given <code>finalSum = 12</code>, the following splits are <strong>valid</strong> (unique positive even integers summing up to <code>finalSum</code>): <code>(2 + 10)</code>, <code>(2 + 4 + 6)</code>, and <code>(4 + 8)</code>. Among them, <code>(2 + 4 + 6)</code> contains the maximum number of integers. Note that <code>finalSum</code> cannot be split into <code>(2 + 2 + 4 + 4)</code> as all the numbers should be unique.</li>
</ul>

<p>Return <em>a list of integers that represent a valid split containing a <strong>maximum</strong> number of integers</em>. If no valid split exists for <code>finalSum</code>, return <em>an <strong>empty</strong> list</em>. You may return the integers in <strong>any</strong> order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> finalSum = 12
<strong>Output:</strong> [2,4,6]
<strong>Explanation:</strong> The following are some valid splits: <code>(2 + 10)</code>, <code>(2 + 4 + 6)</code>, and <code>(4 + 8)</code>.
(2 + 4 + 6) has the maximum number of integers, which is 3. Thus, we return [2,4,6].
Note that [2,6,4], [6,2,4], etc. are also accepted.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> finalSum = 7
<strong>Output:</strong> []
<strong>Explanation:</strong> There are no valid splits for the given finalSum.
Thus, we return an empty array.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> finalSum = 28
<strong>Output:</strong> [6,8,2,12]
<strong>Explanation:</strong> The following are some valid splits: <code>(2 + 26)</code>, <code>(6 + 8 + 2 + 12)</code>, and <code>(4 + 24)</code>. 
<code>(6 + 8 + 2 + 12)</code> has the maximum number of integers, which is 4. Thus, we return [6,8,2,12].
Note that [10,2,4,12], [6,2,4,16], etc. are also accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= finalSum &lt;= 10<sup>10</sup></code></li>
</ul>

## Solution 1. Backtracking

If `finalSum` is odd, return empty array.

Otherwise, we keep trying subtracting `2, 4, 6, 8, ...` from `finalSum` via backtracking.

```cpp
// OJ: https://leetcode.com/problems/maximum-split-of-positive-even-integers/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(sqrt(N))
class Solution {
public:
    vector<long long> maximumEvenSplit(long long s) {
        if (s % 2) return {};
        vector<long long> ans;
        function<bool(long, long)>dfs = [&](long i, long target) {
            if (target == 0) return true;
            if (target < i) return false;
            ans.push_back(i);
            if (dfs(i + 2, target - i)) return true; // use `i`
            ans.pop_back();
            return dfs(i + 2, target); // skip `i`
        };
        dfs(2, s);
        return ans;
    }
};
```


## Solution 2. Greedy

In solution 1, in fact we only backtrack at most once.

We can keep trying subtracting `2, 4, 6, 8, ...` from `finalSum`. We stop the loop when subtracting the current number `i` is invalid -- `s - i < i + 2` (the reminder after the subtraction is less than the next even number). And we push the reminder into the answer.

```cpp
// OJ: https://leetcode.com/problems/maximum-split-of-positive-even-integers/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    vector<long long> maximumEvenSplit(long long s) {
        if (s % 2) return {};
        vector<long long> ans;
        for (int i = 2; s - i >= i + 2; i += 2) {
            ans.push_back(i);
            s -= i;
        }
        ans.push_back(s);
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/maximum-split-of-positive-even-integers/discuss/1783586