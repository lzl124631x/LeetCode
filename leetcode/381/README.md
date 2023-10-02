# [381. Insert Delete GetRandom O(1) - Duplicates allowed (Hard)](https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/)

<p>Design a data structure that supports all following operations in <i>average</i> <b>O(1)</b> time.</p>
<b>Note: Duplicate elements are allowed.</b>
<p>
</p><ol>
<li><code>insert(val)</code>: Inserts an item val to the collection.</li>
<li><code>remove(val)</code>: Removes an item val from the collection if present.</li>
<li><code>getRandom</code>: Returns a random element from current collection of elements. The probability of each element being returned is <b>linearly related</b> to the number of same value the collection contains.</li>
</ol>
<p></p>

<p><b>Example:</b>
</p><pre>// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
</pre>
<p></p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Insert Delete GetRandom O(1) (Medium)](https://leetcode.com/problems/insert-delete-getrandom-o1/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(N)
class RandomizedCollection {
    vector<pair<int, int>> v; // value, index among the numbers of the same value
    unordered_map<int, vector<int>> m; // value to indexes in `v`
public:
    RandomizedCollection() {}
    bool insert(int val) {
        bool ans = m.count(val);
        m[val].push_back(v.size());
        v.emplace_back(val, m[val].size() - 1);
        return ans;
    }
    bool remove(int val) {
        auto it = m.find(val);
        if (it == m.end()) return false;
        auto &last = v.back();
        m[last.first][last.second] = m[val].back();
        v[m[val].back()] = last;
        m[val].pop_back();
        if (m[val].empty()) m.erase(val);
        v.pop_back();
        return true;
    }
    int getRandom() {
        return v[rand() % v.size()].first;
    }
};
```