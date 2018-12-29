# [893. Groups of Special-Equivalent Strings (Easy)](https://leetcode.com/problems/groups-of-special-equivalent-strings/)

<p>You are given an array <code>A</code> of strings.</p>

<p>Two strings <code>S</code> and <code>T</code> are&nbsp;<em>special-equivalent</em>&nbsp;if after any number of <em>moves</em>, S == T.</p>

<p>A <em>move</em> consists of choosing two indices <code>i</code> and <code>j</code> with <code>i % 2 == j % 2</code>, and swapping <code>S[i]</code> with <code>S[j]</code>.</p>

<p>Now, a <em>group of special-equivalent strings from <code>A</code></em>&nbsp;is a&nbsp;non-empty subset S of <code>A</code>&nbsp;such that any string not in S&nbsp;is not special-equivalent with any string in S.</p>

<p>Return the number of groups of special-equivalent strings from <code>A</code>.</p>

<p>&nbsp;</p>

<ul>
</ul>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">["a","b","c","a","c","c"]</span>
<strong>Output: </strong><span id="example-output-1">3</span>
<span><strong>Explanation</strong>: 3 groups ["a","a"], ["b"], ["c","c","c"]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">["aa","bb","ab","ba"]</span>
<strong>Output: </strong><span id="example-output-2">4</span>
<strong>Explanation</strong>: 4 groups <span id="example-input-2-1">["aa"], ["bb"], ["ab"], ["ba"]</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">["abc","acb","bac","bca","cab","cba"]</span>
<strong>Output: </strong><span id="example-output-3">3</span>
<strong>Explanation</strong>: 3 groups ["abc","cba"], ["acb","bca"], ["bac","cab"]
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong><span id="example-input-4-1">["abcd","cdab","adcb","cbad"]</span>
<strong>Output: </strong><span id="example-output-4">1</span>
<strong>Explanation</strong>: 1 group <span id="example-input-4-1">["abcd","cdab","adcb","cbad"]</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ul>
	<li><code>1 &lt;= A.length &lt;= 1000</code></li>
	<li><code>1 &lt;= A[i].length &lt;= 20</code></li>
	<li>All <code>A[i]</code> have the same length.</li>
	<li>All <code>A[i]</code> consist of only lowercase letters.</li>
</ul>
</div>
</div>
</div>
</div>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/groups-of-special-equivalent-strings/
// Author: github.com/lzl124631x
// Time: O(NWlogW) where N is length of `A`, W is max word length
// Space: O(A) where A is the length of all the contents in array `A`
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> s;
        for (string str : A) {
            string a, b;
            for (int i = 0; i < str.size(); ++i) {
                if (i % 2) a += str[i];
                else b += str[i];
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            s.insert(a + b);
        }
        return s.size();
    }
};
```