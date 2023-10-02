# [2268. Minimum Number of Keypresses (Medium)](https://leetcode.com/problems/minimum-number-of-keypresses)

<p>You have a keypad with <code>9</code> buttons, numbered from <code>1</code> to <code>9</code>, each mapped to lowercase English letters. You can choose which characters each button is matched to as long as:</p>
<ul>
	<li>All 26 lowercase English letters are mapped to.</li>
	<li>Each character is mapped to by <strong>exactly</strong> <code>1</code> button.</li>
	<li>Each button maps to <strong>at most</strong> <code>3</code> characters.</li>
</ul>
<p>To type the first character matched to a button, you press the button once. To type the second character, you press the button twice, and so on.</p>
<p>Given a string <code>s</code>, return <em>the <strong>minimum</strong> number of keypresses needed to type </em><code>s</code><em> using your keypad.</em></p>
<p><strong>Note</strong> that the characters mapped to by each button, and the order they are mapped in cannot be changed.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/05/05/image-20220505184346-1.png" style="width: 300px; height: 293px;">
<pre><strong>Input:</strong> s = "apple"
<strong>Output:</strong> 5
<strong>Explanation:</strong> One optimal way to setup your keypad is shown above.
Type 'a' by pressing button 1 once.
Type 'p' by pressing button 6 once.
Type 'p' by pressing button 6 once.
Type 'l' by pressing button 5 once.
Type 'e' by pressing button 3 once.
A total of 5 button presses are needed, so return 5.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/05/05/image-20220505203823-1.png" style="width: 300px; height: 288px;">
<pre><strong>Input:</strong> s = "abcdefghijkl"
<strong>Output:</strong> 15
<strong>Explanation:</strong> One optimal way to setup your keypad is shown above.
The letters 'a' to 'i' can each be typed by pressing a button once.
Type 'j' by pressing button 1 twice.
Type 'k' by pressing button 2 twice.
Type 'l' by pressing button 3 twice.
A total of 15 button presses are needed, so return 15.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/), [Counting](https://leetcode.com/tag/counting/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-keypresses
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minimumKeypresses(string s) {
        int cnt[26] = {}, ans = 0;
        for (char c : s) ++cnt[c - 'a'];
        sort(begin(cnt), end(cnt), greater<>());
        for (int i = 0; i < 26 && cnt[i]; ++i) {
            ans += (i + 9) / 9 * cnt[i];
        }
        return ans;
    }
};
```