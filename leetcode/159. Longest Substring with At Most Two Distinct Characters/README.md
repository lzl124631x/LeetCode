# [159. Longest Substring with At Most Two Distinct Characters (Hard)](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)

<p>Given a string <strong><em>s</em></strong> , find the length of the longest substring&nbsp;<strong><em>t&nbsp;&nbsp;</em></strong>that contains <strong>at most </strong>2 distinct characters.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> "eceba"
<strong>Output: </strong>3
<strong>Explanation: <em>t</em></strong><em> </em>is "ece" which its length is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> "ccaabbb"
<strong>Output: </strong>5
<strong>Explanation: <em>t</em></strong><em> </em>is "aabbb" which its length is 5.
</pre>

**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Longest Substring Without Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
* [Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)
* [Longest Substring with At Most K Distinct Characters (Hard)](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)
* [Subarrays with K Different Integers (Hard)](https://leetcode.com/problems/subarrays-with-k-different-integers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) 
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> m(128, 0);
        int i = 0, j = 0, ans = 0, cnt = 0;
        while (j < s.size()) {
            if (m[s[j++]]++ == 0) ++cnt;
            while (cnt > 2) {
                if (m[s[i++]]-- == 1) --cnt;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```