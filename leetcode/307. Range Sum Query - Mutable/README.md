# [307. Range Sum Query - Mutable (Medium)](https://leetcode.com/problems/range-sum-query-mutable)

<p>Given an integer array <code>nums</code>, handle multiple queries of the following types:</p>
<ol>
	<li><strong>Update</strong> the value of an element in <code>nums</code>.</li>
	<li>Calculate the <strong>sum</strong> of the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> <strong>inclusive</strong> where <code>left &lt;= right</code>.</li>
</ol>
<p>Implement the <code>NumArray</code> class:</p>
<ul>
	<li><code>NumArray(int[] nums)</code> Initializes the object with the integer array <code>nums</code>.</li>
	<li><code>void update(int index, int val)</code> <strong>Updates</strong> the value of <code>nums[index]</code> to be <code>val</code>.</li>
	<li><code>int sumRange(int left, int right)</code> Returns the <strong>sum</strong> of the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> <strong>inclusive</strong> (i.e. <code>nums[left] + nums[left + 1] + ... + nums[right]</code>).</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input</strong>
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
<strong>Output</strong>
[null, 9, null, 8]

<strong>Explanation</strong>
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>0 &lt;= index &lt; nums.length</code></li>
	<li><code>-100 &lt;= val &lt;= 100</code></li>
	<li><code>0 &lt;= left &lt;= right &lt; nums.length</code></li>
	<li>At most <code>3 * 10<sup>4</sup></code> calls will be made to <code>update</code> and <code>sumRange</code>.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Design](https://leetcode.com/tag/design/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Segment Tree](https://leetcode.com/tag/segment-tree/)

**Similar Questions**:
* [Range Sum Query - Immutable (Easy)](https://leetcode.com/problems/range-sum-query-immutable/)
* [Range Sum Query 2D - Mutable (Hard)](https://leetcode.com/problems/range-sum-query-2d-mutable/)
* [Shifting Letters II (Medium)](https://leetcode.com/problems/shifting-letters-ii/)

## Solution 1. Prefix Sum + Dirty Bit

Use `firstDirty` to denote the smallest index of the updated number.

When doing `sumRange`, we calculate the prefix sum from `firstDirty` to `nums.size()` and reset `firstDirty` to be `nums.size()`, then return the prefix sum.

Next time if we `sumRange` without any `update`, we can directly return the prefix sum.

```cpp
// OJ: https://leetcode.com/problems/range-sum-query-mutable/
// Author: github.com/lzl124631x
// Time:
//      NumArray: O(N)
//      update: O(1)
//      sumRange: O(N)
// Space: O(N)
class NumArray {
private:
    vector<int> sums;
    vector<int> nums;
    int firstDirty;
public:
    NumArray(vector<int> &nums) : sums(nums.size() + 1), nums(nums), firstDirty(0) {
    }

    void update(int i, int val) {
        nums[i] = val;
        firstDirty = min(firstDirty, i);
    }

    int sumRange(int i, int j) {
        if (firstDirty != nums.size()) {
            for (int i = firstDirty; i < nums.size(); ++i) {
                sums[i + 1] = sums[i] + nums[i];
            }
            firstDirty = nums.size();
        }
        return sums[j + 1] - sums[i];
    }
};
```

## Solution 2. SQRT decomposition

```cpp
// OJ: https://leetcode.com/problems/range-sum-query-mutable/
// Author: github.com/lzl124631x
// Time:
//      NumArray: O(N)
//      update: O(1)
//      sumRange: O(sqrt(N))
// Space: O(N)
// Ref: https://leetcode.com/problems/range-sum-query-mutable/solution/
class NumArray {
private:
    vector<int> sums;
    vector<int> nums;
    int len; // length of each section.
public:
    NumArray(vector<int> &nums) : nums(nums) {
        if (nums.empty()) return;
        len = ceil(sqrt(nums.size()));
        sums = vector<int>(ceil((double)nums.size() / len));
        for (int i = 0; i < nums.size(); ++i) {
            sums[i / len] += nums[i];
        }
    }

    void update(int i, int val) {
        sums[i / len] += val - nums[i];
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        int sum = 0, start = i / len, end = j / len;
        if (start == end) {
            while (i <= j) sum += nums[i++];
        } else {
            for (int k = (start + 1) * len - 1; k >= i; --k) sum += nums[k];
            for (int k = start + 1; k < end; ++k) sum += sums[k];
            for (int k = end * len; k <= j; ++k) sum += nums[k];
        }
        return sum;
    }
};
```

## Solution 3. Segment Tree

```cpp
// OJ: https://leetcode.com/problems/range-sum-query-mutable/
// Author: github.com/lzl124631x
// Time: 
//      NumArray: O(N)
//      update: O(1)
//      sumRange: O(logN)
// Space: O(N)
class NumArray {
    vector<int> tree;
    int N;
    void buildTree(vector<int> &nums) {
        for (int i = 0, j = N; i < N;) tree[j++] = nums[i++];
        for (int i = N - 1; i > 0; --i) tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        N = nums.size();
        tree = vector<int>(N * 2);
        buildTree(nums);
    }
    
    void update(int i, int val) {
        i += N;
        tree[i] = val;
        while (i > 0) {
            i /= 2;
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
    
    int sumRange(int i, int j) {
        i += N;
        j += N;
        int sum = 0;
        while (i <= j) {
            if (i % 2) sum += tree[i++];
            if (j % 2 == 0) sum += tree[j--];
            i /= 2;
            j /= 2;
        }
        return sum;
    }
};
```

## Solution 4. Segment Tree with OOD

```cpp
// OJ: https://leetcode.com/problems/range-sum-query-mutable/
// Author: github.com/lzl124631x
// Time: 
//      NumArray: O(N)
//      update: O(1)
//      sumRange: O(logN)
// Space: O(N
typedef int Merge(const int &a, const int& b);
class SegTree {
    vector<int> tree;
    int N;
    Merge *merge;
    void buildTree(vector<int> &nums) {
        for (int i = 0, j = N; i < N;) tree[j++] = nums[i++];
        for (int i = N - 1; i > 0; --i) tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
public:
    SegTree(vector<int> &nums, Merge merge) {
        N = nums.size();
        tree.resize(N * 2);
        this->merge = merge;
        buildTree(nums);
    }
    
    void update(int i, int val) {
        i += N;
        tree[i] = val;
        while (i > 0) {
            i /= 2;
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
        }
    }
    
    int query(int from, int to, int def) {
        int i = from + N, j = to + N;
        int ans = def;
        while (i <= j) {
            if (i % 2) ans = merge(ans, tree[i++]);
            if (j % 2 == 0) ans = merge(ans, tree[j--]);
            i /= 2;
            j /= 2;
        }
        return ans;
    }
};
class NumArray {
    SegTree* tree;
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        tree = new SegTree(nums, [](const int &a, const int &b) { return a + b; });
    }
    void update(int i, int val) {
        tree->update(i, val);
    }
    int sumRange(int i, int j) {
        return tree->query(i, j, 0);
    }
};
```

## Solution 5. Binary Indexed Tree

```cpp
// OJ: https://leetcode.com/problems/range-sum-query-mutable/
// Author: github.com/lzl124631x
// Time: 
//      NumArray: O(N^2 * logN)
//      update: O(logN)
//      sumRange: O(logN)
// Ref: https://www.youtube.com/watch?v=WbafSgetDDk
class BIT {
    vector<int> A;
    static inline int lb(int x) { return x & -x; }
public:
    BIT(vector<int> nums) : A(nums.size() + 1) {
        for (int i = 0; i < nums.size(); ++i) {
            update(i + 1, nums[i]);
        }
    }
    int query(int i) {
        int ans = 0;
        for (; i; i -= lb(i)) ans += A[i];
        return ans;
    }
    int rangeQuery(int i, int j) { // i, j are inclusive
        return query(j) - query(i - 1);
    }
    void update(int i, int delta) {
        for (; i < A.size(); i += lb(i)) A[i] += delta;
    }
};
class NumArray {
    BIT tree;
    vector<int> A;
public:
    NumArray(vector<int>& A) : A(A), tree(A) {}
    void update(int index, int val) {
        tree.update(index + 1, val - A[index]);
        A[index] = val;
    }
    int sumRange(int left, int right) {
        return tree.rangeQuery(left + 1, right + 1);
    }
};
```