# [1647. Minimum Deletions to Make Character Frequencies Unique (Medium)](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)

<p>A string <code>s</code> is called <strong>good</strong> if there are no two different characters in <code>s</code> that have the same <strong>frequency</strong>.</p>

<p>Given a string <code>s</code>, return<em> the <strong>minimum</strong> number of characters you need to delete to make </em><code>s</code><em> <strong>good</strong>.</em></p>

<p>The <strong>frequency</strong> of a character in a string is the number of times it appears in the string. For example, in the string <code>"aab"</code>, the <strong>frequency</strong> of <code>'a'</code> is <code>2</code>, while the <strong>frequency</strong> of <code>'b'</code> is <code>1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aab"
<strong>Output:</strong> 0
<strong>Explanation:</strong> <code>s</code> is already good.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aaabbbcc"
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "ceabaacb"
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;contains only lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Minimum Deletions to Make Array Beautiful (Medium)](https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/)
* [Removing Minimum and Maximum From Array (Medium)](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/)

## Solution 1. Greedy

Count the frequencies and sort them in descending order. Then the problem becomes finding the minimum substraction that turns this frequence sequence to a strictly decreasing sequence. We can do it greedily. 

```cpp
// OJ: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minDeletions(string s) {
        int cnt[26] = {}, ans = 0;
        for (char c : s) cnt[c - 'a']++;
        sort(begin(cnt), end(cnt), greater<>());
        for (int i = 1; i < 26 && cnt[i]; ++i) {
            int n = max(0, min(cnt[i - 1] - 1, cnt[i])); // the new cnt[i] value should be at least zero, and no greater than `cnt[i-1]-1` and `cnt[i]` itself.
            ans += cnt[i] - n;
            cnt[i] = n;
        }
        return ans;
    }
};
```