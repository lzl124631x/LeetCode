# [2516. Take K of Each Character From Left and Right (Medium)](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right)

<p>You are given a string <code>s</code> consisting of the characters <code>'a'</code>, <code>'b'</code>, and <code>'c'</code> and a non-negative integer <code>k</code>. Each minute, you may take either the <strong>leftmost</strong> character of <code>s</code>, or the <strong>rightmost</strong> character of <code>s</code>.</p>
<p>Return<em> the <strong>minimum</strong> number of minutes needed for you to take <strong>at least</strong> </em><code>k</code><em> of each character, or return </em><code>-1</code><em> if it is not possible to take </em><code>k</code><em> of each character.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "aabaaaacaabc", k = 2
<strong>Output:</strong> 8
<strong>Explanation:</strong> 
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "a", k = 1
<strong>Output:</strong> -1
<strong>Explanation:</strong> It is not possible to take one 'b' or 'c' so return -1.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only the letters <code>'a'</code>, <code>'b'</code>, and <code>'c'</code>.</li>
	<li><code>0 &lt;= k &lt;= s.length</code></li>
</ul>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Merge Sorted Array (Easy)](https://leetcode.com/problems/merge-sorted-array/)
* [Reorder List (Medium)](https://leetcode.com/problems/reorder-list/)
* [Defuse the Bomb (Easy)](https://leetcode.com/problems/defuse-the-bomb/)

## Solution 1. Binary Answer

```cpp
// OJ: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int takeCharacters(string s, int k) {
        int N = s.size(), L = 3 * k, R = N;
        auto valid = [&](int len) {
            int cnt[3] = {};
            for (int i = 0; i < len; ++i) {
                cnt[s[i] - 'a']++;
            }
            for (int i = 0; i <= len; ++i) {
                if (i > 0) {
                    cnt[s[N - i] - 'a']++;
                    cnt[s[len - i] - 'a']--;
                }
                int j = 0;
                while (j < 3 && cnt[j] >= k) ++j;
                if (j == 3) return true;
            }
            return false;
        };
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L > N ? -1 : L;
    }
};
```

## Solution 2. Sliding Window

```cpp
// OJ: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        int N = s.size(), cnt[3] = {}, i = 0;
        auto valid = [&]() {
            int j = 0;
            while (j < 3 && cnt[j] >= k) ++j;
            return j == 3;
        };
        for (; i < N; ++i) {
            cnt[s[i] - 'a']++;
            if (valid()) break;
        }
        if (i == N) return -1;
        int ans = i + 1, j = N - 1;
        for (; i >= 0; --j) {
            cnt[s[j] - 'a']++;
            while (valid()) {
                ans = min(ans, N - j + i + 1);
                if (i >= 0) cnt[s[i--] - 'a']--;
                else break;
            }
        }
        return ans;
    }
};
```

## Solution 3. Find Maximum Sliding Window

```cpp
// OJ: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        int cnt[3] = {}, limits[3] = {}, N = s.size(), i = 0, j = 0;
        for (char c : s) limits[c - 'a']++;
        for (int i = 0; i < 3; ++i) {
            limits[i] -= k;
            if (limits[i] < 0) return -1;
        }
        auto valid = [&]() {
            int j = 0;
            while (j < 3 && cnt[j] <= limits[j]) ++j;
            return j == 3;
        };
        for (; j < N; ++j) {
            cnt[s[j] - 'a']++;
            if (!valid()) {
                cnt[s[i] - 'a']--;
                ++i;
            }
        }
        return N - j + i;
    }
};
```