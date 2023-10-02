# [1002. Find Common Characters (Easy)](https://leetcode.com/problems/find-common-characters/)

<p>Given an array&nbsp;<code>A</code> of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list <strong>(including duplicates)</strong>.&nbsp;&nbsp;For example, if a character occurs 3 times&nbsp;in all strings but not 4 times, you need to include that character three times&nbsp;in the final answer.</p>

<p>You may return the answer in any order.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">["bella","label","roller"]</span>
<strong>Output: </strong><span id="example-output-1">["e","l","l"]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">["cool","lock","cook"]</span>
<strong>Output: </strong><span id="example-output-2">["c","o"]</span>
</pre>

<p>&nbsp;</p>

<p><strong><span>Note:</span></strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 100</code></li>
	<li><code>1 &lt;= A[i].length &lt;= 100</code></li>
	<li><code>A[i][j]</code> is a lowercase letter</li>
</ol>
</div>
</div>

**Companies**:  
[TripAdvisor](https://leetcode.com/company/tripadvisor)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Intersection of Two Arrays II (Easy)](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-common-characters/
// Author: github.com/lzl124631x
// Time: O(C) where C is the size of all the contents in A
// Space: O(1)
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> overlap(26, INT_MAX);
        for (string s : A) {
            vector<int> cnt(26, 0);
            for (char c : s) cnt[c - 'a']++;
            for (int i = 0; i < 26; ++i) overlap[i] = min(overlap[i], cnt[i]);
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            while (overlap[i]--) ans.push_back(string(1, 'a' + i));
        }
        return ans;
    }
};
```