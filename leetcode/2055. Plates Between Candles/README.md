# [2055. Plates Between Candles (Medium)](https://leetcode.com/problems/plates-between-candles/)

<p>There is a long table with a line of plates and candles arranged on top of it. You are given a <strong>0-indexed</strong> string <code>s</code> consisting of characters <code>'*'</code> and <code>'|'</code> only, where a <code>'*'</code> represents a <strong>plate</strong> and a <code>'|'</code> represents a <strong>candle</strong>.</p>

<p>You are also given a <strong>0-indexed</strong> 2D integer array <code>queries</code> where <code>queries[i] = [left<sub>i</sub>, right<sub>i</sub>]</code> denotes the <strong>substring</strong> <code>s[left<sub>i</sub>...right<sub>i</sub>]</code> (<strong>inclusive</strong>). For each query, you need to find the <strong>number</strong> of plates <strong>between candles</strong> that are <strong>in the substring</strong>. A plate is considered <strong>between candles</strong> if there is at least one candle to its left <strong>and</strong> at least one candle to its right <strong>in the substring</strong>.</p>

<ul>
	<li>For example, <code>s = "||**||**|*"</code>, and a query <code>[3, 8]</code> denotes the substring <code>"*||<strong><u>**</u></strong>|"</code>. The number of plates between candles in this substring is <code>2</code>, as each of the two plates has at least one candle <strong>in the substring</strong> to its left <strong>and</strong> right.</li>
</ul>

<p>Return <em>an integer array</em> <code>answer</code> <em>where</em> <code>answer[i]</code> <em>is the answer to the</em> <code>i<sup>th</sup></code> <em>query</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="ex-1" src="https://assets.leetcode.com/uploads/2021/10/04/ex-1.png" style="width: 400px; height: 134px;">
<pre><strong>Input:</strong> s = "**|**|***|", queries = [[2,5],[5,9]]
<strong>Output:</strong> [2,3]
<strong>Explanation:</strong>
- queries[0] has two plates between candles.
- queries[1] has three plates between candles.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="ex-2" src="https://assets.leetcode.com/uploads/2021/10/04/ex-2.png" style="width: 600px; height: 193px;">
<pre><strong>Input:</strong> s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
<strong>Output:</strong> [9,0,0,0,0]
<strong>Explanation:</strong>
- queries[0] has nine plates between candles.
- The other queries have zero plates between candles.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of <code>'*'</code> and <code>'|'</code> characters.</li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= left<sub>i</sub> &lt;= right<sub>i</sub> &lt; s.length</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Binary Search](https://leetcode.com/tag/binary-search/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Find First and Last Position of Element in Sorted Array (Medium)](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
* [Can Make Palindrome from Substring (Medium)](https://leetcode.com/problems/can-make-palindrome-from-substring/)

## Solution 1. Map + Binary Search

```cpp
// OJ: https://leetcode.com/problems/plates-between-candles/
// Author: github.com/lzl124631x
// Time: O((N + Q) * logN)
// Space: O(N)
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& Q) {
        map<int, int> m;
        for (int i = 0, cnt = 0; i <= s.size(); ++i) {
            if (i < s.size() && s[i] == '*') ++cnt;
            else m[i] = cnt;
        }
        vector<int> ans;
        for (auto &q : Q) {
            auto a = m.lower_bound(q[0]);
            auto b = prev(m.upper_bound(q[1]));
            ans.push_back(max(0, b->second - a->second));
        }
        return ans;
    }
};
```