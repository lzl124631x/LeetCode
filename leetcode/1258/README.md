# [1258. Synonymous Sentences (Medium)](https://leetcode.com/problems/synonymous-sentences/)

<p>You are given a list of equivalent string pairs <code>synonyms</code> where <code>synonyms[i] = [s<sub>i</sub>, t<sub>i</sub>]</code> indicates that <code>s<sub>i</sub></code> and <code>t<sub>i</sub></code> are equivalent strings. You are also given a sentence <code>text</code>.</p>

<p>Return <em>all possible synonymous sentences <strong>sorted lexicographically</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> synonyms = [["happy","joy"],["sad","sorrow"],["joy","cheerful"]], text = "I am happy today but was sad yesterday"
<strong>Output:</strong> ["I am cheerful today but was sad yesterday","I am cheerful today but was sorrow yesterday","I am happy today but was sad yesterday","I am happy today but was sorrow yesterday","I am joy today but was sad yesterday","I am joy today but was sorrow yesterday"]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> synonyms = [["happy","joy"],["cheerful","glad"]], text = "I am happy today but was sad yesterday"
<strong>Output:</strong> ["I am happy today but was sad yesterday","I am joy today but was sad yesterday"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= synonyms.length &lt;= 10</code></li>
	<li><code>synonyms[i].length == 2</code></li>
	<li><code>1 &lt;= s<sub>i</sub>.length,<sub> </sub>t<sub>i</sub>.length &lt;= 10</code></li>
	<li><code>s<sub>i</sub> != t<sub>i</sub></code></li>
	<li><code>text</code> consists of at most <code>10</code> words.</li>
	<li>The words of <code>text</code> are separated by single spaces.</li>
</ul>


**Companies**:  
[Cruise Automation](https://leetcode.com/company/cruise-automation)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/), [Union Find](https://leetcode.com/tag/union-find/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/synonymous-sentences/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class UnionFind {
    vector<int> id;
public:
    UnionFind(int N) : id(N) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
};
class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& A, string s) {
        istringstream ss(s);
        string word;
        vector<string> v, tmp, ans;
        while (ss >> word) v.push_back(word);
        int id = 0;
        unordered_map<string, int> index;
        unordered_map<int, string> rindex;
        for (auto &syn : A) {
            if (index.count(syn[0]) == 0) {
                index[syn[0]] = id;
                rindex[id] = syn[0];
                ++id;
            }
            if (index.count(syn[1]) == 0) {
                index[syn[1]] = id;
                rindex[id] = syn[1];
                ++id;
            }
        }
        UnionFind uf(index.size());
        for (auto &syn : A) {
            uf.connect(index[syn[0]], index[syn[1]]);
        }
        unordered_map<int, set<string>> m;
        for (int i = 0; i < index.size(); ++i) {
            m[uf.find(i)].insert(rindex[i]);
        }
        function<void(int)> dfs = [&](int i) {
            if (i == v.size()) {
                string t;
                for (auto &w : tmp) {
                    if (t.size()) t += ' ';
                    t += w;
                }
                ans.push_back(t);
                return;
            }
            if (index.count(v[i])) {
                for (auto &syn : m[uf.find(index[v[i]])]) {
                    tmp.push_back(syn);
                    dfs(i + 1);
                    tmp.pop_back();
                } 
            } else {
                tmp.push_back(v[i]);
                dfs(i + 1);
                tmp.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
```

## TODO

Too lengthy. Find better solution.