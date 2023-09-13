# [948. Bag of Tokens (Medium)](https://leetcode.com/problems/bag-of-tokens/)

<p>You have an initial power <code>P</code>, an initial score of <code>0</code> points, and a bag of tokens.</p>

<p>Each token can be used at most once, has a value <code>token[i]</code>, and has potentially two ways to use it.</p>

<ul>
	<li>If we have at least <code>token[i]</code> power, we may play the token face up, losing <code>token[i]</code> power, and gaining <code>1</code> point.</li>
	<li>If we have at least <code>1</code> point, we may play the token face down, gaining <code>token[i]</code> power, and losing <code>1</code> point.</li>
</ul>

<p>Return the largest number of points we can have after playing any number of tokens.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>tokens = <span id="example-input-1-1">[100]</span>, P = <span id="example-input-1-2">50</span>
<strong>Output: </strong><span id="example-output-1">0</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>tokens = <span id="example-input-2-1">[100,200]</span>, P = <span id="example-input-2-2">150</span>
<strong>Output: </strong><span id="example-output-2">1</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>tokens = <span id="example-input-3-1">[100,200,300,400]</span>, P = <span id="example-input-3-2">200</span>
<strong>Output: </strong><span id="example-output-3">2</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>tokens.length &lt;= 1000</code></li>
	<li><code>0 &lt;= tokens[i] &lt; 10000</code></li>
	<li><code>0 &lt;= P &lt; 10000</code></li>
</ol>
</div>
</div>
</div>

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Greedy + Two Pointers

Intuition: We would want to buy high value tokens using score and sell low value tokens to get scores.

So we should:

1. sort the tokens in asending order.
2. Try to use `P` to cover as much low value tokens as possible to get scores.
3. We buy the highest value token using one score, and add the value to `P`. If we can't buy any token, break.
4. Repeat step 2 and 3 until we've visited all tokens.
5. The final score we get is the answer.

```cpp
// OJ: https://leetcode.com/problems/bag-of-tokens/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1, S = 0; // i points to the next low value token we can sell, j points to the next high value token we can buy, S is the score.
        while (i <= j) {
            while (i <= j && tokens[i] <= P) { // tokens[i] can be covered by `P`, sell it for score.
                P -= tokens[i++];
                S++;
            }
            if (i < j && S) { // if i == j, we can't sell any token after buying this token. So we only buy this tokens[j] if i < j and we have some score left.
                S--;
                P += tokens[j--];
            } else break;
        }
        return S;
    }
};
```