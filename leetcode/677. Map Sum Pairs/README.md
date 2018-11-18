# [677. Map Sum Pairs (Medium)](https://leetcode.com/problems/map-sum-pairs/)

<p>
Implement a MapSum class with <code>insert</code>, and <code>sum</code> methods.
</p>

<p>
For the method <code>insert</code>, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.
</p>

<p>
For the method <code>sum</code>, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.
</p>

<p><b>Example 1:</b><br>
</p><pre>Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
</pre>
<p></p>


## Solution 1. map

```cpp
// OJ: https://leetcode.com/problems/map-sum-pairs/
// Author: github.com/lzl124631x
// Time:
//     * insert: O(logN)
//     * sum: O(NW) where W is word length
// Space: O(N)
class MapSum {
private:
    map<string, int> m;
public:
    MapSum() { }
    
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

## Solution 2. Trie

```cpp
// OJ: https://leetcode.com/problems/map-sum-pairs/
// Author: github.com/lzl124631x
// Time:
//     * insert: O(W) where W is word length
//     * sum: O(W)
// Space: O(NW)
class TrieNode {
public:
    unordered_map<char, TrieNode*> m;
    int count = 0;
};

class MapSum {
private:
    TrieNode root;
    unordered_map<string, int> m;
public:
    MapSum() {}
    
    void insert(string key, int val) {
        int delta = val - m[key];
        m[key] = val;
        TrieNode *node = &root;
        for (char c : key) {
            if (!node->m[c]) node->m[c] = new TrieNode();
            node = node->m[c];
            node->count += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode *node = &root;
        for (char c : prefix) {
            node = node->m[c];
            if (!node) return 0;
        }
        return node->count;
    }
};
```