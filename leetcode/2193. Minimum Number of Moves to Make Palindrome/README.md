# [2193. Minimum Number of Moves to Make Palindrome (Hard)](https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/)

<p>You are given a string <code>s</code> consisting only of lowercase English letters.</p>

<p>In one <strong>move</strong>, you can select any two <strong>adjacent</strong> characters of <code>s</code> and swap them.</p>

<p>Return <em>the <strong>minimum number of moves</strong> needed to make</em> <code>s</code> <em>a palindrome</em>.</p>

<p><strong>Note</strong> that the input will be generated such that <code>s</code> can always be converted to a palindrome.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aabb"
<strong>Output:</strong> 2
<strong>Explanation:</strong>
We can obtain two palindromes from s, "abba" and "baab". 
- We can obtain "abba" from s in 2 moves: "a<u><strong>ab</strong></u>b" -&gt; "ab<u><strong>ab</strong></u>" -&gt; "abba".
- We can obtain "baab" from s in 2 moves: "a<u><strong>ab</strong></u>b" -&gt; "<u><strong>ab</strong></u>ab" -&gt; "baab".
Thus, the minimum number of moves needed to make s a palindrome is 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "letelt"
<strong>Output:</strong> 2
<strong>Explanation:</strong>
One of the palindromes we can obtain from s in 2 moves is "lettel".
One of the ways we can obtain it is "lete<u><strong>lt</strong></u>" -&gt; "let<u><strong>et</strong></u>l" -&gt; "lettel".
Other palindromes such as "tleelt" can also be obtained in 2 moves.
It can be shown that it is not possible to obtain a palindrome in less than 2 moves.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
	<li><code>s</code> can be converted to a palindrome using a finite number of moves.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/)

**Similar Questions**:
* [Minimum Insertion Steps to Make a String Palindrome (Hard)](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)

## Solution 1. Greedy

Intuition 1: Consider the first and last character in the final palindrome, if they are neither the first nor the last character in the initial string, you must waste some steps.

Assume the final palindrome is `a......a` and the initial string is `x..a....a.y` (`x`, `y` are not `a`.). `..a....a..` can be completed earlier than `a......a`. (How can we formally prove this?)

Intuition 2: For `s = "a....b..a...b"`, it takes the same number of steps to get `"ab.........ba"` and `"ba.........ab"`.

Proof: `a ( x ) b ( y ) a ( z ) b` (`x, y, z` are the number of characters inbetween). Getting `ab...ba` takes `x + (z+1)` steps, and getting `ba...ab` takes `(x+1) + z` steps. So they are the same.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
// Ref: https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/discuss/1822174/
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0;
        while (s.size()) {
            int i = s.find(s.back());
            if (i == s.size() - 1) ans += i / 2; // this character should be put at the middle.
            else ans += i, s.erase(i, 1);
            s.pop_back();
        }
        return ans;
    }
};
```

This solution is tricky because it removes the characters instead of really moving them.

Assume `s = "bbcca"`.

Step 1. Move `a` 2 steps to the center

Step 2. Move `c` 2 steps.

Step 3. No move needed for `b`.

If we do the moving instead of removal, we need to do it in the reversed order.

Step 1. no move needed for `b` `"bbcca"`

Step 2. Move `c` 2 steps `"bbcca" -> "bcbca" -> "cbbca"`

Step 3. Move `a` 2 steps `"cbbca" -> "cbbac" -> "cbabc"`

## TODO

SegmentTree/BIT solutions