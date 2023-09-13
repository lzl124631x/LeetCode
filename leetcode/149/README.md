# [149. Max Points on a Line (Hard)](https://leetcode.com/problems/max-points-on-a-line/)

Given _n_ points on a 2D plane, find the maximum number of points that lie on the same straight line.

**Example 1:**

**Input:** \[\[1,1\],\[2,2\],\[3,3\]\]  
**Output:** 3  
**Explanation:**
```
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
```

**Example 2:**

**Input:** \[\[1,1\],\[3,2\],\[5,3\],\[4,1\],\[2,3\],\[1,4\]\]  
**Output:** 4  
**Explanation:**
```
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
```

## Solution 1. 

Firstly, assume there are no duplicate points. 

We keep a list of lines, each of which is a list of points on that line. We push the first line which is formed by the first two points `a` and `b` into it. So now the `lines` becomes:
```
(a, b)
```

Then we visit the other points one by one. For the third point `c`, we traverse through the `lines` and see if `c` is in any of the lines.

Assume `c` is not on line `(a, b)`, we add `(a, c)` and `(b, c)` to the `lines`.
```
(a, b)
(a, c)
(b, c)
```

For the next point `d`, assume `d` is on line `(b, c)` but not on the other lines, then add `d` into this line.

```
(a, b)
(a, c)
(b, c, d)
```

And at the same time we know `b` and `c` are `d`'s neighbor (i.e. they are on the same line), and `a` is not `d`'s neighbor. So we add line `(a, d)` to the `lines`.
```
(a, b)
(a, c)
(b, c, d)
(a, d)
```

We keep visiting the points in this way. The final result will be the length of longest line.

Now, what if our assumption "there are no duplicate points" is wrong? Just merge the same points into one entry, and take a note of its count. The other logics are the same.

```cpp
// OJ: https://leetcode.com/problems/max-points-on-a-line/
// Author: github.com/lzl124631x
// Time: O(N^3)
//   In worse case, when visiting ith point, there will be O(i^2)
//   lines, but all the lines are of constant size 2. So in
//   sum it's O(N^3), not O(N^4).
// Space: O(N^2)
namespace std {
    template <> struct hash<Point> {
        std::size_t operator () (const Point &p) const {
            return hash<int>()(p.x) ^ hash<int>()(p.y);
        }
    };
}

bool operator==(const Point& a, const Point& b) {
	return a.x == b.x && a.y == b.y;
}

class Solution {
private:
    bool onSameLine(Point &a, Point &b, Point &c) {
        return (long long)(a.x - b.x) * (a.y - c.y) == (long long)(a.x - c.x) * (a.y - b.y);
    }
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) return points.size();
        unordered_map<Point, int> m;
        for (auto p : points) m[p]++;
        vector<pair<Point, int>> ps(m.begin(), m.end());
        vector<vector<int>> lines(1, vector<int>{ 0, 1 });
        int N = ps.size();
        for (int i = 2; i < N; ++i) {
            auto &p = ps[i].first;
            vector<int> bad(i, 1);
            for (auto &line : lines) {
                auto &p1 = ps[line[0]].first, &p2 = ps[line[1]].first;
                if (!onSameLine(p1, p2, p)) continue;
                for (int neighbor : line) bad[neighbor] = 0;
                line.push_back(i);
            }
            for (int j = 0; j < i; ++j) {
                if (bad[j]) lines.emplace_back(vector<int>{ j, i });
            }
        }
        int ans = 2;
        for (auto line : lines) {
            int cnt = 0;
            for (auto i : line) cnt += ps[i].second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```