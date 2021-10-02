# [307. Range Sum Query - Mutable (Medium)](https://leetcode.com/problems/range-sum-query-mutable/)

<p>Given an integer array <i>nums</i>, find the sum of the elements between indices <i>i</i> and <i>j</i> (<i>i</i> ≤ <i>j</i>), inclusive.</p>

<p>The <i>update(i, val)</i> function modifies <i>nums</i> by updating the element at index <i>i</i> to <i>val</i>.</p>

<p><b>Example:</b></p>

<pre>Given nums = [1, 3, 5]

sumRange(0, 2) -&gt; 9
update(1, 2)
sumRange(0, 2) -&gt; 8
</pre>

<p><b>Note:</b></p>

<ol>
	<li>The array is only modifiable by the <i>update</i> function.</li>
	<li>You may assume the number of calls to <i>update</i> and <i>sumRange</i> function is distributed evenly.</li>
</ol>


**Related Topics**:  
[Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Segment Tree](https://leetcode.com/tag/segment-tree/)

**Similar Questions**:
* [Range Sum Query - Immutable (Easy)](https://leetcode.com/problems/range-sum-query-immutable/)
* [Range Sum Query 2D - Mutable (Hard)](https://leetcode.com/problems/range-sum-query-2d-mutable/)

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
    vector<int> sum;
    static inline int lowbit(int x) { return x & -x; }
public:
    BIT(int N) : sum(N + 1) {};
    void update(int i, int delta) {
        for (; i < sum.size(); i += lowbit(i)) sum[i] += delta;
    }
    int query(int i) {
        int ans = 0;
        for (; i; i -= lowbit(i)) ans += sum[i];
        return ans;
    }
    int rangeQuery(int i, int j) {
        return query(j) - query(i - 1);
    }
};
class NumArray {
    BIT tree;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) : nums(nums), tree(nums.size()) {
        for (int i = 0; i < nums.size(); ++i) tree.update(i + 1, nums[i]);
    }
    
    void update(int i, int val) {
        tree.update(i + 1, val - nums[i]);
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        return tree.rangeQuery(i + 1, j + 1);
    }
};
```