# OJ: https://leetcode.com/problems/consecutive-available-seats/
# Author: github.com/lzl124631x
SELECT DISTINCT
    a.seat_id
FROM
    cinema a JOIN cinema b
    ON ABS(a.seat_id - b.seat_id) = 1
    and a.free = true and b.free = true
ORDER BY a.seat_id