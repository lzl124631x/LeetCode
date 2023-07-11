# [737. Sentence Similarity II (Medium)](https://leetcode.com/problems/sentence-similarity-ii)

<p>We can represent a sentence as an array of words, for example, the sentence <code>"I am happy with leetcode"</code> can be represented as <code>arr = ["I","am",happy","with","leetcode"]</code>.</p>
<p>Given two sentences <code>sentence1</code> and <code>sentence2</code> each represented as a string array and given an array of string pairs <code>similarPairs</code> where <code>similarPairs[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> indicates that the two words <code>x<sub>i</sub></code> and <code>y<sub>i</sub></code> are similar.</p>
<p>Return <code>true</code><em> if <code>sentence1</code> and <code>sentence2</code> are similar, or </em><code>false</code><em> if they are not similar</em>.</p>
<p>Two sentences are similar if:</p>
<ul>
	<li>They have <strong>the same length</strong> (i.e., the same number of words)</li>
	<li><code>sentence1[i]</code> and <code>sentence2[i]</code> are similar.</li>
</ul>
<p>Notice that a word is always similar to itself, also notice that the similarity relation is transitive. For example, if the words <code>a</code> and <code>b</code> are similar, and the words <code>b</code> and <code>c</code> are similar, then&nbsp;<code>a</code> and <code>c</code> are <strong>similar</strong>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> sentence1 = ["great","acting","skills"], sentence2 = ["fine","drama","talent"], similarPairs = [["great","good"],["fine","good"],["drama","acting"],["skills","talent"]]
<strong>Output:</strong> true
<strong>Explanation:</strong> The two sentences have the same length and each word i of sentence1 is also similar to the corresponding word in sentence2.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","onepiece"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
<strong>Output:</strong> true
<strong>Explanation:</strong> "leetcode" --&gt; "platform" --&gt; "anime" --&gt; "manga" --&gt; "onepiece".
Since "leetcode is similar to "onepiece" and the first two words are the same, the two sentences are similar.</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","hunterXhunter"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
<strong>Output:</strong> false
<strong>Explanation:</strong> "leetcode" is not similar to "onepiece".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= sentence1.length, sentence2.length &lt;= 1000</code></li>
	<li><code>1 &lt;= sentence1[i].length, sentence2[i].length &lt;= 20</code></li>
	<li><code>sentence1[i]</code> and <code>sentence2[i]</code> consist of lower-case and upper-case English letters.</li>
	<li><code>0 &lt;= similarPairs.length &lt;= 2000</code></li>
	<li><code>similarPairs[i].length == 2</code></li>
	<li><code>1 &lt;= x<sub>i</sub>.length, y<sub>i</sub>.length &lt;= 20</code></li>
	<li><code>x<sub>i</sub></code> and <code>y<sub>i</sub></code> consist of English letters.</li>
</ul>

**Companies**:
[Uber](https://leetcode.com/company/uber), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/)

**Similar Questions**:
* [Number of Provinces (Medium)](https://leetcode.com/problems/number-of-provinces/)
* [Accounts Merge (Medium)](https://leetcode.com/problems/accounts-merge/)
* [Sentence Similarity (Easy)](https://leetcode.com/problems/sentence-similarity/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/sentence-similarity-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& A, vector<string>& B, vector<vector<string>>& P) {
        if (A.size() != B.size()) return false;
        unordered_map<string, int> id;
        int index = 0;
        for (auto &s : A) {
            if (id.count(s) == 0) id[s] = index++;
        }
        for (auto &s : B) {
            if (id.count(s) == 0) id[s] = index++;
        }
        UnionFind uf(index);
        for (auto &v : P) uf.connect(id[v[0]], id[v[1]]);
        for (int i = 0; i < A.size(); ++i) {
            if (!uf.connected(id[A[i]], id[B[i]])) return false;
        }
        return true;
    }
};
```