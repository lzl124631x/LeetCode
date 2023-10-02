# [1096. Brace Expansion II (Hard)](https://leetcode.com/problems/brace-expansion-ii/)

<p>Under a grammar given below, strings can represent a set of lowercase words.&nbsp; Let's&nbsp;use <code>R(expr)</code>&nbsp;to denote the <strong>set</strong> of words the expression represents.</p>

<p>Grammar can best be understood through simple examples:</p>

<ul>
	<li>Single letters represent a singleton set containing that word.
	<ul>
		<li><code>R("a") = {"a"}</code></li>
		<li><code>R("w") = {"w"}</code></li>
	</ul>
	</li>
	<li>When we take a comma delimited list of 2 or more expressions, we take the union of possibilities.
	<ul>
		<li><code>R("{a,b,c}") = {"a","b","c"}</code></li>
		<li><code>R("{{a,b},{b,c}}") = {"a","b","c"}</code>&nbsp;(notice the final set only contains each word at most once)</li>
	</ul>
	</li>
	<li>When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
	<ul>
		<li><code>R("{a,b}{c,d}") = {"ac","ad","bc","bd"}</code></li>
		<li><code>R("a{b,c}{d,e}f{g,h}")&nbsp;= {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}</code></li>
	</ul>
	</li>
</ul>

<p>Formally, the 3 rules for our grammar:</p>

<ul>
	<li>For every lowercase letter <code>x</code>, we have <code>R(x) = {x}</code></li>
	<li>For expressions <code>e_1, e_2, ... , e_k</code>&nbsp;with <code>k &gt;= 2</code>, we have <code>R({e_1,e_2,...}) = R(e_1)&nbsp;∪ R(e_2)&nbsp;∪ ...</code></li>
	<li>For&nbsp;expressions <code>e_1</code> and <code>e_2</code>, we have <code>R(e_1 + e_2) = {a + b for (a, b) in&nbsp;R(e_1)&nbsp;× R(e_2)}</code>, where + denotes concatenation, and × denotes the cartesian product.</li>
</ul>

<p>Given an <code>expression</code> representing a set of words under the given grammar, return the&nbsp;sorted list of words that the expression represents.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"{a,b}{c,{d,e}}"</span>
<strong>Output: </strong><span id="example-output-1">["ac","ad","ae","bc","bd","be"]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span>"{{a,z},a{b,c},{ab,z}}"</span>
<strong>Output: </strong><span>["a","ab","ac","z"]</span>
<strong>Explanation: </strong>Each distinct word is written only once in the final answer.
</pre>

<p>&nbsp;</p>

<p><strong>Constraints:</strong></p>

<ol>
	<li><code>1 &lt;= expression.length &lt;= 60</code></li>
	<li><code>expression[i]</code> consists of <code>'{'</code>, <code>'}'</code>, <code>','</code>or lowercase English letters.</li>
	<li>The given&nbsp;<code>expression</code>&nbsp;represents a set of words based on the grammar given in the description.</li>
</ol>
</div>
</div>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Brace Expansion (Medium)](https://leetcode.com/problems/brace-expansion/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/brace-expansion-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    int i = 0, N;
    unordered_set<string> handleList(string &s) {
        ++i; // {
        unordered_set<string> ans;
        while (s[i] != '}') {
            auto st = dfs(s);
            for (auto &a : st)
                ans.insert(a);
            if (s[i] == ',') ++i;
        }
        ++i; // }
        return ans;
    }
    unordered_set<string> dfs(string &s) {
        unordered_set<string> ans{ "" };
        while (i < N && s[i] != ',' && s[i] != '}') {
            unordered_set<string> tmp;
            if (s[i] != '{') {
                string str;
                while (i < N && isalpha(s[i])) str += s[i++];
                for (auto &a : ans) tmp.insert(a + str); 
            } else {
                auto st = handleList(s);
                for (auto &a : ans) 
                    for (auto &b : st)
                        tmp.insert(a + b); 
            }
            swap(tmp, ans);
        }
        return ans;
    }
public:
    vector<string> braceExpansionII(string s) {
        N = s.size();
        auto st = dfs(s);
        vector<string> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/brace-expansion-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    int i = 0;
    vector<string> handleList(string &s) {
        ++i; // {
        vector<string> ans;
        while (s[i] != '}') {
            auto st = dfs(s);
            for (auto &a : st)
                ans.push_back(a);
            if (s[i] == ',') ++i;
        }
        ++i; // }
        return ans;
    }
    vector<string> dfs(string &s) {
        vector<string> ans{ "" };
        while (i < s.size() && s[i] != ',' && s[i] != '}') {
            if (s[i] != '{') {
                for (auto &a : ans) a += s[i]; 
                ++i;
            } else {
                auto list = handleList(s);
                vector<string> tmp;
                for (auto &a : ans) 
                    for (auto &b : list)
                        tmp.push_back(a + b); 
                swap(tmp, ans);
            }
        }
        return ans;
    }
public:
    vector<string> braceExpansionII(string s) {
        auto st = dfs(s);
        vector<string> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
```