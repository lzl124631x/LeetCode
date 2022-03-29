# [2209. Minimum White Tiles After Covering With Carpets (Hard)](https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/)

<p>You are given a <strong>0-indexed binary</strong> string <code>floor</code>, which represents the colors of tiles on a floor:</p>

<ul>
	<li><code>floor[i] = '0'</code> denotes that the <code>i<sup>th</sup></code> tile of the floor is colored <strong>black</strong>.</li>
	<li>On the other hand, <code>floor[i] = '1'</code> denotes that the <code>i<sup>th</sup></code> tile of the floor is colored <strong>white</strong>.</li>
</ul>

<p>You are also given <code>numCarpets</code> and <code>carpetLen</code>. You have <code>numCarpets</code> <strong>black</strong> carpets, each of length <code>carpetLen</code> tiles. Cover the tiles with the given carpets such that the number of <strong>white</strong> tiles still visible is <strong>minimum</strong>. Carpets may overlap one another.</p>

<p>Return <em>the <strong>minimum</strong> number of white tiles still visible.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/10/ex1-1.png" style="width: 400px; height: 73px;">
<pre><strong>Input:</strong> floor = "10110101", numCarpets = 2, carpetLen = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The figure above shows one way of covering the tiles with the carpets such that only 2 white tiles are visible.
No other way of covering the tiles with the carpets can leave less than 2 white tiles visible.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/10/ex2.png" style="width: 353px; height: 123px;">
<pre><strong>Input:</strong> floor = "11111", numCarpets = 2, carpetLen = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
The figure above shows one way of covering the tiles with the carpets such that no white tiles are visible.
Note that the carpets are able to overlap one another.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= carpetLen &lt;= floor.length &lt;= 1000</code></li>
	<li><code>floor[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>1 &lt;= numCarpets &lt;= 1000</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Edit Distance (Hard)](https://leetcode.com/problems/edit-distance/)

## Solution 1. Fixed-length Sliding Window + DP

**Intuition**:

1. Use a sliding window of length `carpetLen` to compute a `cover` array where `cover[i]` is the number of white tiles covered by a carpet placed ending at `floor[i]`.
2. Use DP to calculate the maximum coverable white tiles using `numCarpets` carpets.

**Algorithm**:

**Fixed-length Sliding Window**:

Keep a rolling sum `white` as the number of white tiles within the sliding window.

For each `i` in range `[0, N)`, we:
* increment `white` if `s[i] == '1'`
* decrement `white` if `s[i - len] == '1'`
* Set `cover[i] = white`.

**DP**:

Let `dp[i][j + 1]` be the maximum number of coverable white tiles where `1 <= i <= numCarpet` is number of carpets used and `0 <= j < N` is the last index where we can place carpet.

All `dp` values are initialized as `0`s.

For each `dp[i][j + 1]`, we have two options:
1. Don't place carpet at index `j`. `dp[i][j+1] = dp[i][j]`
2. Place carpet ending at index `j` covering `cover[j]` white tiles. And we can place `i-1` carpets at or before `j-carpetLen`. So, `dp[i][j+1] = dp[i-1][j-carpetLen+1] + cover[j]`.

```
dp[i][j + 1] = max(
                    dp[i][j],                                                                   // don't place carpet at index `j`
                    (j - carpetLen + 1 >= 0 ? dp[i - 1][j - carpetLen + 1] : 0) + cover[j]      // place carpet at index `j`
                  )
```

`dp[numCarpet][N]` is the maximum number of white titles coverable. The answer is the number of total white tiles minus `dp[numCarpet][N]`. 

```cpp
// OJ: https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/
// Author: github.com/lzl124631x
// Time: O(N * numCarpet)
// Space: O(N * numCarpet)
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpet, int carpetLen) {
        int N = floor.size(), sum = 0;
        vector<int> cover(N);
        for (int i = 0, white = 0; i < N; ++i) {
            sum += floor[i] - '0';
            white += floor[i] - '0';
            if (i - carpetLen >= 0) white -= floor[i - carpetLen] - '0'; 
            cover[i] = white;
        }
        vector<vector<int>> dp(numCarpet + 1, vector<int>(N + 1));
        for (int i = 1; i <= numCarpet; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j + 1] = max(dp[i][j], (j - carpetLen + 1 >= 0 ? dp[i - 1][j - carpetLen + 1] : 0) + cover[j]);
            }
        }
        return sum - dp[numCarpet][N];
    }
};
```

We can reduce the space complexity to `O(N)` by using rolling arrays.

```cpp
// OJ: https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/
// Author: github.com/lzl124631x
// Time: O(N * numCarpet)
// Space: O(N)
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpet, int carpetLen) {
        int N = floor.size(), sum = 0;
        vector<int> cover(N);
        for (int i = 0, white = 0; i < N; ++i) {
            sum += floor[i] - '0';
            white += floor[i] - '0';
            if (i - carpetLen >= 0) white -= floor[i - carpetLen] - '0'; 
            cover[i] = white;
        }
        vector<int> dp(N + 1);
        for (int i = 1; i <= numCarpet; ++i) {
            vector<int> next(N + 1);
            for (int j = 0; j < N; ++j) {
                next[j + 1] = max(next[j], (j - carpetLen + 1 >= 0 ? dp[j - carpetLen + 1] : 0) + cover[j]);
            }
            swap(dp, next);
        }
        return sum - dp[N];
    }
};
```

## Disucss

https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/discuss/1863879