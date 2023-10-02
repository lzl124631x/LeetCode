# [2716. Minimize String Length (Easy)](https://leetcode.com/problems/minimize-string-length)

<p>Given a <strong>0-indexed</strong> string <code>s</code>, repeatedly perform the following operation <strong>any</strong> number of times:</p>
<ul>
	<li>Choose an index <code>i</code> in the string, and let <code>c</code> be the character in position <code>i</code>. <strong>Delete</strong> the <strong>closest occurrence</strong> of <code>c</code> to the <strong>left</strong> of <code>i</code> (if any) and the <strong>closest occurrence</strong> of <code>c</code> to the <strong>right</strong> of <code>i</code> (if any).</li>
</ul>
<p>Your task is to <strong>minimize</strong> the length of <code>s</code> by performing the above operation any number of times.</p>
<p>Return <em>an integer denoting the length of the <strong>minimized</strong> string.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "aaabc"
<strong>Output:</strong> 3
<strong>Explanation:</strong> In this example, s is "aaabc". We can start by selecting the character 'a' at index 1. We then remove the closest 'a' to the left of index 1, which is at index 0, and the closest 'a' to the right of index 1, which is at index 2. After this operation, the string becomes "abc". Any further operation we perform on the string will leave it unchanged. Therefore, the length of the minimized string is 3.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "cbbd"
<strong>Output:</strong> 3
<strong>Explanation:</strong> For this we can start with character 'b' at index 1. There is no occurrence of 'b' to the left of index 1, but there is one to the right at index 2, so we delete the 'b' at index 2. The string becomes "cbd" and further operations will leave it unchanged. Hence, the minimized length is 3.&nbsp;
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "dddaaa"
<strong>Output:</strong> 2
<strong>Explanation:</strong> For this, we can start with the character 'd' at index 1. The closest occurrence of a 'd' to its left is at index 0, and the closest occurrence of a 'd' to its right is at index 2. We delete both index 0 and 2, so the string becomes "daaa". In the new string, we can select the character 'a' at index 2. The closest occurrence of an 'a' to its left is at index 1, and the closest occurrence of an 'a' to its right is at index 3. We delete both of them, and the string becomes "da". We cannot minimize this further, so the minimized length is 2.
</pre>
<div class="notranslate" style="all: initial;">&nbsp;</div>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> contains only lowercase English letters</li>
</ul>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Remove All Adjacent Duplicates In String (Easy)](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)
* [Remove All Adjacent Duplicates in String II (Medium)](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimize-string-length
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimizedStringLength(string s) {
        int cnt[26] = {}, ans = 0;
        for (char c : s) ans += cnt[c - 'a']++ == 0;
        return ans;
    }
};
```