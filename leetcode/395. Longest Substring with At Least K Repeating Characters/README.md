# [395. Longest Substring with At Least K Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/)

<p>Given a string <code>s</code> and an integer <code>k</code>, return <em>the length of the longest substring of</em> <code>s</code> <em>such that the frequency of each character in this substring is greater than or equal to</em> <code>k</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aaabb", k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest substring is "aaa", as 'a' is repeated 3 times.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "ababbc", k = 2
<strong>Output:</strong> 5
<strong>Explanation:</strong> The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


**Related Topics**:  
[Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Recursion](https://leetcode.com/tag/recursion/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

## Solution 1. Sliding Window + Recursion

```cpp
// OJ: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestSubstring(string s, int k) {
        int cnt[26] = {}, ans = 0; // `cnt[i]` is the remaining count of characters `'a' + i` that haven't been added into the sliding window
        for (char c : s) cnt[c - 'a']++;
        for (int i = 0, N = s.size(); i < N; ) { // i is the starting point.
            int added[26] = {}; // the characters in range [i, j) are counted in `added`.
            while (i < N && cnt[s[i] - 'a'] < k) ++i; // skip those characters with counts less than k because they won't show up in the answer
            int j = i; // j is the ending point
            while (j < N && cnt[s[j] - 'a'] + added[s[j] - 'a'] >= k) {
                added[s[j] - 'a']++; // add `s[j]` into the window. Decrement `cnt[s[j] - 'a']` since this occurrence is used.
                cnt[s[j] - 'a']--;
                ++j;
            }
            bool valid = true;
            for (int n : added) {
                if (n && n < k) {
                    valid = false;
                    break;
                }
            }
            if (valid) ans = max(ans, j - i); // if this window is valid, update answer
            else ans = max(ans, longestSubstring(s.substr(i, j - i), k)); // otherwise, solve recursively
            i = j;
        }
        return ans;
    }
};
```

## Solution 2. Sliding Window + Recursion

```cpp
// OJ: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/57134/two-short-c-solutions-3ms-and-6ms
class Solution {
private:
    int longestSubstring(string &s, int k, int begin, int end) {
        int cnt[26] = {};
        for (int i = begin; i < end; ++i) cnt[s[i] - 'a']++;
        int i = begin, ans = 0;
        while (i < end) {
            while (i < end && cnt[s[i] - 'a'] < k) ++i;
            int j = i;
            while (j < end && cnt[s[j] - 'a'] >= k) ++j;
            if (i == begin && j == end) return end - begin;
            ans = max(ans, longestSubstring(s, k, i, j));
            i = j;
        }
        return ans;
    }
public:
    int longestSubstring(string s, int k) {
        return longestSubstring(s, k, 0, s.size());
    }
};
```