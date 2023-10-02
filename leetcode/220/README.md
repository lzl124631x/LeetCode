# [220. Contains Duplicate III (Medium)](https://leetcode.com/problems/contains-duplicate-iii/)

<p>Given an array of integers, find out whether there are two distinct indices <i>i</i> and <i>j</i> in the array such that the <b>absolute</b> difference between <b>nums[i]</b> and <b>nums[j]</b> is at most <i>t</i> and the <b>absolute</b> difference between <i>i</i> and <i>j</i> is at most <i>k</i>.</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-1-1">[1,2,3,1]</span>, k = <span id="example-input-1-2">3</span>, t = <span id="example-input-1-3">0</span>
<strong>Output: </strong><span id="example-output-1">true</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-2-1">[1,0,1,1]</span>, k = <span id="example-input-2-2">1</span>, t = <span id="example-input-2-3">2</span>
<strong>Output: </strong><span id="example-output-2">true</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-3-1">[1,5,9,1,5,9]</span>, k = <span id="example-input-3-2">2</span>, t = <span id="example-input-3-3">3</span>
<strong>Output: </strong><span id="example-output-3">false</span>
</pre>
</div>
</div>
</div>

**Related Topics**:  
[Sort](https://leetcode.com/tag/sort/), [Ordered Map](https://leetcode.com/tag/ordered-map/)

**Similar Questions**:
* [Contains Duplicate (Easy)](https://leetcode.com/problems/contains-duplicate/)
* [Contains Duplicate II (Easy)](https://leetcode.com/problems/contains-duplicate-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/contains-duplicate-iii/
// Author: github.com/lzl124631x
// Time: O(NlogK)
// Space: O(K)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& A, int k, int t) {
        if (t < 0) return false;
        multiset<long> s;
        for (int i = 0; i < A.size(); ++i) {
            if (i > k) s.erase(s.find(A[i - k - 1]));
            if (s.lower_bound((long)A[i] - t) != s.upper_bound((long)A[i] + t)) return true;
            s.insert(A[i]);
        }
        return false;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/contains-duplicate-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
// Ref: https://leetcode.com/problems/contains-duplicate-iii/discuss/61645/AC-O(N)-solution-in-Java-using-buckets-with-explanation
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& A, int k, int t) {
        if (A.size() < 2 || k < 1 || t < 0) return false;
        unordered_map<long, long> m;
        for (int i = 0; i < A.size(); ++i) {
            if (i > k) m.erase(((long)A[i - k - 1] - INT_MIN) / ((long)t + 1));
            long n = (long)A[i] - INT_MIN, id = n / ((long)t + 1);
            if (m.count(id) || (m.count(id - 1) && A[i] - m[id - 1] <= t) || (m.count(id + 1) && m[id + 1] - A[i] <= t)) return true; 
            m[id] = A[i];
        }
        return false;
    }
};
```