# [1807. Evaluate the Bracket Pairs of a String (Medium)](https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/)

<p>You are given a string <code>s</code> that contains some bracket pairs, with each pair containing a <strong>non-empty</strong> key.</p>

<ul>
	<li>For example, in the string <code>"(name)is(age)yearsold"</code>, there are <strong>two</strong> bracket pairs that contain the keys <code>"name"</code> and <code>"age"</code>.</li>
</ul>

<p>You know the values of a wide range of keys. This is represented by a 2D string array <code>knowledge</code> where each <code>knowledge[i] = [key<sub>i</sub>, value<sub>i</sub>]</code> indicates that key <code>key<sub>i</sub></code> has a value of <code>value<sub>i</sub></code>.</p>

<p>You are tasked to evaluate <strong>all</strong> of the bracket pairs. When you evaluate a bracket pair that contains some key <code>key<sub>i</sub></code>, you will:</p>

<ul>
	<li>Replace <code>key<sub>i</sub></code> and the bracket pair with the key's corresponding <code>value<sub>i</sub></code>.</li>
	<li>If you do not know the value of the key, you will replace <code>key<sub>i</sub></code> and the bracket pair with a question mark <code>"?"</code> (without the quotation marks).</li>
</ul>

<p>Each key will appear at most once in your <code>knowledge</code>. There will not be any nested brackets in <code>s</code>.</p>

<p>Return <em>the resulting string after evaluating <strong>all</strong> of the bracket pairs.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]
<strong>Output:</strong> "bobistwoyearsold"
<strong>Explanation:</strong>
The key "name" has a value of "bob", so replace "(name)" with "bob".
The key "age" has a value of "two", so replace "(age)" with "two".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "hi(name)", knowledge = [["a","b"]]
<strong>Output:</strong> "hi?"
<strong>Explanation:</strong> As you do not know the value of the key "name", replace "(name)" with "?".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
<strong>Output:</strong> "yesyesyesaaa"
<strong>Explanation:</strong> The same key can appear multiple times.
The key "a" has a value of "yes", so replace all occurrences of "(a)" with "yes".
Notice that the "a"s not in a bracket pair are not evaluated.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "(a)(b)", knowledge = [["a","b"],["b","a"]]
<strong>Output:</strong> "ba"</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= knowledge.length &lt;= 10<sup>5</sup></code></li>
	<li><code>knowledge[i].length == 2</code></li>
	<li><code>1 &lt;= key<sub>i</sub>.length, value<sub>i</sub>.length &lt;= 10</code></li>
	<li><code>s</code> consists of lowercase English letters and round brackets <code>'('</code> and <code>')'</code>.</li>
	<li>Every open bracket <code>'('</code> in <code>s</code> will have a corresponding close bracket <code>')'</code>.</li>
	<li>The key in each bracket pair of <code>s</code> will be non-empty.</li>
	<li>There will not be any nested bracket pairs in <code>s</code>.</li>
	<li><code>key<sub>i</sub></code> and <code>value<sub>i</sub></code> consist of lowercase English letters.</li>
	<li>Each <code>key<sub>i</sub></code> in <code>knowledge</code> is unique.</li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
// Author: github.com/lzl124631x
// Time: O(S + A)
// Space: O(S + A)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& A) {
        unordered_map<string, string> m;
        for (auto &v : A) {
            m[v[0]] = v[1];
        }
        int N = s.size(), start = -1;
        string ans;
        for (int i = 0; i < N; ++i) {
            if (s[i] == '(') {
                start = i;
            } else if (s[i] == ')') {
                auto key = s.substr(start + 1, i - start - 1);
                if (m.count(key)) ans += m[key];
                else ans += "?";
                start = -1;
            } else if (start == -1) {
                ans += s[i];
            }
        }
        return ans;
    }
};
```