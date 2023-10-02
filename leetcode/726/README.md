# [726. Number of Atoms (Hard)](https://leetcode.com/problems/number-of-atoms/)

<p>Given a chemical <code>formula</code> (given as a string), return the count of each atom.
</p><p>
An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.
</p><p>
1 or more digits representing the count of that element may follow if the count is greater than 1.  If the count is 1, no digits will follow.  For example, H2O and H2O2 are possible, but H1O2 is impossible.
</p><p>
Two formulas concatenated together produce another formula.  For example, H2O2He3Mg4 is also a formula.  
</p><p>
A formula placed in parentheses, and a count (optionally added) is also a formula.  For example, (H2O2) and (H2O2)3 are formulas.
</p><p>
Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 
formula = "H2O"
<b>Output:</b> "H2O"
<b>Explanation:</b> 
The count of elements are {'H': 2, 'O': 1}.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> 
formula = "Mg(OH)2"
<b>Output:</b> "H2MgO2"
<b>Explanation:</b> 
The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
</pre>
<p></p>

<p><b>Example 3:</b><br>
</p><pre><b>Input:</b> 
formula = "K4(ON(SO3)2)2"
<b>Output:</b> "K4N2O14S4"
<b>Explanation:</b> 
The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
</pre>
<p></p>

<p><b>Note:</b>
</p><li>All atom names consist of lowercase letters, except for the first character which is uppercase.</li>
<li>The length of <code>formula</code> will be in the range <code>[1, 1000]</code>.</li>
<li><code>formula</code> will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.</li>
<p></p>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Stack](https://leetcode.com/tag/stack/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Decode String (Medium)](https://leetcode.com/problems/decode-string/)
* [Encode String with Shortest Length (Hard)](https://leetcode.com/problems/encode-string-with-shortest-length/)
* [Parse Lisp Expression (Hard)](https://leetcode.com/problems/parse-lisp-expression/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-atoms/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    int N;
    int readNum(string &s, int &i) {
        int cnt = 0;
        while (i < N && isdigit(s[i])) cnt = cnt * 10 + (s[i++] - '0');
        return cnt ? cnt : 1;
    }
    map<string, int> dfs(string &s, int &i, bool isInParens = false) {
        map<string, int> m;
        if (isInParens) ++i;
        while (i < N && s[i] != ')') {
            if (s[i] == '(') {
                auto mm = dfs(s, i, true);
                for (auto &p : mm) m[p.first] += p.second;
            } else {
                string symbol = string(1, s[i++]);
                while (i < N && islower(s[i])) symbol += s[i++];
                m[symbol] += readNum(s, i);
            }
        }
        if (isInParens) {
            ++i;
            int cnt = readNum(s, i);
            for (auto &p : m) p.second *= cnt;
        }
        return m;
    }
public:
    string countOfAtoms(string formula) {
        N = formula.size();
        int i = 0;
        auto m = dfs(formula, i);
        string ans;
        for (auto &p : m) ans += p.first + (p.second > 1 ? to_string(p.second) : "");
        return ans;
    }
};
```