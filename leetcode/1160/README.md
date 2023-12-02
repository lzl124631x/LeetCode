# [1160. Find Words That Can Be Formed by Characters (Easy)](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters)

<p>You are given an array of strings <code>words</code> and a string <code>chars</code>.</p>

<p>A string is <strong>good</strong> if it can be formed by characters from chars (each character can only be used once).</p>

<p>Return <em>the sum of lengths of all good strings in words</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;cat&quot;,&quot;bt&quot;,&quot;hat&quot;,&quot;tree&quot;], chars = &quot;atach&quot;
<strong>Output:</strong> 6
<strong>Explanation:</strong> The strings that can be formed are &quot;cat&quot; and &quot;hat&quot; so the answer is 3 + 3 = 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;hello&quot;,&quot;world&quot;,&quot;leetcode&quot;], chars = &quot;welldonehoneyr&quot;
<strong>Output:</strong> 10
<strong>Explanation:</strong> The strings that can be formed are &quot;hello&quot; and &quot;world&quot; so the answer is 5 + 5 = 10.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length, chars.length &lt;= 100</code></li>
	<li><code>words[i]</code> and <code>chars</code> consist of lowercase English letters.</li>
</ul>


**Companies**:
[Karat](https://leetcode.com/company/karat), [Indeed](https://leetcode.com/company/indeed), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [String](https://leetcode.com/tag/string)

**Similar Questions**:
* [Rearrange Characters to Make Target String (Easy)](https://leetcode.com/problems/rearrange-characters-to-make-target-string)

**Hints**:
* Solve the problem for each string in <code>words</code> independently.
* Now try to think in frequency of letters.
* Count how many times each character occurs in string <code>chars</code>.
* To form a string using characters from <code>chars</code>, the frequency of each character in <code>chars</code> must be greater than or equal the frequency of that character in the string to be formed.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
// Author: github.com/lzl124631x
// Time: O(N) where N is the length of all the contents in `words` and `chars`
// Space: O(1)
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26] = {0}, ans = 0;
        for (char c : chars) cnt[c - 'a']++;
        for (auto w : words) {
            int c[26] = {0};
            bool good = true;
            for (char ch : w) {
                if (++c[ch - 'a'] <= cnt[ch - 'a']) continue;
                good = false;
                break;
            }
            if (good) ans += w.size();
        }
        return ans;
    }
};
```