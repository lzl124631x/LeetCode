# [165. Compare Version Numbers (Medium)](https://leetcode.com/problems/compare-version-numbers/)

<p>Compare two version numbers <em>version1</em> and <em>version2</em>.<br>
If <code><em>version1</em> &gt; <em>version2</em></code> return <code>1;</code>&nbsp;if <code><em>version1</em> &lt; <em>version2</em></code> return <code>-1;</code>otherwise return <code>0</code>.</p>

<p>You may assume that the version strings are non-empty and contain only digits and the <code>.</code> character.</p>
<p>The <code>.</code> character does not represent a decimal point and is used to separate number sequences.</p>
<p>For instance, <code>2.5</code> is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.</p>
<p>You may assume the default revision number for each level of a version number to be <code>0</code>. For example, version number <code>3.4</code> has a revision number of <code>3</code> and <code>4</code> for its first and second level revision number. Its third and fourth level revision number are both <code>0</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> <code><em>version1</em></code> = "0.1", <code><em>version2</em></code> = "1.1"
<strong>Output:</strong> -1</pre>

<p><strong>Example 2:</strong></p>
<pre><strong>Input: </strong><code><em>version1</em></code> = "1.0.1", <code><em>version2</em></code> = "1"
<strong>Output:</strong> 1</pre>

<p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> <code><em>version1</em></code> = "7.5.2.4", <code><em>version2</em></code> = "7.5.3"
<strong>Output:</strong> -1</pre>

<p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> <code><em>version1</em></code> = "1.01", <code><em>version2</em></code> = "1.001"
<strong>Output:</strong> 0
<strong>Explanation:</strong> Ignoring leading zeroes, both “01” and “001" represent the same number “1”</pre>

<p><strong>Example 5:</strong></p>
<pre><strong>Input:</strong> <code><em>version1</em></code> = "1.0", <code><em>version2</em></code> = "1.0.0"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The first version number does not have a third level revision number, which means its third level revision number is default to "0"</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>
<ol>
<li>Version strings are composed of numeric strings separated by dots <code>.</code> and this numeric strings <strong>may</strong> have leading zeroes. </li>
<li>Version strings do not start or end with dots, and they will not be two consecutive dots.</li>
</ol>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

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