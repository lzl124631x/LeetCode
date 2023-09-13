# [691. Stickers to Spell Word (Hard)](https://leetcode.com/problems/stickers-to-spell-word/)

<p>
We are given N different types of stickers.  Each sticker has a lowercase English word on it.
</p><p>
You would like to spell out the given <code>target</code> string by cutting individual letters from your collection of stickers and rearranging them.
</p><p>
You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
</p><p>
What is the minimum number of stickers that you need to spell out the <code>target</code>?  If the task is impossible, return -1.
</p>

<p><b>Example 1:</b></p>
<p>Input:</p><pre>["with", "example", "science"], "thehat"
</pre><p></p>

<p>Output:</p><pre>3
</pre><p></p>

<p>Explanation:</p><pre>We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.
</pre><p></p>

<p><b>Example 2:</b></p>
<p>Input:</p><pre>["notice", "possible"], "basicbasic"
</pre><p></p>

<p>Output:</p><pre>-1
</pre><p></p>

<p>Explanation:</p><pre>We can't form the target "basicbasic" from cutting letters from the given stickers.
</pre><p></p>

<p><b>Note:</b>
</p><li><code>stickers</code> has length in the range <code>[1, 50]</code>.</li>
<li><code>stickers</code> consists of lowercase English words (without apostrophes).</li>
<li><code>target</code> has length in the range <code>[1, 15]</code>, and consists of lowercase English letters.</li>
<li>In all test cases, all words were chosen <u>randomly</u> from the 1000 most common US English words, and the target was chosen as a concatenation of two random words.</li>
<li>The time limit may be more challenging than usual.  It is expected that a 50 sticker test case can be solved within 35ms on average.</li>
<p></p>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Ransom Note (Easy)](https://leetcode.com/problems/ransom-note/)

## Solution 1. Bitmask DP

```cpp
// OJ: https://leetcode.com/problems/stickers-to-spell-word/
// Author: github.com/lzl124631x
// Time: O(2^T * S * T)
// Space: O(2^T)
// Ref: https://leetcode.com/problems/stickers-to-spell-word/solution/
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int N = target.size();
        vector<int> dp(1 << N, -1);
        dp[0] = 0;
        for (int state = 0; state < 1 << N; ++state) { // a state represents the target characters matched
            if (dp[state] == -1) continue; // this state is not reachable
            for (auto &s : stickers) { // try each sticker
                int next = state;
                for (char c : s) { // for each character in the current sticker
                    for (int i = 0; i < N; ++i) {
                        if ((next >> i) & 1) continue; // if the current target character set doesn't contain the target[i], skip
                        if (target[i] == c) {
                            next |= 1 << i; // if they are matched, we can update the next state reachable
                            break;
                        }
                    }
                }
                if (dp[next] == -1 || dp[next] > dp[state] + 1) dp[next] = dp[state] + 1;
            }
        }
        return dp[(1 << N) - 1];
    }
};
```