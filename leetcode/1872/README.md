# [1872. Stone Game VIII (Hard)](https://leetcode.com/problems/stone-game-viii/)

<p>Alice and Bob take turns playing a game, with <strong>Alice starting first</strong>.</p>

<p>There are <code>n</code> stones arranged in a row. On each player's turn, while the number of stones is <strong>more than one</strong>, they will do the following:</p>

<ol>
	<li>Choose an integer <code>x &gt; 1</code>, and <strong>remove</strong> the leftmost <code>x</code> stones from the row.</li>
	<li>Add the <strong>sum</strong> of the <strong>removed</strong> stones' values to the player's score.</li>
	<li>Place a <strong>new stone</strong>, whose value is equal to that sum, on the left side of the row.</li>
</ol>

<p>The game stops when <strong>only</strong> <strong>one</strong> stone is left in the row.</p>

<p>The <strong>score difference</strong> between Alice and Bob is <code>(Alice's score - Bob's score)</code>. Alice's goal is to <strong>maximize</strong> the score difference, and Bob's goal is the <strong>minimize</strong> the score difference.</p>

<p>Given an integer array <code>stones</code> of length <code>n</code> where <code>stones[i]</code> represents the value of the <code>i<sup>th</sup></code> stone <strong>from the left</strong>, return <em>the <strong>score difference</strong> between Alice and Bob if they both play <strong>optimally</strong>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> stones = [-1,2,-3,4,-5]
<strong>Output:</strong> 5
<strong>Explanation:</strong>
- Alice removes the first 4 stones, adds (-1) + 2 + (-3) + 4 = 2 to her score, and places a stone of
  value 2 on the left. stones = [2,-5].
- Bob removes the first 2 stones, adds 2 + (-5) = -3 to his score, and places a stone of value -3 on
  the left. stones = [-3].
The difference between their scores is 2 - (-3) = 5.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> stones = [7,-6,5,10,5,-2,-6]
<strong>Output:</strong> 13
<strong>Explanation:</strong>
- Alice removes all stones, adds 7 + (-6) + 5 + 10 + 5 + (-2) + (-6) = 13 to her score, and places a
  stone of value 13 on the left. stones = [13].
The difference between their scores is 13 - 0 = 13.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> stones = [-10,-12]
<strong>Output:</strong> -22
<strong>Explanation:</strong>
- Alice can only make one move, which is to remove both stones. She adds (-10) + (-12) = -22 to her
  score and places a stone of value -22 on the left. stones = [-22].
The difference between their scores is (-22) - 0 = -22.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == stones.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= stones[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Infosys](https://leetcode.com/company/infosys)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Stone Game (Medium)](https://leetcode.com/problems/stone-game/)
* [Stone Game II (Medium)](https://leetcode.com/problems/stone-game-ii/)
* [Stone Game III (Hard)](https://leetcode.com/problems/stone-game-iii/)
* [Stone Game IV (Hard)](https://leetcode.com/problems/stone-game-iv/)
* [Stone Game V (Hard)](https://leetcode.com/problems/stone-game-v/)
* [Stone Game VI (Medium)](https://leetcode.com/problems/stone-game-vi/)
* [Stone Game VII (Medium)](https://leetcode.com/problems/stone-game-vii/)
* [Stone Game VIII (Hard)](https://leetcode.com/problems/stone-game-viii/)

## Solution 1. DP

Let prefix sum `prefix[i] = A[0] + ... + A[i]`. 

Let `dp[i]` be the maximum score difference the current player can get when the game starts at `i`, i.e. stones `0 ~ i` are already merged as a new stone `i` whose value is `prefix[i]`.

Consider `dp[i]`: assume the current player chooses to merge stones `0 ~ j` (`i < j < N`), according to the `dp` definition, the maximum score difference the next player can get using the remaining stones is `dp[j]`. So the score difference the current player gets is `prefix[j] - dp[j]`.

The current player will need to try all `i < j < N` and use the maximum `prefix[j] - dp[j]` as `dp[i]`. Thus, we have:

```
dp[i] = max( prefix[j] - dp[j] | i < j <= N - 2 )
dp[N - 2] = prefix[N - 1] // when there are only two stones left, the current player must take them all
```

The anser is `dp[0]`.

We can simplify the above formula into the following form. In this way, `dp` doesn't have to be an array; we just need to store the latest `dp` value.

```
dp[i] = max( dp[i + 1], prefix[i + 1] - dp[i + 1] )   where 0 <= i < N - 2
dp[N - 2] = prefix[N - 1]
```

```cpp
// OJ: https://leetcode.com/problems/stone-game-viii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int stoneGameVIII(vector<int>& A) {
        int N = A.size();
        for (int i = 1; i < N; ++i) A[i] += A[i - 1]; // now A[i] is the prefix sum, i.e. prefix[i]
		int dp = A.back(); // dp[N - 2] = prefix[N - 1]
        for (int i = N - 2; i > 0; --i) dp = max(dp, A[i] - dp); // dp[i - 1] = max(dp[i], A[i] - dp[i]) 
        return dp; // dp[0]
    }
};
```

Or use STL functions to minify code.

```cpp
// OJ: https://leetcode.com/problems/stone-game-viii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int stoneGameVIII(vector<int>& A) {
        partial_sum(begin(A), end(A), begin(A));
        return accumulate(next(rbegin(A)), prev(rend(A)), A.back(), [](int memo, int cur) { return max(memo, cur - memo); });
    }
};
```

Or one liner in python.

```py
# OJ: https://leetcode.com/problems/stone-game-viii/
# Author: github.com/lzl124631x
class Solution:
    def stoneGameVIII(self, A: List[int]) -> int:
        return reduce(lambda memo, cur : max(memo, cur - memo), list(accumulate(A))[::-1][:-1])
```