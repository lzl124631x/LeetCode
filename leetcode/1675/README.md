# [1675. Minimize Deviation in Array (Hard)](https://leetcode.com/problems/minimize-deviation-in-array)

<p>You are given an array <code>nums</code> of <code>n</code> positive integers.</p>

<p>You can perform two types of operations on any element of the array any number of times:</p>

<ul>
	<li>If the element is <strong>even</strong>, <strong>divide</strong> it by <code>2</code>.
	<ul>
		<li>For example, if the array is <code>[1,2,3,4]</code>, then you can do this operation on the last element, and the array will be <code>[1,2,3,<u>2</u>].</code></li>
	</ul>
	</li>
	<li>If the element is <strong>odd</strong>, <strong>multiply</strong> it by <code>2</code>.
	<ul>
		<li>For example, if the array is <code>[1,2,3,4]</code>, then you can do this operation on the first element, and the array will be <code>[<u>2</u>,2,3,4].</code></li>
	</ul>
	</li>
</ul>

<p>The <strong>deviation</strong> of the array is the <strong>maximum difference</strong> between any two elements in the array.</p>

<p>Return <em>the <strong>minimum deviation</strong> the array can have after performing some number of operations.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> 1
<strong>Explanation:</strong> You can transform the array to [1,2,3,<u>2</u>], then to [<u>2</u>,2,3,2], then the deviation will be 3 - 2 = 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,1,5,20,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You can transform the array after two operations to [4,<u>2</u>,5,<u>5</u>,3], then the deviation will be 5 - 2 = 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,10,8]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 5 * 10<sup><span style="font-size: 10.8333px;">4</span></sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[Samsung](https://leetcode.com/company/samsung)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Greedy](https://leetcode.com/tag/greedy), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue), [Ordered Set](https://leetcode.com/tag/ordered-set)

**Hints**:
* Assume you start with the minimum possible value for each number so you can only multiply a number by 2 till it reaches its maximum possible value.
* If there is a better solution than the current one, then it must have either its maximum value less than the current maximum value, or the minimum value larger than the current minimum value.
* Since that we only increase numbers (multiply them by 2), we cannot decrease the current maximum value, so we must multiply the current minimum number by 2.

## Solution 1. Reuse solution to 632

For each `A[i]`, there is a limited number of transformed numbers.

Take `[1,2,3,4]` for example,

```
1 -> [1, 2]
2 -> [1, 2]
3 -> [3, 6]
4 -> [1, 2, 4]
```

And the problem can be transformed as follows:

For each `A[i]`, pick a transformed number. In this way we will get a group of `N` numbers. Find a group what can minimize the maximum difference of the group.

This is exactly [632. Smallest Range Covering Elements from K Lists (Hard)](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/).

### Time complexity

Generating the transformed array `B` takes `O(NlogC)` time where `C` is the maximum number in `A`.

The solution to 632 takes `O(NK * logN)` where `K` is the maximum length of `B[i]`, i.e. `logC`.

So overall the time complexity is `O(NlogN * logC)`.

```cpp
// OJ: https://leetcode.com/problems/minimize-deviation-in-array/
// Author: github.com/lzl124631x
// Time: O(NlogN * logC) where C is the maximum number in A
// Space: O(NlogC)
class Solution {
public:
    int minimumDeviation(vector<int>& A) {
        int N = A.size();
        vector<vector<int>> B(N);
        for (int i = 0; i < N; ++i) {
            int x = A[i];
            B[i].push_back(x);
            if (x % 2 == 0) {
                while (x % 2 == 0) {
                    B[i].push_back(x / 2);
                    x /= 2;
                }
                reverse(begin(B[i]), end(B[i]));
            } else B[i].push_back(2 * x);
        }
        int mx = INT_MIN, ans = INT_MAX;
        vector<int> next(N);
        auto cmp = [&](int a, int b) { return B[a][next[a]] > B[b][next[b]]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < N; ++i) {
            pq.push(i);
            mx = max(mx, B[i][0]);
        }
        while (true) {
            int i = pq.top();
            pq.pop();
            ans = min(ans, mx - B[i][next[i]]);
            if (++next[i] == B[i].size()) break;
            mx = max(mx, B[i][next[i]]);
            pq.push(i);
        }
        return ans;
    }
};
```

## Solution 2.

Instead of storing all the transformed values, we just need to store the lower bound and upper bound of the transformed values.

For a even number `n`, we divide it by `2` until it becomes a odd number, say `k`, so the lower and upper bounds are `k`, `n`, respectively.

For an odd number `n`, the lower and upper bounds are `n` and `2n` respectively.

We push these ranges into a min heap `pq`. Now we can ignore the parity of the numbers in the min heap, we just need to uniformly increase the lower bound numbers towards the upper bound.

We use a `mx` to store the maximum value of all the **lower bound** values in the min heap.

Each time we pop a range with minimal lower bound. The current range of all the lower bounds in the min heap including the one just popped is `mx - pq.top().first`.

We multiply the lower bound by 2, and update the `mx` value and push the new lower bound with its upper bound back into the `pq`.

We stop until `2 * lower_bound` exceeds upper bound.

### Time complexity

We initialize the min heap by pushing `N` times, so it takes `O(NlogN)` time.

Each value in the min heap at most increases `O(logC)` times where `C` is the maximum value in `A`. So in the worst case we need to increase `O(NlogC)` times. Each time we need to push/pop into/from a min heap of size `N` which takes `O(logN)`.

So overall the time complexity is `O(NlogN * logC)`.

```cpp
// OJ: https://leetcode.com/problems/minimize-deviation-in-array/
// Author: github.com/lzl124631x
// Time: O(NlogN * logC)
// Space: O(N)
// Ref: https://leetcode.com/problems/minimize-deviation-in-array/discuss/952819/Python-Priority-queue-and-record-the-lower-and-upper-bound
class Solution {
public:
    int minimumDeviation(vector<int>& A) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int mx = INT_MIN;
        for (int n : A) {
            if (n % 2 == 0) {
                int upper = n;
                while (n % 2 == 0) n /= 2;
                pq.emplace(n, upper);
            } else pq.emplace(n, 2 * n);
            mx = max(mx, n);
        }
        int ans = INT_MAX;
        while (true) {
            auto [val, upper] = pq.top();
            pq.pop();
            ans = min(ans, mx - val);
            mx = max(mx, 2 * val);
            if (2 * val > upper) break;
            pq.emplace(2 * val, upper);
        }
        return ans;
    }
};
```

## Solution 3. 

Solution 2 is increasing the number. But if we turn odd numbers `n` to `2n` and decrease the numbers, we don't need to care about the lower bound because the lower bound is always met when the number becomes odd.

```cpp
// OJ: https://leetcode.com/problems/minimize-deviation-in-array/
// Author: github.com/lzl124631x
// Time: O(NlogN * logC)
// Space: O(N)
class Solution {
public:
    int minimumDeviation(vector<int>& A) {
        int N = A.size(), ans = INT_MAX, mn = INT_MAX; // `mn` is the minimum number within the max heap
        priority_queue<int> pq;
        for (int n : A) {
            if (n % 2) n *= 2;
            pq.push(n);
            mn = min(mn, n);
        }
        while (true) {
            int mx = pq.top();
            pq.pop();
            ans = min(ans, mx - mn);
            if (mx % 2) break;
            mx /= 2;
            mn = min(mn, mx);
            pq.push(mx);
        }
        return ans;
    }
};
```