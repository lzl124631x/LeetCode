# [146. LRU Cache (Hard)](https://leetcode.com/problems/lru-cache)

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

`get(key)` - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.

`put(key, value)` - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

**Follow up:**
Could you do both operations in O(1) time complexity?

**Example:**
```
LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
```

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
//    get: O(1)
//    put: O(1)
// Space: O(N)
class LRUCache {
private:
  list<pair<int, int>> data;
  unordered_map<int, list<pair<int, int>>::iterator> m;
  int capacity;
public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    auto it = m.find(key);
    if (it == m.end()) return -1;
    data.splice(data.begin(), data, it->second);
    m[key] = data.begin();
    return data.front().second;
  }

  void put(int key, int value) {
    if (!capacity) return;
    if (get(key) == -1) {
      if (data.size() == capacity) {
        auto p = data.back();
        m.erase(p.first);
        data.pop_back();
      }
      data.emplace_front(key, value);
      m[key] = data.begin();
    } else data.front().second = value;
  }
};
```