# [1520. Maximum Number of Non-Overlapping Substrings (Hard)](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings)

<p>Given a string <code>s</code> of lowercase letters, you need to find the maximum number of <strong>non-empty</strong> substrings of <code>s</code> that meet the following conditions:</p>
<ol>
	<li>The substrings do not overlap, that is for any two substrings <code>s[i..j]</code> and <code>s[x..y]</code>, either <code>j &lt; x</code> or <code>i &gt; y</code> is true.</li>
	<li>A substring that contains a certain character <code>c</code> must also contain all occurrences of <code>c</code>.</li>
</ol>
<p>Find <em>the maximum number of substrings that meet the above conditions</em>. If there are multiple solutions with the same number of substrings, <em>return the one with minimum total length. </em>It can be shown that there exists a unique solution of minimum total length.</p>
<p>Notice that you can return the substrings in <strong>any</strong> order.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "adefaddaccc"
<strong>Output:</strong> ["e","f","ccc"]
<b>Explanation:</b>&nbsp;The following are all the possible substrings that meet the conditions:
[
&nbsp; "adefaddaccc"
&nbsp; "adefadda",
&nbsp; "ef",
&nbsp; "e",
  "f",
&nbsp; "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abbaccd"
<strong>Output:</strong> ["d","bb","cc"]
<b>Explanation: </b>Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Maximum Number of Non-overlapping Palindrome Substrings (Hard)](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/)

## Solution 1. DP

For `s[0..i]`, assume `S(i+1)` is the optimal substring set satisfying those conditions.

Let `dp[i+1]` be the length of `S(i+1)`, `len[i+1]` be the sum of lengths of substrings in `S(i+1)`, `pick[i+1]` be the character we pick to get the optimal solution `S(i+1)`.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int N = s.size();
        vector<int> left(26, -1), right(26, -1); // the range of each character
        for (int i = 0; i < N; ++i) {
            int c = s[i] - 'a';
            if (left[c] == -1) left[c] = i;
            right[c] = i;
        }
        for (int i = 0; i < 26; ++i) { // An inefficient way of generating the ranges satisfying condition 2.
            if (left[i] == -1) continue;
            for (int j = left[i] + 1; j < right[i]; ++j) {
                int L = left[s[j] - 'a'], R = right[s[j] - 'a'];
                if (L < left[i]) j = L; // rewind
                left[i] = min(left[i], L);
                right[i] = max(right[i], R);
            }
        }
        vector<int> dp(N + 1), pick(N + 1, -1), len(N + 1, N + 1);
        for (int i = 0; i < N; ++i) {
            len[i + 1] = len[i];
            pick[i + 1] = pick[i];
            dp[i + 1] = dp[i];
            int j = 0;
            for (; j < 26; ++j) {
                if (right[j] == i) break;
            }
            if (j == 26 || dp[left[j]] + 1 < dp[i + 1]) continue;
            if (dp[left[j]] + 1 > dp[i + 1] || len[left[j]] + right[j] - left[j] + 1 < len[i]) {
                len[i + 1] = len[left[j]] + right[j] - left[j] + 1; // find a better choice, update the choice.
                pick[i + 1] = j;
            }
            dp[i + 1] = max(dp[i + 1], dp[left[j]] + 1);
        }
        vector<string> ans;
        for (int p = pick[N]; p != -1;) { // reconstruct the substrings.
            int L = left[p], R = right[p];
            ans.push_back(s.substr(L, R - L + 1));
            p = pick[L];
        }
        return ans;
    }
};
```
## Solution 2. Greedy

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/discuss/743223/C%2B%2BJava-Greedy-O(n)
class Solution {
    int getRightEdge(string &s, int i, vector<int> &left, vector<int> &right) { // get the corresponding right edge of `s[i]`
        int R = right[s[i] - 'a'];
        for (int j = i; j <= R; ++j) {
            if (left[s[j] - 'a'] < i) return -1; // If this range extends leftwards, it must be handled before and should be skipped.
            R = max(R, right[s[j] - 'a']);
        }
        return R;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        int N = s.size();
        vector<int> left(26, -1), right(26, -1); // The range of the character
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            if (left[c] == -1) left[c] = i;
            right[c] = i;
        }
        int R = -1;
        vector<string> ans;
        for (int i = 0; i < N; ++i) {
            int nextR = getRightEdge(s, i, left, right);
            if (nextR == -1) continue;
            if (i > R) ans.push_back(""); // If this substring doesn't overlap with the previous substring, push new item instead of updating the previous one.
            R = nextR;
            ans.back() = s.substr(i, R - i + 1);
        }
        return ans;
    }
};
```

## Solution 3. Interval Scheduling Maximization Problem (ISMP)

First get the covering ranges of all the characters in `s`. There are at most 26 ranges.

Then the problem becomes a classic problem -- finding the maximum set of non-overlapping intervals, aka, Interval Scheduling Maximization Problem.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/discuss/744420/C%2B%2BJavaPython-Interval-Scheduling-Maximization-(ISMP)
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int N = s.size();
        vector<int> left(26, -1), right(26, -1);
        for (int i = 0; i < N; ++i) {
            int c = s[i] - 'a';
            if (left[c] == -1) left[c] = i;
            right[c] = i;
        }
        vector<pair<int, int>> ranges; // last, first
        for (int i = 0; i < 26; ++i) {
            if (left[i] == -1) continue;
            int first = left[i], last = right[i];
            for (int j = first; j <= last && first == left[i]; ++j) { // If `first != left[i]`, this character is not the representative of its covering range. The representative character is the first character of that range.
                first = min(first, left[s[j] - 'a']);
                last = max(last, right[s[j] - 'a']);
            }
            if (first == left[i]) ranges.emplace_back(last, first); // Only push representative ranges.
        }
        sort(begin(ranges), end(ranges)); // Greedily pick the interval ends first.
        int end = -1;
        vector<string> ans;
        for (auto &[last, first] : ranges) {
            if (first <= end) continue; // If this range overlaps with the previously picked range, skip.
            ans.push_back(s.substr(first, last - first + 1));
            end = last;
        }
        return ans;
    }
};
```

## Note

Lesson learned: During the context I came up with similar idea but I was stuck at generating the smallest covering range of each character. When scaning within `left[i], right[i]` range for `'a' + i`, if we extend the left edge due to another character range, we need to restart the scanning from the newly extended left edge. This is not efficient but it DOES work because we at most restart 25 times.

In the above solutions, instead of generating 26 intervals, they just generate representative intervals using the starting character to ensure the uniqueness of the intervals.