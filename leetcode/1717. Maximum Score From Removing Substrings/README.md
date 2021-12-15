# [1717. Maximum Score From Removing Substrings (Medium)](https://leetcode.com/problems/maximum-score-from-removing-substrings/)

<p>You are given a string <code>s</code> and two integers <code>x</code> and <code>y</code>. You can perform two types of operations any number of times.</p>

<ul>
	<li>Remove substring <code>"ab"</code> and gain <code>x</code> points.

	<ul>
		<li>For example, when removing <code>"ab"</code> from <code>"c<u>ab</u>xbae"</code> it becomes <code>"cxbae"</code>.</li>
	</ul>
	</li>
	<li>Remove substring <code>"ba"</code> and gain <code>y</code> points.
	<ul>
		<li>For example, when removing <code>"ba"</code> from <code>"cabx<u>ba</u>e"</code> it becomes <code>"cabxe"</code>.</li>
	</ul>
	</li>
</ul>

<p>Return <em>the maximum points you can gain after applying the above operations on</em> <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "cdbcbbaaabab", x = 4, y = 5
<strong>Output:</strong> 19
<strong>Explanation:</strong>
- Remove the "ba" underlined in "cdbcbbaaa<u>ba</u>b". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaa<u>ab</u>". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcb<u>ba</u>a". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbc<u>ba</u>". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aabbaaxybbaabb", x = 5, y = 4
<strong>Output:</strong> 20
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x, y &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Greedy

We greedily remove the pattern with greater points, then remove the other pattern.

For removing the pattern string iteratively, we can reuse [the solution](https://github.com/lzl124631x/LeetCode/blob/master/leetcode/1003.%20Check%20If%20Word%20Is%20Valid%20After%20Substitutions/README.md) to [1003. Check If Word Is Valid After Substitutions (Medium)](https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/)

```cpp
// OJ: https://leetcode.com/problems/maximum-score-from-removing-substrings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int remove(string &s, string r, int x) {
        int i = 0, ans = 0; // `i` is write pointer, `j` is read pointer. 
        for (int j = 0; j < s.size(); ++j) {
            s[i++] = s[j];
            if (i > 1 && s[i - 2] == r[0] && s[i - 1] == r[1]) i -= 2, ans += x; // We keep removing pattern string `r` when `r` shows up in the end of written part.
        }
        s.resize(i);
        return ans;
    }
public:
    int maximumGain(string s, int x, int y) {
        string a = "ab", b = "ba";
        if (x < y) swap(a, b), swap(x, y);
        return remove(s, a, x) + remove(s, b, y);
    }
};
```

Proof by contradiction:

Assume `score(ab) > score(ba)` but removing `ba` first is optimal.

This could only happen when the removal of a single `ab` prevents 2 `ba` removals, and `score(remove ba first) > score(remove ab first)` i.e. `score(ba) * 2 > score(ab)`.

Only `b(ab)a` satisfies this requirement. But after removing `ab` we can remove one `ba`, so we get `score(ab) + score(ba)` which is greater than `score(ba) * 2`.

Thus removing `ba` first is not optimal, the assumption is wrong.

## Discuss

https://leetcode.com/problems/maximum-score-from-removing-substrings/discuss/1009028/C%2B%2B-Greedy-O(N)-Time-O(1)-Space