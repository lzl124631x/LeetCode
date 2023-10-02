# [914. X of a Kind in a Deck of Cards (Easy)](https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/)

<p>In a deck of cards, each card has an integer written on it.</p>

<p>Return <code>true</code> if and only if you can choose&nbsp;<code>X &gt;= 2</code> such that&nbsp;it is possible to split the entire deck&nbsp;into 1 or more groups of cards, where:</p>

<ul>
	<li>Each group has exactly <code>X</code> cards.</li>
	<li>All the cards in each group have the same integer.</li>
</ul>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,2,3,4,4,3,2,1]</span>
<strong>Output: </strong><span id="example-output-1">true
<strong>Explanation</strong>: Possible partition [1,1],[2,2],[3,3],[4,4]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[1,1,1,2,2,2,3,3]</span>
<strong>Output: </strong><span id="example-output-2">false
</span><span id="example-output-1"><strong>Explanation</strong>: No possible partition.</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[1]</span>
<strong>Output: </strong><span id="example-output-3">false
</span><span id="example-output-1"><strong>Explanation</strong>: No possible partition.</span>
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong><span id="example-input-4-1">[1,1]</span>
<strong>Output: </strong><span id="example-output-4">true
</span><span id="example-output-1"><strong>Explanation</strong>: Possible partition [1,1]</span>
</pre>

<div>
<p><strong>Example 5:</strong></p>

<pre><strong>Input: </strong><span id="example-input-5-1">[1,1,2,2,2,2]</span>
<strong>Output: </strong><span id="example-output-5">true
</span><span id="example-output-1"><strong>Explanation</strong>: Possible partition [1,1],[2,2],[2,2]</span>
</pre>
</div>
</div>
</div>
</div>

<p><br>
<strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= deck.length &lt;= 10000</code></li>
	<li><code>0 &lt;= deck[i] &lt;&nbsp;10000</code></li>
</ol>

<div>
<div>
<div>
<div>
<div>&nbsp;</div>
</div>
</div>
</div>
</div>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
// Author: github.com/lzl124631x
// Time: O(N^2loglogN)
// Space: O(N)
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> cnt;
        for (int n : deck) cnt[n]++;
        int minCnt = INT_MAX;
        for (auto p : cnt) minCnt = min(minCnt, p.second);
        if (minCnt == 1) return false;
        for (int x = 2; x <= minCnt; ++x) {
            bool found = true;
            for (auto p : cnt) {
                if (p.second % x) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }
        return false;
    }
};
```