# [744. Find Smallest Letter Greater Than Target (Easy)](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)

<p>
Given a list of sorted characters <code>letters</code> containing only lowercase letters, and given a target letter <code>target</code>, find the smallest element in the list that is larger than the given target.
</p><p>
Letters also wrap around.  For example, if the target is <code>target = 'z'</code> and <code>letters = ['a', 'b']</code>, the answer is <code>'a'</code>.
</p>

<p><b>Examples:</b><br>
</p><pre><b>Input:</b>
letters = ["c", "f", "j"]
target = "a"
<b>Output:</b> "c"

<b>Input:</b>
letters = ["c", "f", "j"]
target = "c"
<b>Output:</b> "f"

<b>Input:</b>
letters = ["c", "f", "j"]
target = "d"
<b>Output:</b> "f"

<b>Input:</b>
letters = ["c", "f", "j"]
target = "g"
<b>Output:</b> "j"

<b>Input:</b>
letters = ["c", "f", "j"]
target = "j"
<b>Output:</b> "c"

<b>Input:</b>
letters = ["c", "f", "j"]
target = "k"
<b>Output:</b> "c"
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li><code>letters</code> has a length in range <code>[2, 10000]</code>.</li>
<li><code>letters</code> consists of lowercase letters, and contains at least 2 unique letters.</li>
<li><code>target</code> is a lowercase letter.</li>
</ol>
<p></p>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto i = upper_bound(letters.begin(), letters.end(), target);
        return i == letters.end() ? letters[0] : *i;
    }
};
```