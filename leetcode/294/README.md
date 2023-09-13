# [294. Flip Game II (Medium)](https://leetcode.com/problems/flip-game-ii/)

<p>You are playing a Flip Game with your friend.</p>

<p>You are given a string <code>currentState</code> that contains only <code>'+'</code> and <code>'-'</code>. You and your friend take turns to flip <strong>two consecutive</strong> <code>"++"</code> into <code>"--"</code>. The game ends when a person can no longer make a move, and therefore the other person will be the winner.</p>

<p>Return <code>true</code> <em>if the starting player can <strong>guarantee a win</strong></em>, and <code>false</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> currentState = "++++"
<strong>Output:</strong> true
<strong>Explanation:</strong> The starting player can guarantee a win by flipping the middle "++" to become "+--+".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> currentState = "+"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= currentState.length &lt;= 60</code></li>
	<li><code>currentState[i]</code> is either <code>'+'</code> or <code>'-'</code>.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Derive your algorithm's runtime complexity.

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/), [Memoization](https://leetcode.com/tag/memoization/), [Game Theory](https://leetcode.com/tag/game-theory/)

**Similar Questions**:
* [Nim Game (Easy)](https://leetcode.com/problems/nim-game/)
* [Flip Game (Easy)](https://leetcode.com/problems/flip-game/)
* [Guess Number Higher or Lower II (Medium)](https://leetcode.com/problems/guess-number-higher-or-lower-ii/)
* [Can I Win (Medium)](https://leetcode.com/problems/can-i-win/)

## Solution 1.

At first I tried finding some greedy solution but I failed. Then I stepped back to think about the brute force solution which would be DFS. On top of that we can reduce repetitive computation using Memoization, i.e. Top-down DP.

**Time Complexity**:

In the worst case, all the `N` characters are `+` signs. To get a intermediate state, we can flip some of the `+`s to `-`s. The first `++` to flip has `N-1` options. The second `++` to flip at most has `N-3` options. And so on. So in total there could be `(N-1)(N-3)(N-5)...` total states. Saving a state into the map takes `O(N)` time, so in total it's at most `O(N!)` time.

```cpp
// OJ: https://leetcode.com/problems/flip-game-ii/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N!)
class Solution {
public:
    bool canWin(string s) {
        bitset<60> bs;
        int cnt = 0;
        int N = s.size();
        for (int i = 0; i < N; ++i) {
            if (s[i] == '+') {
                bs.set(i);
                ++cnt;
            }
        }
        unordered_map<bitset<60>, bool> m;
        function<bool()> dp = [&]() {
            if (cnt == 0 || cnt == 1) return false;
            if (m.count(bs)) return m[bs];
            bool ans = false;
            for (int i = 0; i + 1 < N && !ans; ++i) {
                if (bs.test(i) && bs.test(i + 1)) {
                    bs.reset(i);
                    bs.reset(i + 1);
                    cnt -= 2;
                    if (!dp()) ans = true;
                    bs.set(i);
                    bs.set(i + 1);
                    cnt += 2;
                }
            }
            return m[bs] = ans;
        };
        return dp();
    }
};
```

## Solution 2. Game Theory

```cpp
// OJ: https://leetcode.com/problems/flip-game-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
// Ref: https://leetcode.com/problems/flip-game-ii/discuss/73954
class Solution {
    int firstMissingNumber(unordered_set<int> &s) {
        int N = s.size();
        for (int i = 0; i < N; ++i) {
            if (s.count(i) == 0) return i;
        }
        return N;
    }
public:
    bool canWin(string s) {
        int curLen = 0, maxLen = 0, N = s.size();
        vector<int> init;
        for (int i = 0; i < N; ++i) {
            if (s[i] == '+') curLen++;
            if (i + 1 == N || s[i] == '-') {
                if (curLen >= 2) init.push_back(curLen);
                maxLen = max(maxLen, curLen);
                curLen = 0;
            }
        }
        vector<int> G(maxLen + 1);
        for (int len = 2; len <= maxLen; ++len) {
            unordered_set<int> sub;
            for (int lenFirstGame = 0; lenFirstGame < len / 2; ++lenFirstGame) {
                int lenSecondGame = len - lenFirstGame - 2;
                sub.insert(G[lenFirstGame] ^ G[lenSecondGame]);
            }
            G[len] = firstMissingNumber(sub);
        }
        int ans = 0;
        for (int n : init) ans ^= G[n];
        return ans != 0;
    }
};
```