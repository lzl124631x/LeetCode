# [424. Longest Repeating Character Replacement (Medium)](https://leetcode.com/problems/longest-repeating-character-replacement/)

<p>You are given a string <code>s</code> and an integer <code>k</code>. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most <code>k</code> times.</p>

<p>Return <em>the length of the longest substring containing the same letter you can get after performing the above operations</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "ABAB", k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> Replace the two 'A's with two 'B's or vice versa.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "AABABBA", k = 1
<strong>Output:</strong> 4
<strong>Explanation:</strong> Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only uppercase English letters.</li>
	<li><code>0 &lt;= k &lt;= s.length</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber), [Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon), [Infosys](https://leetcode.com/company/infosys)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Longest Substring with At Most K Distinct Characters (Medium)](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)
* [Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii/)
* [Minimum Number of Operations to Make Array Continuous (Hard)](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/)

## Solution 1. Sliding Window

Check out "[C++ Maximum Sliding Window Cheatsheet Template!](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)".

Shrinkable Sliding Window:

```cpp
// OJ: https://leetcode.com/problems/longest-repeating-character-replacement/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, cnt[26] = {}, ans = 0, N = s.size();
        while (j < N) {
            cnt[s[j++] - 'A']++;
            while (j - i - *max_element(cnt, cnt + 26) > k) cnt[s[i++] - 'A']--;
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```

Non-shrinkable Sliding Window:

```cpp
// OJ: https://leetcode.com/problems/longest-repeating-character-replacement/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, cnt[26] = {}, N = s.size();
        while (j < N) {
            cnt[s[j++] - 'A']++;
            if (j - i - *max_element(cnt, cnt + 26) > k) cnt[s[i++] - 'A']--;
        }
        return j - i;
    }
};
```

## Solution 2. Sliding Window

Shrinkable Sliding Window:

```cpp
// OJ: https://leetcode.com/problems/longest-repeating-character-replacement
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, N = s.size();
        auto count = [&](char c) {
            int i = 0, j = 0, cnt = 0, ans = 0;
            for (; j < N; ++j) {
                cnt += s[j] != c;
                while (cnt > k) cnt -= s[i++] != c;
                ans = max(ans, j - i + 1);
            }
            return ans;
        };
        for (char c = 'A'; c <= 'Z'; ++c) ans = max(ans, count(c));
        return ans;
    }
};
```

Non-shrinkable sliding window:

```cpp
// OJ: https://leetcode.com/problems/longest-repeating-character-replacement
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, N = s.size();
        auto count = [&](char c) {
            int i = 0, j = 0, cnt = 0, ans = 0;
            for (; j < N; ++j) {
                cnt += s[j] != c;
                if (cnt > k) cnt -= s[i++] != c;
            }
            return j - i;
        };
        for (char c = 'A'; c <= 'Z'; ++c) ans = max(ans, count(c));
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/longest-repeating-character-replacement/discuss/1499834/C%2B%2B-Sliding-Window-(%2B-Cheat-Sheet)