# OJ: https://leetcode.com/problems/big-countries/
# Author: github.com/lzl124631x
SELECT
    name, population, area
FROM
    world
WHERE
    population > 25000000 OR area > 3000000