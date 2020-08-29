# [920. Number of Music Playlists (Hard)](https://leetcode.com/problems/number-of-music-playlists/)

<p>Your music player contains <code>N</code>&nbsp;different songs and she wants to listen to <code>L</code><strong> </strong>(not necessarily different) songs during your trip. &nbsp;You&nbsp;create&nbsp;a playlist so&nbsp;that:</p>

<ul>
	<li>Every song is played at least once</li>
	<li>A song can only be played again only if&nbsp;<code>K</code>&nbsp;other songs have been played</li>
</ul>

<p>Return the number of possible playlists.&nbsp; <strong>As the answer can be very large, return it modulo <code>10^9 + 7</code></strong>.</p>

<p>&nbsp;</p>

<div>
<div>
<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-1-1">3</span>, L = <span id="example-input-1-2">3</span>, K = <span id="example-input-1-3">1</span>
<strong>Output: </strong><span id="example-output-1">6
<strong>Explanation</strong>: </span><span>There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-2-1">2</span>, L = <span id="example-input-2-2">3</span>, K = <span id="example-input-2-3">0</span>
<strong>Output: </strong><span id="example-output-2">6
</span><span id="example-output-1"><strong>Explanation</strong>: </span><span>There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>N = <span id="example-input-3-1">2</span>, L = <span id="example-input-3-2">3</span>, K = <span id="example-input-3-3">1</span>
<strong>Output: </strong><span id="example-output-3">2
<strong>Explanation</strong>: </span><span>There are 2 possible playlists. [1, 2, 1], [2, 1, 2]</span>
</pre>
</div>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= K &lt; N &lt;= L &lt;= 100</code></li>
</ol>
</div>
</div>
</div>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

Let `dp[i][j]` be the number of playlists of length `i` that have exactly `j` unique songs. The answer is `dp[L][N]`.

To get `dp[i][j]`, we consider the `i-1`-th song:
* It has not been played before. This is the first time it's played. The first `i - 1` songs must have `j - 1` unique songs. We can choose from `N - (j - 1)` new songs. So `dp[i - 1][j - 1] * (N - j + 1)` cases.
* It has been played before. The first `i - 1` songs must have `j` unique songs. This song is one of the `j` unique songs. The `[i - K, i - 1]` songs must be unique and the last song can't be of these `K` songs. So we can only choose from the remaining `j - K` songs. `dp[i - 1][j] * max(j - K, 0)`

```cpp
// OJ: https://leetcode.com/problems/number-of-music-playlists/
// Author: github.com/lzl124631x
// Time: O(NL)
// Space: O(NL)
// Ref: https://leetcode.com/problems/number-of-music-playlists/solution/
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        long dp[101][101] = {}, mod = 1e9+7;
        dp[0][0] = 1;
        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] += dp[i - 1][j - 1] * (N - j + 1);
                dp[i][j] += dp[i - 1][j] * max(j - K, 0);
                dp[i][j] %= mod;
            }
        }
        return dp[L][N];
    }
};
```