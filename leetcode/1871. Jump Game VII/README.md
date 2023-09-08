# [ (Medium)](https://leetcode.com/problems/jump-game-vii)

<p>You are given a <strong>0-indexed</strong> binary string <code>s</code> and two integers <code>minJump</code> and <code>maxJump</code>. In the beginning, you are standing at index <code>0</code>, which is equal to <code>'0'</code>. You can move from index <code>i</code> to index <code>j</code> if the following conditions are fulfilled:</p>
<ul>
	<li><code>i + minJump &lt;= j &lt;= min(i + maxJump, s.length - 1)</code>, and</li>
	<li><code>s[j] == '0'</code>.</li>
</ul>
<p>Return <code>true</code><i> if you can reach index </i><code>s.length - 1</code><i> in </i><code>s</code><em>, or </em><code>false</code><em> otherwise.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "<u>0</u>11<u>0</u>1<u>0</u>", minJump = 2, maxJump = 3
<strong>Output:</strong> true
<strong>Explanation:</strong>
In the first step, move from index 0 to index 3. 
In the second step, move from index 3 to index 5.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "01101110", minJump = 2, maxJump = 3
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>s[0] == '0'</code></li>
	<li><code>1 &lt;= minJump &lt;= maxJump &lt; s.length</code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Jump Game II (Medium)](https://leetcode.com/problems/jump-game-ii/)
* [Jump Game (Medium)](https://leetcode.com/problems/jump-game/)
* [Jump Game III (Medium)](https://leetcode.com/problems/jump-game-iii/)
* [Jump Game IV (Hard)](https://leetcode.com/problems/jump-game-iv/)
* [Jump Game V (Hard)](https://leetcode.com/problems/jump-game-v/)
* [Jump Game VI (Medium)](https://leetcode.com/problems/jump-game-vi/)
* [Jump Game VII (Medium)](https://leetcode.com/problems/jump-game-vii/)
* [Jump Game VIII (Medium)](https://leetcode.com/problems/jump-game-viii/)
* [Count Vowel Strings in Ranges (Medium)](https://leetcode.com/problems/count-vowel-strings-in-ranges/)
* [Maximum Number of Jumps to Reach the Last Index (Medium)](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/jump-game-vii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(maxJump - minJump)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1') return false;
        queue<int> q;
        int j = 0, prev = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (i - prev > maxJump) return false;
            if (s[i] == '1') continue;
            j = max(j, i - maxJump);
            while (i - j >= minJump) {
                if (s[j] == '0') q.push(j);
                ++j;
            }
            while (q.size() && i - q.front() > maxJump) q.pop();
            if (q.empty()) s[i] = '1'; // mark this position as non-reachable.
            else prev = i;
        }
        return q.size();
    }
};
```

## Solution 2. Two Pointers

Mark reacheable position using `'2'`. For each `s[i] == '2'`, we traverse `i + minJump <= j <= i + maxJump` and turn `s[j]` to `2` if `s[j] == '0'`.

Pointer `j` can be monotonically increasing so that both pointer `i` and `j` at most traverse the array once.

```cpp
// OJ: https://leetcode.com/problems/jump-game-vii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1') return false;
        s[0] = '2'; // mark s[0] as reacheable
        int j = 0;
        for (int i = 0; i < s.size() && s.back() != '2'; ++i) {
            if (s[i] != '2') continue; // only extend reacheable points
            j = max(j, i + minJump); // `j` is at least `i + minJump`
            while (j < s.size() && j - i <= maxJump) { // try to extend until `j > i + maxJump`
                if (s[j] == '0') s[j] = '2'; // mark `s[j]` as reacheable if `s[j] == '0'`
                ++j;
            }
        }
        return s.back() == '2';
    }
};
```

## Solution 3. DP + Sliding Window

`dp[i] = true` if we can reach `s[i]`.

`active` is the number of previous positions that we can jump from.

For each `i`, the `[i - maxJump, i + minJump]` forms a sliding window, and we only update the `active` when `'0'` goes in/out of the window.

```cpp
// OJ: https://leetcode.com/problems/jump-game-vii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/jump-game-vii/discuss/1224804/JavaC%2B%2BPython-One-Pass-DP
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1') return false;
        int N = s.size(), active = 0;
        vector<int> dp(N);
        dp[0] = true;
        for (int i = 1; i < N; ++i) {
            if (i - minJump >= 0 && dp[i - minJump]) ++active;
            if (i - maxJump - 1 >= 0 && dp[i - maxJump - 1]) --active;
            dp[i] = s[i] == '0' && active;
        }
        return dp.back();
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/jump-game-vii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1') return false;
        int N = s.size(), active = 0;
        s[0] = '2';
        for (int i = 1; i < N && s.back() != '2'; ++i) {
            if (i - minJump >= 0 && s[i - minJump] == '2') ++active;
            if (i - maxJump - 1 >= 0 && s[i - maxJump - 1] == '2') --active;
            if (s[i] == '0' && active) s[i] = '2';
        }
        return s.back() == '2';
    }
};
```