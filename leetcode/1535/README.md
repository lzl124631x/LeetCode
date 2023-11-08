# [1535. Find the Winner of an Array Game (Medium)](https://leetcode.com/problems/find-the-winner-of-an-array-game)

<p>Given an integer array <code>arr</code> of <strong>distinct</strong> integers and an integer <code>k</code>.</p>

<p>A game will be played between the first two elements of the array (i.e. <code>arr[0]</code> and <code>arr[1]</code>). In each round of the game, we compare <code>arr[0]</code> with <code>arr[1]</code>, the larger integer wins and remains at position <code>0</code>, and the smaller integer moves to the end of the array. The game ends when an integer wins <code>k</code> consecutive rounds.</p>

<p>Return <em>the integer which will win the game</em>.</p>

<p>It is <strong>guaranteed</strong> that there will be a winner of the game.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,1,3,5,4,6,7], k = 2
<strong>Output:</strong> 5
<strong>Explanation:</strong> Let&#39;s see the rounds of the game:
Round |       arr       | winner | win_count
  1   | [2,1,3,5,4,6,7] | 2      | 1
  2   | [2,3,5,4,6,7,1] | 3      | 1
  3   | [3,5,4,6,7,1,2] | 5      | 1
  4   | [5,4,6,7,1,2,3] | 5      | 2
So we can see that 4 rounds will be played and 5 is the winner because it wins 2 consecutive games.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [3,2,1], k = 10
<strong>Output:</strong> 3
<strong>Explanation:</strong> 3 will win the first 10 rounds consecutively.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>arr</code> contains <strong>distinct</strong> integers.</li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[spinny](https://leetcode.com/company/spinny), [Directi](https://leetcode.com/company/directi)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Simulation](https://leetcode.com/tag/simulation)

**Hints**:
* If k ≥ arr.length return the max element of the array.
* If k < arr.length simulate the game until a number wins k consecutive games.

## Solution 1. Queue

Just simulate the process. Because once we visit the maximum number in the array, we'll at most visit the entire array one more time, so the time complexity is `O(N)`.

Note that if we found that one number has beaten other `N - 1` numbers already, we don't need to continue the loop and this maximum number must be the result.

Actually just using a `queue` is enough, but `queue` doesn't support initialization using `queue<int> q(begin(A), end(A))`.

```cpp
// OJ: https://leetcode.com/problems/find-the-winner-of-an-array-game/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int getWinner(vector<int>& A, int k) {
        deque<int> q(begin(A), end(A));
        int N = A.size(), x = q.front(), cnt = 0;
        q.pop_front();
        while (cnt < k && cnt < N - 1) {
            int y = q.front();
            q.pop_front();
            if (x > y) {
                ++cnt;
                q.push_back(y);
            } else {
                cnt = 1;
                q.push_back(x);
                x = y;
            }
        }
        return x;
    }
};
```

## Solution 2. Monotonic stack (Next Greater Element)

Let `next[i]` be the index of the next element greater than `A[i]`(in a cyclic manner). For example, `[3,1,2]`'s `next` array is `[-1,2,0]`.

We can use a monotonic stack to calculate the `next` array. This stack contains indices whose corresponding values are monotonically decreasing. Whenever we see a greater element `A[i]`, we pop all the smaller elements `A[j]` from the stack, and assign `next[j] = i`.

After the `next` array is calculated, we find the first winning element from left to right. The winning criteria is one of the following:
* `next[i] = -1` meaning that this is the greatest element in array.
* `next[i] - i - (i == 0) >= k` meaning that this element can have more than `k` consecutive wins. `next[i] - i - 1` is the smaller elements between `A[i]` and `A[next[i]]`. For any `i > 0`, we need to `+1` considering `A[i]` wins an element to it's left. Even if `A[i] (i > 0)` can't win any of the elements to its left, we can still safely `+1` because there must be a greater element to `A[i]`'s left and has a greater number of consecutive winning dominating `next[i] - i - (i == 0)`.

```cpp
// OJ: https://leetcode.com/problems/find-the-winner-of-an-array-game/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int getWinner(vector<int>& A, int k) {
        int N = A.size();
        if (k >= N - 1) return *max_element(begin(A), end(A));
        vector<int> next(N, -1);
        stack<int> s; // decreasing monotonic stack
        for (int i = 0; i < 2 * N; ++i) {
            while (s.size() && A[s.top() % N] < A[i % N]) {
                next[s.top() % N] = i % N;
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < N; ++i) {
            if (next[i] == -1 || next[i] - i - (i == 0) >= k) return A[i];
        }
        return -1;
    }
};
```

## Solution 3. One pass

One key observation is that after comparing all the elements first pass, we don't need to compare the current winning element from the beginning of the array again because we must meet the greatest element in the first pass which will definitely win the game.

```cpp
// OJ: https://leetcode.com/problems/find-the-winner-of-an-array-game/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/find-the-winner-of-an-array-game/discuss/768007/JavaC%2B%2BPython-One-Pass-O(1)-Space
class Solution {
public:
    int getWinner(vector<int>& A, int k) {
        int cur = A[0], win = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > cur) {
                cur = A[i];
                win = 0;
            }
            if (++win == k) break;
        }
        return cur;
    }
};
```