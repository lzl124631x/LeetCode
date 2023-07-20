# [735. Asteroid Collision (Medium)](https://leetcode.com/problems/asteroid-collision)

<p>We are given an array <code>asteroids</code> of integers representing asteroids in a row.</p>
<p>For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.</p>
<p>Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> asteroids = [5,10,-5]
<strong>Output:</strong> [5,10]
<strong>Explanation:</strong> The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> asteroids = [8,-8]
<strong>Output:</strong> []
<strong>Explanation:</strong> The 8 and -8 collide exploding each other.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> asteroids = [10,2,-5]
<strong>Output:</strong> [10]
<strong>Explanation:</strong> The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= asteroids.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= asteroids[i] &lt;= 1000</code></li>
	<li><code>asteroids[i] != 0</code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [DoorDash](https://leetcode.com/company/doordash)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Stack](https://leetcode.com/tag/stack/), [Simulation](https://leetcode.com/tag/simulation/)

**Similar Questions**:
* [Can Place Flowers (Easy)](https://leetcode.com/problems/can-place-flowers/)
* [Destroying Asteroids (Medium)](https://leetcode.com/problems/destroying-asteroids/)
* [Count Collisions on a Road (Medium)](https://leetcode.com/problems/count-collisions-on-a-road/)
* [Robot Collisions (Hard)](https://leetcode.com/problems/robot-collisions/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/asteroid-collision/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        vector<int> ans;
        for (int n : A) {
            if (ans.empty() || ans.back() < 0 || n > 0) ans.push_back(n);
            else {
                while (ans.size() && ans.back() > 0 && ans.back() < -n) ans.pop_back();
                if (ans.size() && ans.back() == -n) ans.pop_back();
                else if (ans.empty() || ans.back() < 0) ans.push_back(n);
            }
        }
        return ans;
    }
};
```