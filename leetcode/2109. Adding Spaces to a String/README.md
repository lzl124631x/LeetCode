# [2109. Adding Spaces to a String (Medium)](https://leetcode.com/problems/adding-spaces-to-a-string/)

<p>You are given a <strong>0-indexed</strong> string <code>s</code> and a <strong>0-indexed</strong> integer array <code>spaces</code> that describes the indices in the original string where spaces will be added. Each space should be inserted <strong>before</strong> the character at the given index.</p>

<ul>
	<li>For example, given <code>s = "EnjoyYourCoffee"</code> and <code>spaces = [5, 9]</code>, we place spaces before <code>'Y'</code> and <code>'C'</code>, which are at indices <code>5</code> and <code>9</code> respectively. Thus, we obtain <code>"Enjoy <strong><u>Y</u></strong>our <u><strong>C</strong></u>offee"</code>.</li>
</ul>

<p>Return<strong> </strong><em>the modified string <strong>after</strong> the spaces have been added.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
<strong>Output:</strong> "Leetcode Helps Me Learn"
<strong>Explanation:</strong> 
The indices 8, 13, and 15 correspond to the underlined characters in "Leetcode<u><strong>H</strong></u>elps<u><strong>M</strong></u>e<u><strong>L</strong></u>earn".
We then place spaces before those characters.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "icodeinpython", spaces = [1,5,7,9]
<strong>Output:</strong> "i code in py thon"
<strong>Explanation:</strong>
The indices 1, 5, 7, and 9 correspond to the underlined characters in "i<u><strong>c</strong></u>ode<u><strong>i</strong></u>n<u><strong>p</strong></u>y<u><strong>t</strong></u>hon".
We then place spaces before those characters.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "spacing", spaces = [0,1,2,3,4,5,6]
<strong>Output:</strong> " s p a c i n g"
<strong>Explanation:</strong>
We are also able to place spaces before the first character of the string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> consists only of lowercase and uppercase English letters.</li>
	<li><code>1 &lt;= spaces.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= spaces[i] &lt;= s.length - 1</code></li>
	<li>All the values of <code>spaces</code> are <strong>strictly increasing</strong>.</li>
</ul>

## Solution 1. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/adding-spaces-to-a-string/
// Author: github.com/lzl124631x
// Time: O(N + M) = O(N)
// Space: O(1) extra space
class Solution {
public:
    string addSpaces(string s, vector<int>& A) {
        string ans;
        ans.reserve(s.size() + A.size()); // Optional: pre-allocate enough space for the answer.
        int N = s.size(), j = 0, M = A.size(); // `A[j]` is the next index before which a space should be inserted
        for (int i = 0; i < N; ++i) {
            if (j < M && i == A[j]) { // If `i == A[j]`, we insert a space
                ans += ' ';
                ++j;
            }
            ans += s[i];
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/adding-spaces-to-a-string/discuss/1635042/C%2B%2B-Straightforward