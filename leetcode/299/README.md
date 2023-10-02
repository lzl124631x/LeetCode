# [299. Bulls and Cows (Medium)](https://leetcode.com/problems/bulls-and-cows/)

<p>You are playing the <strong><a href="https://en.wikipedia.org/wiki/Bulls_and_Cows" target="_blank">Bulls and Cows</a></strong> game with your friend.</p>

<p>You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:</p>

<ul>
	<li>The number of "bulls", which are digits in the guess that are in the correct position.</li>
	<li>The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.</li>
</ul>

<p>Given the secret number <code>secret</code> and your friend's guess <code>guess</code>, return <em>the hint for your friend's guess</em>.</p>

<p>The hint should be formatted as <code>"xAyB"</code>, where <code>x</code> is the number of bulls and <code>y</code> is the number of cows. Note that both <code>secret</code> and <code>guess</code> may contain duplicate digits.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> secret = "1807", guess = "7810"
<strong>Output:</strong> "1A3B"
<strong>Explanation:</strong> Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"<u>7</u>8<u>10</u>"</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> secret = "1123", guess = "0111"
<strong>Output:</strong> "1A1B"
<strong>Explanation:</strong> Bulls are connected with a '|' and cows are underlined:
"1123"        "1123"
  |      or     |
"01<u>1</u>1"        "011<u>1</u>"
Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> secret = "1", guess = "0"
<strong>Output:</strong> "0A0B"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> secret = "1", guess = "1"
<strong>Output:</strong> "1A0B"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= secret.length, guess.length &lt;= 1000</code></li>
	<li><code>secret.length == guess.length</code></li>
	<li><code>secret</code> and <code>guess</code> consist of digits only.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [eBay](https://leetcode.com/company/ebay)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Counting](https://leetcode.com/tag/counting/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/bulls-and-cows/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string getHint(string secret, string guess) {
        int N = secret.size(), bull = 0, cow = 0, secretCnt[10] = {}, guessCnt[10] = {};
        for (int i = 0; i < N; ++i) {
            if (secret[i] == guess[i]) ++bull;
            else {
                secretCnt[secret[i] - '0']++;
                guessCnt[guess[i] - '0']++;
            } 
        }
        for (int i = 0; i < 10; ++i) cow += min(secretCnt[i], guessCnt[i]);
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
```