# [1371. Find the Longest Substring Containing Vowels in Even Counts (Medium)](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)

<p>Given the string <code>s</code>, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "eleetminicoworoep"
<strong>Output:</strong> 13
<strong>Explanation: </strong>The longest substring is "leetminicowor" which contains two each of the vowels: <strong>e</strong>, <strong>i</strong> and <strong>o</strong> and zero of the vowels: <strong>a</strong> and <strong>u</strong>.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "leetcodeisgreat"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The longest substring is "leetc" which contains two e's.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "bcbcbc"
<strong>Output:</strong> 6
<strong>Explanation:</strong> In this case, the given string "bcbcbc" is the longest because all vowels: <strong>a</strong>, <strong>e</strong>, <strong>i</strong>, <strong>o</strong> and <strong>u</strong> appear zero times.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 x 10^5</code></li>
	<li><code>s</code>&nbsp;contains only lowercase English letters.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

## Solution 1. Bitmask + Prefix State Map

At the first glance it's like a sliding window problem. For a find maximum sliding window problem, the initial state should be valid, then keep extending the 2nd pointer until the state becomes invalid (now the maximum is found), then move the first pointer to get back the valid state again.

In this problem, the initial state is valid. When extending the 2nd pointer, the state might jump back and forth between invalid and valid before reaching the longest valid end position. So we shouldn't use sliding window to solve this problem.

Try to get the intuition by simplying the problem -- what if we only consider `a` as vowel?

```
    4    9   13  17
    v    v   v   v
xxxxaxxxxaxxxaxxxaxxx
    ~
         -1
             4
                 -1        
```


Consider the above input.

For `i = 0 ~ 3`, `0` `a` has been visited, substring `s[0..i]` is valid.

For `i = 4 ~ 8`, `1` `a` has been visited, substring `s[5..i]` is valid.

For `i = 9 ~ 12`, `2` `a`s have been visited, substring `s[0..i]` is valid.

For `i = 13 ~ 16`, `3` `a`s have been visited, substring `s[5..i]` is valid.

For `i = 17 ~ (N - 1)`, `4` `a`s have been visited, substring `s[0..i]` is valid.

So we can see there can be a greedy solution:

* If we've visited **even** number of `a`, substring `s[0..i]` is valid which has length `i + 1`.
* If we've visited **odd** number of `a`, substring `s[(k+1)..i]` is valid where `k` is the first index of the first occurrence of `a`. The length is `i - k`.

We can regard **even** and **odd** are two different states, then the above two cases can be unified into one:

* If we are in state `x` at index `i`, find the index of the first occurrence of the same state `x`, say `k`, then `i - k` is the length of the longest valid string ending at `i`.

Note that we need to regard `-1` as the index of the first occurrence of **even** state.

Now we consider the 5 vowels. Each vowel has two different states, **even** and **odd**. So in total there are `2^5` different states. We can use bitmask to encode the state.

For example, if the state of `aeiou` are even, even, odd, odd, even respectively, we can encode the state as `00110`.

Let `index` be a map from state `x` to the index of the first occurrence of state `x`.

For each index `i`, we get the corresponding state `mask` of `s[i]` first, then:
* If we've seen this state, then try to update the answer using `i - index[mask]`.
* Otherwise, `index[mask] = i`.

```cpp
// OJ: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int h = 0, ans = 0;
        unordered_map<int, int> m{{'a',0},{'e',1},{'i',2},{'o',3},{'u',4}}, index{{0,-1}};
        for (int i = 0; i < s.size(); ++i) {
            if (m.count(s[i])) h ^= 1 << m[s[i]];
            if (index.count(h)) ans = max(ans, i - index[h]);
            else index[h] = i;
        }
        return ans;
    }
};
```