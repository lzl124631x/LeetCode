# [2336. Smallest Number in Infinite Set (Medium)](https://leetcode.com/problems/smallest-number-in-infinite-set)

<p>You have a set which contains all positive integers <code>[1, 2, 3, 4, 5, ...]</code>.</p>
<p>Implement the <code>SmallestInfiniteSet</code> class:</p>
<ul>
	<li><code>SmallestInfiniteSet()</code> Initializes the <strong>SmallestInfiniteSet</strong> object to contain <strong>all</strong> positive integers.</li>
	<li><code>int popSmallest()</code> <strong>Removes</strong> and returns the smallest integer contained in the infinite set.</li>
	<li><code>void addBack(int num)</code> <strong>Adds</strong> a positive integer <code>num</code> back into the infinite set, if it is <strong>not</strong> already in the infinite set.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input</strong>
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
<strong>Output</strong>
[null, null, 1, 2, 3, null, 1, 4, 5]

<strong>Explanation</strong>
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change is made.
smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the set and
                                   // is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= num &lt;= 1000</code></li>
	<li>At most <code>1000</code> calls will be made <strong>in total</strong> to <code>popSmallest</code> and <code>addBack</code>.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Design](https://leetcode.com/tag/design/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/)

**Similar Questions**:
* [First Missing Positive (Hard)](https://leetcode.com/problems/first-missing-positive/)

## Solution 1. Set of Available Intervals

```cpp
// OJ: https://leetcode.com/problems/smallest-number-in-infinite-set
// Author: github.com/lzl124631x
// Time:
//      SmallestInfiniteSet: O(1)
//      popSmallest, addBack: O(logN) where N is the number of addBack calls
// Space: O(N)
class SmallestInfiniteSet {
    set<pair<int, int>> s{{1, INT_MAX}};
public:
    int popSmallest() {
        auto it = s.begin();
        int ans = it->first, from = it->first + 1, to = it->second;
        s.erase(it);
        if (from <= to) s.emplace(from, to);
        return ans;
    }
    
    void addBack(int n) {
        auto it = upper_bound(begin(s), end(s), n, [](int target, auto &p) {
            return p.second >= target;
        });
        if (it->first <= n) return;
        int from = it->first, to = it->second;
        if (from == n + 1) {
            from--;
            if (it != s.begin()) {
                auto p = prev(it);
                int pfrom = p->first, pto = p->second;
                if (pto == from) {
                    it = s.erase(p);
                    s.erase(it);
                    from = pfrom;
                }
            } else s.erase(it);
            s.emplace(from, to);
        } else if (it != s.begin() && prev(it)->second == n - 1) {
            auto p = prev(it);
            int from = p->first, to = p->second + 1;
            s.erase(p);
            s.emplace(from, to);
        } else {
            s.insert({n, n});
        }
    }
};
```

## Solution 2. Heap + Set

```cpp
// OJ: https://leetcode.com/problems/smallest-number-in-infinite-set
// Author: github.com/lzl124631x
// Time:
//      SmallestInfiniteSet: O(1)
//      popSmallest, addBack: O(logN) where N is the number of addBack calls.
// Space: O(N)
class SmallestInfiniteSet {
    unordered_set<int> present; // set of added back numbers
    priority_queue<int, vector<int>, greater<>> added; // min-heap of added back numbers
    int cur = 1;
public:
    int popSmallest() {
        int ans;
        if (added.size()) {
            ans = added.top();
            added.pop();
            present.erase(ans);
        } else {
            ans = cur++;
        }
        return ans;
    }
    
    void addBack(int n) {
        if (cur <= n || present.count(n)) return;
        added.push(n);
        present.insert(n);
    }
};
```

## Solution 3. Set

```cpp
// OJ: https://leetcode.com/problems/smallest-number-in-infinite-set
// Author: github.com/lzl124631x
// Time:
//      SmallestInfiniteSet: O(1)
//      popSmallest, addBack: O(logN) where N is the number of addBack calls.
// Space: O(N)
class SmallestInfiniteSet {
    set<int> added;
    int cur = 1;
public:
    int popSmallest() {
        int ans;
        if (added.size()) {
            ans = *added.begin();
            added.erase(added.begin());
        } else {
            ans = cur++;
        }
        return ans;
    }
    
    void addBack(int n) {
        if (cur <= n || added.count(n)) return;
        added.insert(n);
    }
};
```