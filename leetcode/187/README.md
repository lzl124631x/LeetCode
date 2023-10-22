# [187. Repeated DNA Sequences (Medium)](https://leetcode.com/problems/repeated-dna-sequences)

<p>The <strong>DNA sequence</strong> is composed of a series of nucleotides abbreviated as <code>&#39;A&#39;</code>, <code>&#39;C&#39;</code>, <code>&#39;G&#39;</code>, and <code>&#39;T&#39;</code>.</p>

<ul>
	<li>For example, <code>&quot;ACGAATTCCG&quot;</code> is a <strong>DNA sequence</strong>.</li>
</ul>

<p>When studying <strong>DNA</strong>, it is useful to identify repeated sequences within the DNA.</p>

<p>Given a string <code>s</code> that represents a <strong>DNA sequence</strong>, return all the <strong><code>10</code>-letter-long</strong> sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
<strong>Output:</strong> ["AAAAACCCCC","CCCCCAAAAA"]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "AAAAAAAAAAAAA"
<strong>Output:</strong> ["AAAAAAAAAA"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>&#39;A&#39;</code>, <code>&#39;C&#39;</code>, <code>&#39;G&#39;</code>, or <code>&#39;T&#39;</code>.</li>
</ul>


**Companies**:
[LinkedIn](https://leetcode.com/company/linkedin), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table), [String](https://leetcode.com/tag/string), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Sliding Window](https://leetcode.com/tag/sliding-window), [Rolling Hash](https://leetcode.com/tag/rolling-hash), [Hash Function](https://leetcode.com/tag/hash-function)

## Solution 1. Rabin Karp

Note that this implementation is unsafe because it doesn't check whether two strings are the same when their hashes are the same.

```cpp
// OJ: https://leetcode.com/problems/repeated-dna-sequences
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(4^10)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<unsigned long long, int> cnt;
        vector<string> ans;
        unsigned long long h = 0, p = 1, d = 1099511628211;
        for (int i = 0, N = s.size(); i < N; ++i) {
            if (i < 10) p *= d;
            h = h * d + s[i];
            if (i >= 10) h -= p * s[i - 10];
            if (++cnt[h] == 2) ans.push_back(s.substr(i - 9, 10));
        }
        return ans;
    }
};
```

## Solution 2. Rabin Karp

```cpp
// OJ: https://leetcode.com/problems/repeated-dna-sequences
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return {};
        unordered_map<int, unordered_set<string>> m;
        unordered_set<string> st;
        unsigned h = 0, p = 1, prime = 16777619;
        for (int i = 0; i < 10; ++i) {
            h = h * prime + s[i];
            p *= prime;
        }
        m[h].insert(s.substr(0, 10));
        for (int i = 10; i < s.size(); ) {
            h = h * prime + s[i] - p * s[i - 10];
            ++i;
            auto sub = s.substr(i - 10, 10);
            if (m[h].count(sub)) st.insert(sub);
            else m[h].insert(sub);
        }
        vector<string> ans(begin(st), end(st));
        return ans;
    }
};
```