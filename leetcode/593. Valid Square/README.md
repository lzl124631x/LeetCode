# [593. Valid Square (Medium)](https://leetcode.com/problems/valid-square/)

<p>Given the coordinates of four points in 2D space, return whether the four points could construct a square.</p>

<p>The coordinate (x,y) of a point is represented by an integer array with two integers.</p>

<p><b>Example:</b></p>

<pre><b>Input:</b> p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
<b>Output:</b> True
</pre>

<p>&nbsp;</p>

<p>Note:</p>

<ol>
	<li>All the input integers are in the range [-10000, 10000].</li>
	<li>A valid square has four equal sides with positive length and four equal angles (90-degree angles).</li>
	<li>Input points have no order.</li>
</ol>

<p>&nbsp;</p>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

Compute the squared distance (SD) between each pair of points. The points form a square if:
* only two unique SDs
* the smaller SD appears 4 times and the greater SD appears 2 times.
* the greater SD equals the smaller one times 2.

```cpp
// OJ: https://leetcode.com/problems/valid-square/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
    long long dist(vector<int>& a, vector<int>& b) {
        return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<long long, int> m;
        vector<vector<int>> v = {p1, p2, p3, p4};
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                auto d = dist(v[i], v[j]);
                if (!d) return false;
                m[d]++;
            }
        }
        auto a = *m.begin(), b = *m.rbegin();
        return m.size() == 2 && a.second == 4 && 2 * a.first == b.first;
    }
};
```

## Solution 2.

Since the input points are all of integer values, we don't need to consider case like `(0,0),(0,2),(-1,√3),(1,√3)`.

Thus, we can simplify the check to: as long as there is no `0` SD and there are only two unique SDs.

```cpp
// OJ: https://leetcode.com/problems/valid-square/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/valid-square/discuss/103442/C%2B%2B-3-lines-(unordered_set)
class Solution {
private:
    long long d(vector<int>& a, vector<int>& b) {
        return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<long long> s({ d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4) });
        return !s.count(0) && s.size() == 2;
    }
};
```

## Solution 3.

Assume `b` and `c` are two adjacent nodes to `a` and `ad` forms a diagonal line, then we can return `true` if the following two are true.

* `ab = ac = bd = cd`
* `(by-ay)/(bx-ax) = -1 / ((cy-ay)/(cx-ax)) = (cx-ax)/(cy-ay)`, so `(by-ay)*(cy-ay) = -(bx-ax)*(cx-ax)`

We need to enumerate 3 cases where `ad`, `ac`, `ab` are diagonal lines respectively.

```cpp
class Solution {
    double dist(vector<int> &a, vector<int> &b) {
        return sqrt(pow((double)a[0] - b[0], 2) + pow((double)a[1] - b[1], 2));
    }
    bool valid(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        if (a == b) return false;
        double ab = dist(a, b), ac = dist(a, c), bd = dist(b, d), cd = dist(c, d);
        return ab == ac && ab == bd && ab == cd && (b[1] - a[1]) * (c[1] - a[1]) == -1 * (c[0] - a[0]) * (b[0] - a[0]);
    }
public:
    bool validSquare(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        return valid(a, b, c, d) || valid(a, c, b, d) || valid(a, b, d, c) || valid(a, c, d, b);
    }
};
```