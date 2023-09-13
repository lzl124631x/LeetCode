# [613. Shortest Distance in a Line (Easy)](https://leetcode.com/problems/shortest-distance-in-a-line/)

<a class="sql-schema-link__1HYH">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__3Su4"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a>

## Solution 1.

```sql
# OJ: https://leetcode.com/problems/shortest-distance-in-a-line/
# Author: github.com/lzl124631x
SELECT
    MIN(ABS(p1.x - p2.x)) AS shortest
FROM
    point p1
        JOIN
    point p2 ON p1.x != p2.x
```