# OJ: https://leetcode.com/problems/triangle-judgement/
# Author: github.com/lzl124631x
SELECT
    x, y, z,
    CASE
        WHEN x + y > z AND x + z > y AND y + z > x THEN 'Yes'
        ELSE 'No'
    END AS 'triangle'
FROM
    triangle