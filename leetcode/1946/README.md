# [1946. Largest Number After Mutating Substring (Medium)](https://leetcode.com/problems/largest-number-after-mutating-substring/)

<p>You are given a string <code>num</code>, which represents a large integer. You are also given a <strong>0-indexed</strong> integer array <code>change</code> of length <code>10</code> that maps each digit <code>0-9</code> to another digit. More formally, digit <code>d</code> maps to digit <code>change[d]</code>.</p>

<p>You may choose to <strong>mutate</strong> any substring of <code>num</code>. To mutate a substring, replace each digit <code>num[i]</code> with the digit it maps to in <code>change</code> (i.e. replace <code>num[i]</code> with <code>change[num[i]]</code>).</p>

<p>Return <em>a string representing the <strong>largest</strong> possible integer after <strong>mutating</strong> (or choosing not to) any substring of </em><code>num</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within the string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = "<u>1</u>32", change = [9,8,5,0,3,6,4,2,6,8]
<strong>Output:</strong> "<u>8</u>32"
<strong>Explanation:</strong> Replace the substring "1":
- 1 maps to change[1] = 8.
Thus, "<u>1</u>32" becomes "<u>8</u>32".
"832" is the largest number that can be created, so return it.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = "<u>021</u>", change = [9,4,3,5,7,2,1,9,0,6]
<strong>Output:</strong> "<u>934</u>"
<strong>Explanation:</strong> Replace the substring "021":
- 0 maps to change[0] = 9.
- 2 maps to change[2] = 3.
- 1 maps to change[1] = 4.
Thus, "<u>021</u>" becomes "<u>934</u>".
"934" is the largest number that can be created, so return it.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num = "5", change = [1,4,7,5,3,2,5,6,9,4]
<strong>Output:</strong> "5"
<strong>Explanation:</strong> "5" is already the largest number that can be created, so return it.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num</code> consists of only digits <code>0-9</code>.</li>
	<li><code>change.length == 10</code></li>
	<li><code>0 &lt;= change[d] &lt;= 9</code></li>
</ul>

## Solution 1. Greedy

**Intuition**: Try to change the digit from left to right. We only greedily make the change if we can make it greater or the same.

**Algorithm**:

One caveat is that, we should skip the leading digits if making changes won't result in greater digit. So we can keep track of a boolean `changed` indicating whether we have made changes.

If we haven't made any changes:
* If the change results in a greater digit, we do it.
* Otherwise, we just skip the digit.

If we have made changes:
* If the change results in a greater or equal digit, we do it.
* Otherwise, we should stop the loop.

```cpp
// OJ: https://leetcode.com/problems/largest-number-after-mutating-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string maximumNumber(string num, vector<int>& A) {
        bool changed = false;
        for (char &c : num) {
            int before = c - '0', after = A[before];
            if (after < before) {
                if (changed) break;
                continue;
            } else if (after == before) {
                continue;
            }
            changed = true;
            c = '0' + after;
        }
        return num;
    }
};
```

Or 

```cpp
// OJ: https://leetcode.com/problems/largest-number-after-mutating-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string maximumNumber(string num, vector<int>& A) {
        bool changed = false;
        for (char &c : num) {
            int before = c - '0', after = A[before];
            if (changed) {
                if (after >= before) c = '0' + after;
                else break;
            } else {
                if (after > before) {
                    c = '0' + after;
                    changed = true;
                } 
            }
        }
        return num;
    }
};
```