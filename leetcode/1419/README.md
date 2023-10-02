# [1419. Minimum Number of Frogs Croaking (Medium)](https://leetcode.com/problems/minimum-number-of-frogs-croaking/)

<p>Given the string <code>croakOfFrogs</code>, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple “croak” are mixed.&nbsp;<em>Return the minimum number of </em>different<em> frogs to finish all the croak in the given string.</em></p>

<p>A valid "croak"&nbsp;means a frog is printing 5 letters ‘c’, ’r’, ’o’, ’a’, ’k’&nbsp;<strong>sequentially</strong>.&nbsp;The frogs have to print all five letters to finish a croak.&nbsp;If the given string is not a combination of valid&nbsp;"croak"&nbsp;return -1.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> croakOfFrogs = "croakcroak"
<strong>Output:</strong> 1 
<strong>Explanation:</strong> One frog yelling "croak<strong>"</strong> twice.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> croakOfFrogs = "crcoakroak"
<strong>Output:</strong> 2 
<strong>Explanation:</strong> The minimum number of frogs is two.&nbsp;
The first frog could yell "<strong>cr</strong>c<strong>oak</strong>roak".
The second frog could yell later "cr<strong>c</strong>oak<strong>roak</strong>".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> croakOfFrogs = "croakcrook"
<strong>Output:</strong> -1
<strong>Explanation:</strong> The given string is an invalid combination of "croak<strong>"</strong> from different frogs.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> croakOfFrogs = "croakcroa"
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;croakOfFrogs.length &lt;= 10^5</code></li>
	<li>All characters in the string are: <code>'c'</code>, <code>'r'</code>, <code>'o'</code>, <code>'a'</code> or <code>'k'</code>.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-frogs-croaking/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minNumberOfFrogs(string s) {
        string t = "croak";
        vector<int> cnt(5);
        int ans = 0, cur = 0;
        for (char c : s) {
            int n = t.find(c);
            if (n == string::npos) return -1;
            if (n != 0 && --cnt[n - 1] < 0) return -1;
            ++cnt[n];
            if (n == 0) ++cur;
            else if (n == 4) --cur;
            ans = max(ans, cur);
        }
        return cur ? -1 : ans;
    }
};
```