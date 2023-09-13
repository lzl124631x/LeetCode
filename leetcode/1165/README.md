# [1165. Single-Row Keyboard (Easy)](https://leetcode.com/problems/single-row-keyboard/)

<p>There is a special keyboard with <strong>all keys in a single row</strong>.</p>

<p>Given a string <code>keyboard</code> of length <code>26</code> indicating the layout of the keyboard (indexed from <code>0</code> to <code>25</code>). Initially, your finger is at index <code>0</code>. To type a character, you have to move your finger to the index of the desired character. The time taken to move your finger from index <code>i</code> to index <code>j</code> is <code>|i - j|</code>.</p>

<p>You want to type a string <code>word</code>. Write a function to calculate how much time it takes to type it with one finger.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba"
<strong>Output:</strong> 4
<strong>Explanation: </strong>The index moves from 0 to 2 to write 'c' then to 1 to write 'b' then to 0 again to write 'a'.
Total time = 2 + 1 + 1 = 4. 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode"
<strong>Output:</strong> 73
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>keyboard.length == 26</code></li>
	<li><code>keyboard</code> contains each English lowercase letter exactly once in some order.</li>
	<li><code>1 &lt;= word.length &lt;= 10<sup>4</sup></code></li>
	<li><code>word[i]</code> is an English lowercase letter.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/single-row-keyboard/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> m;
        for (int i = 0; i < 26; ++i) m[keyboard[i]] = i;
        int prev = 0, ans = 0;
        for (char c : word) {
            int i = m[c];
            ans += abs(prev - i);
            prev = i;
        }
        return ans;
    }
};
```