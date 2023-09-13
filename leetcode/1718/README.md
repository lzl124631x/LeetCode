# [1718. Construct the Lexicographically Largest Valid Sequence (Medium)](https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/)

<p>Given an integer <code>n</code>, find a sequence that satisfies all of the following:</p>

<ul>
	<li>The integer <code>1</code> occurs once in the sequence.</li>
	<li>Each integer between <code>2</code> and <code>n</code> occurs twice in the sequence.</li>
	<li>For every integer <code>i</code> between <code>2</code> and <code>n</code>, the <strong>distance</strong> between the two occurrences of <code>i</code> is exactly <code>i</code>.</li>
</ul>

<p>The <strong>distance</strong> between two numbers on the sequence, <code>a[i]</code> and <code>a[j]</code>, is the absolute difference of their indices, <code>|j - i|</code>.</p>

<p>Return <em>the <strong>lexicographically largest</strong> sequence</em><em>. It is guaranteed that under the given constraints, there is always a solution. </em></p>

<p>A sequence <code>a</code> is lexicographically larger than a sequence <code>b</code> (of the same length) if in the first position where <code>a</code> and <code>b</code> differ, sequence <code>a</code> has a number greater than the corresponding number in <code>b</code>. For example, <code>[0,1,9,0]</code> is lexicographically larger than <code>[0,1,5,6]</code> because the first position they differ is at the third number, and <code>9</code> is greater than <code>5</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> [3,1,2,3,2]
<strong>Explanation:</strong> [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 5
<strong>Output:</strong> [5,3,1,4,3,5,2,4,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/), [Recursion](https://leetcode.com/tag/recursion/)

## Solution 1. Backtracking

At first I thought it's a greedy / pattern-finding problem. But the pattern I found failed at `n = 7`. So I had to try DFS + Backtracking.

For indexes `0 <= i < ans.size()`, we try the numbers available in descending order. Once we successfully fill all the indexes, we return `ans`.

```cpp
// OJ: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N)
class Solution {
    vector<int> used;
    bool dfs(vector<int> &ans, int i) {
        if (i == ans.size()) return true; // filled all the numbers, found the answer
        if (ans[i]) return dfs(ans, i + 1); // this index is already filled, continue to fill the next index.
        for (int j = used.size() - 1; j > 0; --j) { // try each number in decending order from n to 1.
            if (used[j]) continue; // j is already used, skip
            if (j != 1 && (i + j >= ans.size() || ans[i + j])) continue; // we can't fill `ans[i + j]` either because `i + j` is out of bound or `ans[i + j]` is already filled. Skip.
            used[j] = 1; // mark number `j` as used.
            ans[i] = j; // fill `ans[j]` and `ans[i + j]` (if needed) with `j`.
            if (j != 1) ans[i + j] = j;
            if (dfs(ans, i + 1)) return true;
            ans[i] = 0; // this filling is invalid, backtrack and try the next number.
            if (j != 1) ans[i + j] = 0;
            used[j] = 0;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1);
        used.assign(n + 1, 0); // numbers 1 ~ n are unused initially
        dfs(ans, 0); // try filling numbers from index 0.
        return ans;
    }
};
```

Or use lambda function for DFS.

```cpp
// OJ: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N)
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1), used(n + 1, 0);
        function<bool(int i)> dfs = [&](int i) -> bool {
            if (i == ans.size()) return true;
            if (ans[i]) return dfs(i + 1);
            for (int j = n; j >= 1; --j) {
                if (used[j] || (j != 1 && (i + j >= ans.size() || ans[i + j]))) continue;
                used[j] = 1;
                ans[i] = j;
                if (j != 1) ans[i + j] = j;
                if (dfs(i + 1)) return true;
                ans[i] = used[j] = 0;
                if (j != 1) ans[i + j] = 0;
            }
            return false;
        };
        dfs(0);
        return ans;
    }
};
```