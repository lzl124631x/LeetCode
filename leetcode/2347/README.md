# [2347. Best Poker Hand (Easy)](https://leetcode.com/problems/best-poker-hand)

<p>You are given an integer array <code>ranks</code> and a character array <code>suits</code>. You have <code>5</code> cards where the <code>i<sup>th</sup></code> card has a rank of <code>ranks[i]</code> and a suit of <code>suits[i]</code>.</p>
<p>The following are the types of <strong>poker hands</strong> you can make from best to worst:</p>
<ol>
	<li><code>"Flush"</code>: Five cards of the same suit.</li>
	<li><code>"Three of a Kind"</code>: Three cards of the same rank.</li>
	<li><code>"Pair"</code>: Two cards of the same rank.</li>
	<li><code>"High Card"</code>: Any single card.</li>
</ol>
<p>Return <em>a string representing the <strong>best</strong> type of <strong>poker hand</strong> you can make with the given cards.</em></p>
<p><strong>Note</strong> that the return values are <strong>case-sensitive</strong>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> ranks = [13,2,3,1,9], suits = ["a","a","a","a","a"]
<strong>Output:</strong> "Flush"
<strong>Explanation:</strong> The hand with all the cards consists of 5 cards with the same suit, so we have a "Flush".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> ranks = [4,4,2,4,4], suits = ["d","a","a","b","c"]
<strong>Output:</strong> "Three of a Kind"
<strong>Explanation:</strong> The hand with the first, second, and fourth card consists of 3 cards with the same rank, so we have a "Three of a Kind".
Note that we could also make a "Pair" hand but "Three of a Kind" is a better hand.
Also note that other cards could be used to make the "Three of a Kind" hand.</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> ranks = [10,10,2,12,9], suits = ["a","b","c","a","d"]
<strong>Output:</strong> "Pair"
<strong>Explanation:</strong> The hand with the first and second card consists of 2 cards with the same rank, so we have a "Pair".
Note that we cannot make a "Flush" or a "Three of a Kind".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>ranks.length == suits.length == 5</code></li>
	<li><code>1 &lt;= ranks[i] &lt;= 13</code></li>
	<li><code>'a' &lt;= suits[i] &lt;= 'd'</code></li>
	<li>No two cards have the same rank and suit.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Categorize Box According to Criteria (Easy)](https://leetcode.com/problems/categorize-box-according-to-criteria/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/best-poker-hand
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    string bestHand(vector<int>& R, vector<char>& S) {
        int suit[4] = {}, rank[14] = {}, mxRank = 0, mxSuit = 0;
        for (int i = 0; i < 5; ++i) {
            mxRank = max(mxRank, ++rank[R[i]]);
            mxSuit = max(mxSuit, ++suit[S[i] - 'a']);
        }
        if (mxSuit == 5) return "Flush";
        if (mxRank >= 3) return "Three of a Kind";
        if (mxRank == 2) return "Pair";
        return "High Card";
    }
};
```