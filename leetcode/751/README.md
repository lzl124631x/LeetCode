# [340. Longest Substring with At Most K Distinct Characters (Hard)](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)

<p>Given a string, find the length of the longest substring T that contains at most <i>k</i> distinct characters.</p>

<p><strong>Example 1:</strong></p>

<div>
<pre><strong>Input: </strong>s = <span id="example-input-1-1">"eceba"</span>, k = <span id="example-input-1-2">2</span>
<strong>Output: </strong><span id="example-output-1">3</span>
<strong>Explanation: </strong>T is "ece" which its length is 3.</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>s = <span id="example-input-2-1">"aa"</span>, k = <span id="example-input-2-2">1</span>
<strong>Output: </strong>2
<strong>Explanation: </strong>T is "aa" which its length is 2.
</pre>
</div>
</div>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Longest Substring Without Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
* [Longest Substring with At Most Two Distinct Characters (Hard)](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)
* [Longest Repeating Character Replacement (Medium)](https://leetcode.com/problems/longest-repeating-character-replacement/)
* [Subarrays with K Different Integers (Hard)](https://leetcode.com/problems/subarrays-with-k-different-integers/)
* [Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> m(128, 0);
        int i = 0, j = 0, ans = 0, cnt = 0;
        while (j < s.size()) {
            if (m[s[j++]]++ == 0) cnt++;
            while (cnt > k) {
                if (m[s[i++]]-- == 1) cnt--;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```