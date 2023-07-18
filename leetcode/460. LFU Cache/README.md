# [460. LFU Cache (Hard)](https://leetcode.com/problems/lfu-cache)

<p>Design and implement a data structure for a <a href="https://en.wikipedia.org/wiki/Least_frequently_used" target="_blank">Least Frequently Used (LFU)</a> cache.</p>
<p>Implement the <code>LFUCache</code> class:</p>
<ul>
	<li><code>LFUCache(int capacity)</code> Initializes the object with the <code>capacity</code> of the data structure.</li>
	<li><code>int get(int key)</code> Gets the value of the <code>key</code> if the <code>key</code> exists in the cache. Otherwise, returns <code>-1</code>.</li>
	<li><code>void put(int key, int value)</code> Update the value of the <code>key</code> if present, or inserts the <code>key</code> if not already present. When the cache reaches its <code>capacity</code>, it should invalidate and remove the <strong>least frequently used</strong> key before inserting a new item. For this problem, when there is a <strong>tie</strong> (i.e., two or more keys with the same frequency), the <strong>least recently used</strong> <code>key</code> would be invalidated.</li>
</ul>
<p>To determine the least frequently used key, a <strong>use counter</strong> is maintained for each key in the cache. The key with the smallest <strong>use counter</strong> is the least frequently used key.</p>
<p>When a key is first inserted into the cache, its <strong>use counter</strong> is set to <code>1</code> (due to the <code>put</code> operation). The <strong>use counter</strong> for a key in the cache is incremented either a <code>get</code> or <code>put</code> operation is called on it.</p>
<p>The functions&nbsp;<code data-stringify-type="code">get</code>&nbsp;and&nbsp;<code data-stringify-type="code">put</code>&nbsp;must each run in <code>O(1)</code> average time complexity.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input</strong>
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
<strong>Output</strong>
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

<strong>Explanation</strong>
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
&nbsp;                // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= capacity&nbsp;&lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= key &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= value &lt;= 10<sup>9</sup></code></li>
	<li>At most <code>2 * 10<sup>5</sup></code>&nbsp;calls will be made to <code>get</code> and <code>put</code>.</li>
</ul>
<p>&nbsp;</p>
<span style="display: none;">&nbsp;</span>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Linked List](https://leetcode.com/tag/linked-list/), [Design](https://leetcode.com/tag/design/), [Doubly-Linked List](https://leetcode.com/tag/doubly-linked-list/)

**Similar Questions**:
* [LRU Cache (Medium)](https://leetcode.com/problems/lru-cache/)
* [Design In-Memory File System (Hard)](https://leetcode.com/problems/design-in-memory-file-system/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/lfu-cache
// Author: github.com/lzl124631x
// Time:
//      LFUCache: O(1)
//      get: O(logF) where F is the maximum of unique frequencies
//      put: O(logF)
// Space: O(N)
class LFUCache {
    int capacity, cnt = 0;
    map<int, list<int>> data; // freq -> entries. The least recently used is at the front
    unordered_map<int, list<int>::iterator> m;
    unordered_map<int, int> vals, freq;
public:
    LFUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (!m.count(key)) return -1;
        int f = freq[key];
        data[f].erase(m[key]);
        if (data[f].empty()) data.erase(f);
        data[f + 1].push_front(key);
        m[key] = data[f + 1].begin();
        freq[key]++;
        return vals[key];
    }
    
    void put(int key, int value) {
        if (get(key) == -1) {
            ++cnt;
            if (cnt > capacity) {
                int f = data.begin()->first;
                int rm = data[f].back();
                data[f].pop_back();
                m.erase(rm);
                freq.erase(rm);
                vals.erase(rm);
                --cnt;
            }
            freq[key] = 1;
            data[1].push_front(key);
            m[key] = data[1].begin();
            vals[key] = value;
        } else vals[key] = value;
    }
};
```