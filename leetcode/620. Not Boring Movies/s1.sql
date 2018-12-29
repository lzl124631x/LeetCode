# OJ: https://leetcode.com/problems/not-boring-movies/
# Author: github.com/lzl124631x
SELECT
    *
FROM
    cinema
WHERE
    MOD(id, 2) = 1 AND description != 'boring'
ORDER BY rating DESC