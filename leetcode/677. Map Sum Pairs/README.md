# [677. Map Sum Pairs (Medium)](https://leetcode.com/problems/map-sum-pairs/)

<p>Implement the <code>MapSum</code> class:</p>

<ul>
	<li><code>MapSum()</code> Initializes the&nbsp;<code>MapSum</code> object.</li>
	<li><code>void insert(String key, int val)</code> Inserts the <code>key-val</code> pair into the map. If the <code>key</code> already existed, the original <code>key-value</code> pair will be overridden to the new one.</li>
	<li><code>int sum(string prefix)</code> Returns&nbsp;the sum of all the pairs' value whose <code>key</code> starts with the <code>prefix</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
<strong>Output</strong>
[null, null, 3, null, 5]

<strong>Explanation</strong>
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (<u>ap</u>ple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (<u>ap</u>ple + <u>ap</u>p = 3 + 2 = 5)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= key.length, prefix.length &lt;= 50</code></li>
	<li><code>key</code> and <code>prefix</code> consist of only lowercase English letters.</li>
	<li><code>1 &lt;= val &lt;= 1000</code></li>
	<li>At most <code>50</code> calls will be made to <code>insert</code> and <code>sum</code>.</li>
</ul>


**Companies**:  
[Akuna Capital](https://leetcode.com/company/akuna-capital)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Design](https://leetcode.com/tag/design/), [Trie](https://leetcode.com/tag/trie/)

## Solution 1. Map

```cpp
// OJ: https://leetcode.com/problems/map-sum-pairs/
// Author: github.com/lzl124631x
// Time:
//      MapSum: O(1)
//      insert: O(WlogN) where W is word length
//      sum: O(NW)
// Space: O(NW)
class MapSum {
private:
    map<string, int> m;
public:
    MapSum() {}
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0;
        for (auto start = m.lower_bound(prefix); start != m.end(); ++start) {
            if (start->first.compare(0, prefix.size(), prefix) != 0) break;
            sum += start->second;
        }
        return sum;
    }
};
```

## Solution 2. Trie + Unordered Map

```cpp
// OJ: https://leetcode.com/problems/map-sum-pairs/
// Author: github.com/lzl124631x
// Time:
//      MapSum: O(1)
//      insert: O(W) where W is word length
//      sum: O(W)
// Space: O(NW)
struct TrieNode {
    TrieNode *next[26] = {};
    int sum = 0;
};
class MapSum {
    TrieNode root;
    unordered_map<string, int> m;
public:
    MapSum() {}
    
    void insert(string key, int val) {
        int diff = val;
        if (m.count(key)) diff = val - m[key];
        m[key] = val;
        auto node = &root;
        for (char c : key) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
            node->sum += diff;
        }
    }
    
    int sum(string prefix) {
        auto node = &root;
        for (char c : prefix) {
            node = node->next[c - 'a'];
            if (!node) return 0;
        }
        return node->sum;
    }
};

```