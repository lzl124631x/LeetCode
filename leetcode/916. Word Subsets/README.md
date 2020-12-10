# [916. Word Subsets (Medium)](https://leetcode.com/problems/word-subsets/)

<p>We are given two arrays <code>A</code> and <code>B</code> of words.&nbsp; Each word is a string of lowercase letters.</p>

<p>Now, say that&nbsp;word <code>b</code> is a subset of word <code>a</code><strong>&nbsp;</strong>if every letter in <code>b</code> occurs in <code>a</code>, <strong>including multiplicity</strong>.&nbsp; For example, <code>"wrr"</code> is a subset of <code>"warrior"</code>, but is not a subset of <code>"world"</code>.</p>

<p>Now say a word <code>a</code> from <code>A</code> is <em>universal</em> if for every <code>b</code> in <code>B</code>, <code>b</code>&nbsp;is a subset of <code>a</code>.&nbsp;</p>

<p>Return a list of all universal words in <code>A</code>.&nbsp; You can return the words in any order.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-1-1">["amazon","apple","facebook","google","leetcode"]</span>, B = <span id="example-input-1-2">["e","o"]</span>
<strong>Output: </strong><span id="example-output-1">["facebook","google","leetcode"]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-2-1">["amazon","apple","facebook","google","leetcode"]</span>, B = <span id="example-input-2-2">["l","e"]</span>
<strong>Output: </strong><span id="example-output-2">["apple","google","leetcode"]</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-3-1">["amazon","apple","facebook","google","leetcode"]</span>, B = <span id="example-input-3-2">["e","oo"]</span>
<strong>Output: </strong><span id="example-output-3">["facebook","google"]</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-4-1">["amazon","apple","facebook","google","leetcode"]</span>, B = <span id="example-input-4-2">["lo","eo"]</span>
<strong>Output: </strong><span id="example-output-4">["google","leetcode"]</span>
</pre>

<div>
<p><strong>Example 5:</strong></p>

<pre><strong>Input: </strong>A = <span id="example-input-5-1">["amazon","apple","facebook","google","leetcode"]</span>, B = <span id="example-input-5-2">["ec","oc","ceo"]</span>
<strong>Output: </strong><span id="example-output-5">["facebook","leetcode"]</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= A.length, B.length &lt;= 10000</code></li>
	<li><code>1 &lt;= A[i].length, B[i].length&nbsp;&lt;= 10</code></li>
	<li><code>A[i]</code> and <code>B[i]</code> consist only of lowercase letters.</li>
	<li>All words in <code>A[i]</code> are unique: there isn't <code>i != j</code> with <code>A[i] == A[j]</code>.</li>
</ol>
</div>
</div>
</div>
</div>
</div>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/word-subsets/
// Author: github.com/lzl124631x
// Time: O((A + B) * N) where N is the maximum length of string
// Space: O(1)
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int N = A.size(), target[26] = {}, j = 0;
        for (auto &b : B) {
            int cnt[26] = {};
            for (char c : b) cnt[c - 'a']++;
            for (int i = 0; i < 26; ++i) target[i] = max(target[i], cnt[i]);
        }
        for (int i = 0; i < N; ++i) {
            int cnt[26] = {};
            for (char c : A[i]) cnt[c - 'a']++;
            bool valid = true;
            for (int k = 0; k < 26 && valid; ++k) valid = target[k] <= cnt[k];
            if (valid) A[j++] = A[i];
        }
        A.resize(j);
        return A;
    }
};
```