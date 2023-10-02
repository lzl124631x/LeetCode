# [620. Not Boring Movies (Easy)](https://leetcode.com/problems/not-boring-movies/)

X city opened a new cinema, many people would like to go to this cinema.
The cinema also gives out a poster indicating the movies’ ratings and descriptions. <p>
 
Please write a SQL query to output movies with an odd numbered ID and a description that is not 'boring'. Order the result by rating.
</p><p>
</p><p>
For example, table <code>cinema</code>:
</p><pre>+---------+-----------+--------------+-----------+
|   id    | movie     |  description |  rating   |
+---------+-----------+--------------+-----------+
|   1     | War       |   great 3D   |   8.9     |
|   2     | Science   |   fiction    |   8.5     |
|   3     | irish     |   boring     |   6.2     |
|   4     | Ice song  |   Fantacy    |   8.6     |
|   5     | House card|   Interesting|   9.1     |
+---------+-----------+--------------+-----------+
</pre>
For the example above, the output should be:
<pre>+---------+-----------+--------------+-----------+
|   id    | movie     |  description |  rating   |
+---------+-----------+--------------+-----------+
|   5     | House card|   Interesting|   9.1     |
|   1     | War       |   great 3D   |   8.9     |
+---------+-----------+--------------+-----------+
</pre>
<p></p>

**Companies**:  
[Adobe](https://leetcode.com/company/adobe)

## Solution 1.

```sql
# OJ: https://leetcode.com/problems/not-boring-movies/
# Author: github.com/lzl124631x
SELECT
    *
FROM
    cinema
WHERE
    MOD(id, 2) = 1 AND description != 'boring'
ORDER BY rating DESC
```