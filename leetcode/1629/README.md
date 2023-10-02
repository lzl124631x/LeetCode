# [1629. Slowest Key (Easy)](https://leetcode.com/problems/slowest-key/)

<p>A newly designed keypad was tested, where a tester pressed a sequence of <code>n</code> keys, one at a time.</p>

<p>You are given a string <code>keysPressed</code> of length <code>n</code>, where <code>keysPressed[i]</code> was the <code>i<sup>th</sup></code> key pressed in the testing sequence, and a sorted list <code>releaseTimes</code>, where <code>releaseTimes[i]</code> was the time the <code>i<sup>th</sup></code> key was released. Both arrays are <strong>0-indexed</strong>. The <code>0<sup>th</sup></code> key was pressed at the time <code>0</code>,&nbsp;and every subsequent key was pressed at the <strong>exact</strong> time the previous key was released.</p>

<p>The tester wants to know the key of the keypress that had the <strong>longest duration</strong>. The <code>i<sup>th</sup></code><sup> </sup>keypress had a <strong>duration</strong> of <code>releaseTimes[i] - releaseTimes[i - 1]</code>, and the <code>0<sup>th</sup></code> keypress had a duration of <code>releaseTimes[0]</code>.</p>

<p>Note that the same key could have been pressed multiple times during the test, and these multiple presses of the same key <strong>may not</strong> have had the same <strong>duration</strong>.</p>

<p><em>Return the key of the keypress that had the <strong>longest duration</strong>. If there are multiple such keypresses, return the lexicographically largest key of the keypresses.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> releaseTimes = [9,29,49,50], keysPressed = "cbcd"
<strong>Output:</strong> "c"
<strong>Explanation:</strong> The keypresses were as follows:
Keypress for 'c' had a duration of 9 (pressed at time 0 and released at time 9).
Keypress for 'b' had a duration of 29 - 9 = 20 (pressed at time 9 right after the release of the previous character and released at time 29).
Keypress for 'c' had a duration of 49 - 29 = 20 (pressed at time 29 right after the release of the previous character and released at time 49).
Keypress for 'd' had a duration of 50 - 49 = 1 (pressed at time 49 right after the release of the previous character and released at time 50).
The longest of these was the keypress for 'b' and the second keypress for 'c', both with duration 20.
'c' is lexicographically larger than 'b', so the answer is 'c'.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> releaseTimes = [12,23,36,46,62], keysPressed = "spuda"
<strong>Output:</strong> "a"
<strong>Explanation:</strong> The keypresses were as follows:
Keypress for 's' had a duration of 12.
Keypress for 'p' had a duration of 23 - 12 = 11.
Keypress for 'u' had a duration of 36 - 23 = 13.
Keypress for 'd' had a duration of 46 - 36 = 10.
Keypress for 'a' had a duration of 62 - 46 = 16.
The longest of these was the keypress for 'a' with duration 16.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>releaseTimes.length == n</code></li>
	<li><code>keysPressed.length == n</code></li>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= releaseTimes[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>releaseTimes[i] &lt; releaseTimes[i+1]</code></li>
	<li><code>keysPressed</code> contains only lowercase English letters.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/slowest-key/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int N = releaseTimes.size(), prev = 0, ans = 0, maxTime = 0;
        for (int i = 0; i < N; ++i) {
            int time = releaseTimes[i] - prev;
            prev = releaseTimes[i];
            if (time > maxTime || (time == maxTime && keysPressed[i] - 'a' > ans)) {
                ans = keysPressed[i] - 'a';
                maxTime = time;
            }
        }
        return 'a' + ans;
    }
};
```