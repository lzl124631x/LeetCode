# [2189. Number of Ways to Build House of Cards (Medium)](https://leetcode.com/problems/number-of-ways-to-build-house-of-cards/)

<p>You are given an integer <code>n</code> representing the number of playing cards you have. A <strong>house of cards</strong> meets the following conditions:</p>

<ul>
	<li>A <strong>house of cards</strong> consists of one or more rows of <strong>triangles</strong> and horizontal cards.</li>
	<li><strong>Triangles</strong> are created by leaning two cards against each other.</li>
	<li>One card must be placed horizontally between <strong>all adjacent</strong> triangles in a row.</li>
	<li>Any triangle on a row higher than the first must be placed on a horizontal card from the previous row.</li>
	<li>Each triangle is placed in the <strong>leftmost</strong> available spot in the row.</li>
</ul>

<p>Return <em>the number of <strong>distinct</strong> <strong>house of cards</strong> you can build using <strong>all</strong></em> <code>n</code><em> cards.</em> Two houses of cards are considered distinct if there exists a row where the two houses contain a different number of cards.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/02/27/image-20220227213243-1.png" style="width: 726px; height: 150px;">
<pre><strong>Input:</strong> n = 16
<strong>Output:</strong> 2
<strong>Explanation:</strong> The two valid houses of cards are shown.
The third house of cards in the diagram is not valid because the rightmost triangle on the top row is not placed on top of a horizontal card.
</pre>

<p><strong>Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/02/27/image-20220227213306-2.png" style="width: 96px; height: 80px;">
<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> The one valid house of cards is shown.
</pre>

<p><strong>Example 3:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/02/27/image-20220227213331-3.png" style="width: 330px; height: 85px;">
<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> 0
<strong>Explanation:</strong> The three houses of cards in the diagram are not valid.
The first house of cards needs a horizontal card placed between the two triangles.
The second house of cards uses 5 cards.
The third house of cards uses 2 cards.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
</ul>


**Companies**:  
[Airbnb](https://leetcode.com/company/airbnb)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Champagne Tower (Medium)](https://leetcode.com/problems/champagne-tower/)

## Solution 1. Top-down DP

**Intuition**: Try using `1, 2, 3, ...` triangles in the first row, then count how many different houses we can build on top of this first row. 

**Algorithm**:

If we build `j` houses in the first row, then we can at most build `j - 1` houses in the second row. 

Let `dp[i][j]` be the number of different houses we can build given `i` cards and `j` houses allowed in the current row.

For `dp[i][j]`, we can try building `1, 2, 3, ..., j` houses in the current row.

```
dp[i][j] = SUM( dp[i - usedCards][housesInCurrentRow - 1] )
                where usedCards = 3 * housesInCurrentRow - 1
```

The trivial case is `dp[0][j] = 1` -- we add one to the answer once we used all the cards.

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-build-house-of-cards/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int houseOfCards(int n) {
        int m[501][170] = {};
        memset(m, -1, sizeof(m));
        function<int(int, int)> dp = [&](int i, int j) {
            if (i == 0) return 1;
            if (m[i][j] != -1) return m[i][j];
            int h = 1, used = 2, ans = 0;
            for (; h <= j && used <= i; ++h, used += 3) {
                ans += dp(i - used, h - 1);
            }
            return m[i][j] = ans;
        };
        return dp(n, n / 3 + 1);
    }
};
```

## Solution 2. Bottom-up DP

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-build-house-of-cards/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int houseOfCards(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int h = 1; h <= n / 3 + 1; ++h) { // build `h` houses in the current row
            int used = 3 * h - 1; // cards used in the current row
            for (int i = n; i >= used; --i) { // the # of cards available to build houses in the current row and rows above.
                dp[i] += dp[i - used];
            }
        }
        return dp[n];
    }
};
```