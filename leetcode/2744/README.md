# [2744. Find Maximum Number of String Pairs (Easy)](https://leetcode.com/problems/find-maximum-number-of-string-pairs)

<p>You are given a <strong>0-indexed</strong> array <code>words</code> consisting of <strong>distinct</strong> strings.</p>
<p>The string <code>words[i]</code> can be paired with the string <code>words[j]</code> if:</p>
<ul>
	<li>The string <code>words[i]</code> is equal to the reversed string of <code>words[j]</code>.</li>
	<li><code>0 &lt;= i &lt; j &lt; words.length</code>.</li>
</ul>
<p>Return <em>the <strong>maximum</strong> number of pairs that can be formed from the array </em><code>words</code><em>.</em></p>
<p>Note that&nbsp;each string can belong in&nbsp;<strong>at most one</strong> pair.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> words = ["cd","ac","dc","ca","zz"]
<strong>Output:</strong> 2
<strong>Explanation:</strong> In this example, we can form 2 pair of strings in the following way:
- We pair the 0<sup>th</sup> string with the 2<sup>nd</sup> string, as the reversed string of word[0] is "dc" and is equal to words[2].
- We pair the 1<sup>st</sup> string with the 3<sup>rd</sup> string, as the reversed string of word[1] is "ca" and is equal to words[3].
It can be proven that 2 is the maximum number of pairs that can be formed.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> words = ["ab","ba","cc"]
<strong>Output:</strong> 1
<strong>Explanation:</strong> In this example, we can form 1 pair of strings in the following way:
- We pair the 0<sup>th</sup> string with the 1<sup>st</sup> string, as the reversed string of words[1] is "ab" and is equal to words[0].
It can be proven that 1 is the maximum number of pairs that can be formed.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> words = ["aa","ab"]
<strong>Output:</strong> 0
<strong>Explanation:</strong> In this example, we are unable to form any pair of strings.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>words[i].length == 2</code></li>
	<li><code>words</code>&nbsp;consists of distinct strings.</li>
	<li><code>words[i]</code>&nbsp;contains only lowercase English letters.</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Group Shifted Strings (Medium)](https://leetcode.com/problems/group-shifted-strings/)
* [Palindrome Pairs (Hard)](https://leetcode.com/problems/palindrome-pairs/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-maximum-number-of-string-pairs
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& A) {
        unordered_set<string> s;
        int ans = 0;
        for (auto &w : A) {
            string r(rbegin(w), rend(w));
            if (s.count(r)) ++ans;
            s.insert(w);
        }
        return ans;
    }
};
```