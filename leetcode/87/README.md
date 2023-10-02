# [87. Scramble String (Hard)](https://leetcode.com/problems/scramble-string/)

<p>Given a string <em>s1</em>, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.</p>

<p>Below is one possible representation of <em>s1</em> = <code>"great"</code>:</p>

<pre>    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
</pre>

<p>To scramble the string, we may choose any non-leaf node and swap its two children.</p>

<p>For example, if we choose the node <code>"gr"</code> and swap its two children, it produces a scrambled string <code>"rgeat"</code>.</p>

<pre>    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
</pre>

<p>We say that <code>"rgeat"</code> is a scrambled string of <code>"great"</code>.</p>

<p>Similarly, if we continue to swap the children of nodes <code>"eat"</code> and <code>"at"</code>, it produces a scrambled string <code>"rgtae"</code>.</p>

<pre>    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
</pre>

<p>We say that <code>"rgtae"</code> is a scrambled string of <code>"great"</code>.</p>

<p>Given two strings <em>s1</em> and <em>s2</em> of the same length, determine if <em>s2</em> is a scrambled string of <em>s1</em>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "great", s2 = "rgeat"
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "abcde", s2 = "caebd"
<strong>Output:</strong> false</pre>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## TLE Solution

The basic idea is to try different split of `s1` and `s2`, and test whether the split parts are also scrambles.

```cpp
// OJ: https://leetcode.com/problems/scramble-string
// Author: github.com/lzl124631x
// Time: O(N^(N+1))
// Space: O(N^(N+1))
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        for (int i = 1; i < s1.size(); ++i) {
            string l1 = s1.substr(0, i), r1 = s1.substr(i);
            string l2 = s2.substr(0, i), r2 = s2.substr(i);
            string r2r = s2.substr(0, s1.size() - i), l2r = s2.substr(s1.size() - i);
            if ((isScramble(l1, l2) && isScramble(r1, r2))
               || (isScramble(l1, l2r) && isScramble(r1, r2r))) return true;
        }
        return false;
    }
};
```

## Solution 1.

The 2nd idea came to me was to save visited result to save computation. Time `~136 ms`.

```cpp
// OJ: https://leetcode.com/problems/scramble-string
// Author: github.com/lzl124631x
// Time: O(N^5)
// Space: O(N^5)
class Solution {
private:
    unordered_map<string, bool> m;
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        if (s1 > s2) swap(s1, s2);
        string key = s1 + "#" + s2;
        if (m.find(key) != m.end()) return m[key];
        bool ans = false;
        for (int i = 1; i < s1.size(); ++i) {
            string l1 = s1.substr(0, i), r1 = s1.substr(i);
            string l2 = s2.substr(0, i), r2 = s2.substr(i);
            string r2r = s2.substr(0, s1.size() - i), l2r = s2.substr(s1.size() - i);
            if ((isScramble(l1, l2) && isScramble(r1, r2))
               || (isScramble(l1, l2r) && isScramble(r1, r2r))) {
                ans = true;
                break;
            }
        }
        return m[key] = ans;
    }
};
```

## Solution 2

Saving string is not efficient. Try just saving indexes. Time `~20 ms`

```cpp
// OJ: https://leetcode.com/problems/scramble-string
// Author: github.com/lzl124631x
// Time: O(N^4)
// Space: O(N^4)
class Solution {
private:
    unordered_map<int, bool> m;
    string A, B;
    int getHash (int sa, int ea, int sb, int eb) {
        return sa + ea * 100 + sb * 10000 + eb * 1000000;
    }
    bool isScramble(int sa, int ea, int sb, int eb) {
        int M = ea - sa, N = eb - sb;
        if (M != N) return false;
        int key = getHash(sa, ea, sb, eb);
        if (m.find(key) != m.end()) return m[key];
        bool ans = false;
        if (!A.compare(sa, ea - sa, B, sb, eb - sb)) ans = true;
        else {
           for (int len = 1; len < M; ++len) {
                if ((isScramble(sa, sa + len, sb, sb + len) && isScramble(sa + len, ea, sb + len, eb))
                   || (isScramble(sa, sa + len, eb - len, eb) && isScramble(sa + len, ea, sb, eb - len))) {
                    ans = true;
                    break;
                }
            } 
        }
        return m[key] = ans;
    }
public:
    bool isScramble(string s1, string s2) {
        A = s1;
        B = s2;
        return isScramble(0, s1.size(), 0, s2.size());
    }
};
```

## Solution 3.

Another optimization is that, if the two strings are not anagram, we can directly return false. Time `4~8 ms`.

```cpp
// OJ: https://leetcode.com/problems/scramble-string
// Author: github.com/lzl124631x
// Time: O(N^4)
// Space: O(N^4)
class Solution {
private:
    unordered_map<int, bool> m;
    string A, B;
    int getHash (int sa, int ea, int sb, int eb) {
        return sa + ea * 100 + sb * 10000 + eb * 1000000;
    }
    bool isAnagram(int sa, int ea, int sb, int eb) {
        unordered_map<char, int> cnts;
        for (int i = 0, N = ea - sa; i < N; ++i) {
            cnts[A[sa + i]]++;
            cnts[B[sb + i]]--;
        }
        for (auto &p : cnts) {
            if (p.second) return false;
        }
        return true;
    }
    bool isScramble(int sa, int ea, int sb, int eb) {
        int M = ea - sa, N = eb - sb;
        if (M != N) return false;
        int key = getHash(sa, ea, sb, eb);
        if (m.find(key) != m.end()) return m[key];
        bool ans = false;
        if (!A.compare(sa, ea - sa, B, sb, eb - sb)) ans = true;
        else if (!isAnagram(sa, ea, sb, eb)) ans = false;
        else {
           for (int len = 1; len < M; ++len) {
                if ((isScramble(sa, sa + len, sb, sb + len) && isScramble(sa + len, ea, sb + len, eb))
                   || (isScramble(sa, sa + len, eb - len, eb) && isScramble(sa + len, ea, sb, eb - len))) {
                    ans = true;
                    break;
                }
            } 
        }
        return m[key] = ans;
    }
public:
    bool isScramble(string s1, string s2) {
        A = s1;
        B = s2;
        return isScramble(0, s1.size(), 0, s2.size());
    }
};
```

## Solution 4.

`areAnagram` is the most important optimization here because it can eliminate lots computation of sub-cases. Even without storing visited result, this optization is good to reduce the time to `4ms`.

```cpp
// OJ: https://leetcode.com/problems/scramble-string
// Author: github.com/lzl124631x
// Time: O(N^4)
// Space: O(N^4)
class Solution {
private:
    bool areAnagram(string &s1, string &s2) {
        unordered_map<char, int> m;
        for (int i = 0; i < s1.size(); ++i) {
            m[s1[i]]++;
            m[s2[i]]--;
        }
        for (auto &p : m) {
            if (p.second) return false;
        }
        return true;
    }
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        if (!areAnagram(s1, s2)) return false;
        for (int len = 1; len < s1.size(); ++len) {
            if ((isScramble(s1.substr(0, len), s2.substr(0, len))
                && isScramble(s1.substr(len), s2.substr(len)))
               || (isScramble(s1.substr(0, len), s2.substr(s2.size() - len))
                    && isScramble(s1.substr(len), s2.substr(0, s2.size() - len))))
                return true;
        }
        return false;
    }
};
```