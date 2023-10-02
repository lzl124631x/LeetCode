# [771. Jewels and Stones (Easy)](https://leetcode.com/problems/jewels-and-stones/)

<p>You're given strings <code>J</code> representing the types of stones that are jewels, and <code>S</code> representing the stones you have.&nbsp; Each character in <code>S</code> is a type of stone you have.&nbsp; You want to know how many of the stones you have are also jewels.</p>

<p>The letters in <code>J</code> are guaranteed distinct, and all characters in <code>J</code> and <code>S</code> are letters. Letters are case sensitive, so <code>"a"</code> is considered a different type of stone from <code>"A"</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> J = "aA", S = "aAAbbbb"
<strong>Output:</strong> 3
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> J = "z", S = "ZZ"
<strong>Output:</strong> 0
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li><code>S</code> and <code>J</code> will consist of letters and have length at most 50.</li>
	<li>The characters in <code>J</code> are distinct.</li>
</ul>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/jewels-and-stones/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s(J.begin(), J.end());
        int ans = 0;
        for (char c : S) ans += s.count(c);
        return ans;
    }
};
```