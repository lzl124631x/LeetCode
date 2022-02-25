# [165. Compare Version Numbers (Medium)](https://leetcode.com/problems/compare-version-numbers/)

<p>Given two version numbers,&nbsp;<code>version1</code> and <code>version2</code>, compare them.</p>

<ul>
</ul>

<p>Version numbers consist of <strong>one or more revisions</strong> joined by a dot&nbsp;<code>'.'</code>. Each revision&nbsp;consists of <strong>digits</strong>&nbsp;and may contain leading <strong>zeros</strong>. Every revision contains <strong>at least one character</strong>. Revisions are <strong>0-indexed from left to right</strong>, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example&nbsp;<code>2.5.33</code>&nbsp;and&nbsp;<code>0.1</code>&nbsp;are valid version numbers.</p>

<p>To compare version numbers, compare their revisions in <strong>left-to-right order</strong>. Revisions are compared using their&nbsp;<strong>integer value ignoring any leading zeros</strong>. This means that revisions&nbsp;<code>1</code>&nbsp;and&nbsp;<code>001</code>&nbsp;are considered&nbsp;<strong>equal</strong>. If a version number does not specify a revision at an index, then&nbsp;<strong>treat the revision as&nbsp;<code>0</code></strong>. For example, version&nbsp;<code>1.0</code> is less than version&nbsp;<code>1.1</code>&nbsp;because their revision 0s are the same, but their revision 1s are&nbsp;<code>0</code>&nbsp;and&nbsp;<code>1</code>&nbsp;respectively, and&nbsp;<code>0 &lt; 1</code>.</p>

<p><em>Return the following:</em></p>

<ul>
	<li>If <code>version1 &lt; version2</code>, return <code>-1</code>.</li>
	<li>If <code>version1 &gt; version2</code>, return <code>1</code>.</li>
	<li>Otherwise, return <code>0</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> version1 = "1.01", version2 = "1.001"
<strong>Output:</strong> 0
<strong>Explanation:</strong> Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> version1 = "1.0", version2 = "1.0.0"
<strong>Output:</strong> 0
<strong>Explanation:</strong> version1 does not specify revision 2, which means it is treated as "0".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> version1 = "0.1", version2 = "1.1"
<strong>Output:</strong> -1
<strong>Explanation:</strong> version1's revision 0 is "0", while version2's revision 0 is "1". 0 &lt; 1, so version1 &lt; version2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= version1.length, version2.length &lt;= 500</code></li>
	<li><code>version1</code> and <code>version2</code>&nbsp;only contain digits and <code>'.'</code>.</li>
	<li><code>version1</code> and <code>version2</code>&nbsp;<strong>are valid version numbers</strong>.</li>
	<li>All the given revisions in&nbsp;<code>version1</code> and <code>version2</code>&nbsp;can be stored in&nbsp;a&nbsp;<strong>32-bit integer</strong>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Salesforce](https://leetcode.com/company/salesforce)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/compare-version-numbers/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int compareVersion(string a, string b) {
        istringstream sa(a), sb(b);
        while (sa.good() || sb.good()) {
            string x, y;
            getline(sa, x, '.');
            getline(sb, y, '.');
            int v1 = x.size() ? stoi(x) : 0, v2 = y.size() ? stoi(y) : 0;
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
        }
        return 0;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/compare-version-numbers/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int compareVersion(string a, string b) {
        istringstream sa(a), sb(b);
        while (sa.good() || sb.good()) {
            int v1 = 0, v2 = 0;
            sa >> v1;
            sb >> v2;
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
            if (sa.good()) sa.get();
            if (sb.good()) sb.get();
        }
        return 0;
    }
};
```