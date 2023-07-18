# [146. LRU Cache (Medium)](https://leetcode.com/problems/lru-cache)

<p>Design a data structure that follows the constraints of a <strong><a href="https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU" target="_blank">Least Recently Used (LRU) cache</a></strong>.</p>
<p>Implement the <code>LRUCache</code> class:</p>
<ul>
	<li><code>LRUCache(int capacity)</code> Initialize the LRU cache with <strong>positive</strong> size <code>capacity</code>.</li>
	<li><code>int get(int key)</code> Return the value of the <code>key</code> if the key exists, otherwise return <code>-1</code>.</li>
	<li><code>void put(int key, int value)</code> Update the value of the <code>key</code> if the <code>key</code> exists. Otherwise, add the <code>key-value</code> pair to the cache. If the number of keys exceeds the <code>capacity</code> from this operation, <strong>evict</strong> the least recently used key.</li>
</ul>
<p>The functions <code>get</code> and <code>put</code> must each run in <code>O(1)</code> average time complexity.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input</strong>
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
<strong>Output</strong>
[null, null, null, 1, null, -1, null, -1, 3, 4]

<strong>Explanation</strong>
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= capacity &lt;= 3000</code></li>
	<li><code>0 &lt;= key &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= value &lt;= 10<sup>5</sup></code></li>
	<li>At most <code>2 * 10<sup>5</sup></code> calls will be made to <code>get</code> and <code>put</code>.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [TikTok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Linked List](https://leetcode.com/tag/linked-list/), [Design](https://leetcode.com/tag/design/), [Doubly-Linked List](https://leetcode.com/tag/doubly-linked-list/)

**Similar Questions**:
* [LFU Cache (Hard)](https://leetcode.com/problems/lfu-cache/)
* [Design In-Memory File System (Hard)](https://leetcode.com/problems/design-in-memory-file-system/)
* [Design Compressed String Iterator (Easy)](https://leetcode.com/problems/design-compressed-string-iterator/)
* [Design Most Recently Used Queue (Medium)](https://leetcode.com/problems/design-most-recently-used-queue/)


## Note

I usually forgot that I need to store the `<key, value>` pair in the list which is needed when evicting least recently used item.

We'd better write the logic as comments first, then we can find the detailed data structure we need and see if there is any common utility function that we can extract. 

Need to remember the signature of the `splice` function: `toList.splice(toListIterator, fromList, fromListIterator)` is moving the data pointed by the `fromListIterator` from the `fromList` into the position pointed by the `toListIterator` within the `toList`.

## Solution 1.

Use a `list<pair<int, int>> data` to store the key-value pairs, `unordered_map<int, list<pair<int, int>>::iterator> m` to store the mapping from **key** to **the corresponding iterator pointing into data**.

The constructor `LRUCache` is trivial, just storing the `capacity` as member.

The `get` logic is:
* If the `key` cannot be found in `m`, return `-1`.
* Otherwise, move the key-value pair pointed by `m[key]` to the front of `data`. And update `m[key]` to point to the front of `data`. Return the value `data.front().second`.

The `put` logic is:
* Use `get(key)` to test the existance of the `key`.
  * If not found,
    - Emit the last key-value pair, if the `data` storage is full.
    - Then insert the key-value pair to the front of `data` and update `m[key]` accordingly.
  * Otherwise, just update `data.front().second` to be `value`. 

```cpp
// OJ: https://leetcode.com/problems/lru-cache
// Author: github.com/lzl124631x
// Time:
//    LRUCache: O(1)
//    get: O(1)
//    put: O(1)
// Space: O(N)
class LRUCache {
    int capacity;
    typedef pair<int, int> Node;
    list<Node> data;
    typedef list<Node>::iterator Iterator;
    unordered_map<int, Iterator> m;
    void moveToFront(int key) {
        auto node = m[key];
        data.splice(data.begin(), data, node);
        m[key] = data.begin();
    }
public:
    LRUCache(int capacity) : capacity(capacity) {}
    int get(int key) {
        // get node given key, put the node at the beginning of the list, return the value in the node
        if (m.count(key)) {
            moveToFront(key);
            return m[key]->second;
        }
        return -1;
    }
    void put(int key, int value) {
        // if key exists in the map, get node given key, put the node at the beginning of the list and update the value in the node
        // otherwise, put a new node at the beginning of the list with the <key, value> and update the map. If capacity exceeded, remove the last node from the list and map.
        if (m.count(key)) {
            moveToFront(key);
            m[key]->second = value;
        } else {
            data.emplace_front(key, value);
            m[key] = data.begin();
            if (data.size() > capacity) {
                m.erase(data.back().first);
                data.pop_back();
            }
        }
    }
};
```

We can also leverage `get` in `put`

```cpp
// OJ: https://leetcode.com/problems/lru-cache
// Author: github.com/lzl124631x
// Time:
//    LRUCache: O(1)
//    get: O(1)
//    put: O(1)
// Space: O(N)
class LRUCache {
    int capacity;
    typedef pair<int, int> Node;
    list<Node> data;
    typedef list<Node>::iterator Iterator;
    unordered_map<int, Iterator> m;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    int get(int key) {
        if (m.count(key)) {
            auto node = m[key];
            data.splice(data.begin(), data, node);
            m[key] = data.begin();
            return node->second;
        }
        return -1;
    }
    void put(int key, int value) {
        if (get(key) == -1) {
            data.emplace_front(key, value);
            m[key] = data.begin();
            if (data.size() > capacity) {
                m.erase(data.back().first);
                data.pop_back();
            }
        } else data.front().second = value;
    }
};
```