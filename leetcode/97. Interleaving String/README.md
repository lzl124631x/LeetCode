# [97. Interleaving String (Hard)](https://leetcode.com/problems/interleaving-string/)

<p>Given <em>s1</em>, <em>s2</em>, <em>s3</em>, find whether <em>s3</em> is formed by the interleaving of <em>s1</em> and <em>s2</em>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "aabcc", s2 = "dbbca", <em>s3</em> = "aadbbcbcac"
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "aabcc", s2 = "dbbca", <em>s3</em> = "aadbbbaccc"
<strong>Output:</strong> false
</pre>


**Companies**:  
[Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/interleaving-string/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N^3)
class Solution {
private:
    string a, b, c;
    unordered_map<string, bool> m;
    string getKey(int a, int b, int c) {
        return to_string(a) + "-" + to_string(b) + "-" + to_string(c);
    }
    bool isInterleave(int x, int y, int z) {
        if (!x && !y && !z) return true;
        string key = getKey(x, y, z);
        if (m.find(key) != m.end()) return m[key];
        bool ans = false;
        if (x > 0 && a[x - 1] == c[z - 1]) ans = isInterleave(x - 1, y, z - 1);
        if (!ans && y > 0 && b[y - 1] == c[z - 1]) ans = isInterleave(x, y - 1, z - 1);
        return m[key] = ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        a = s1;
        b = s2;
        c = s3;
        return isInterleave(s1.size(), s2.size(), s3.size());
    }
};
```