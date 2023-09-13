# [733. Flood Fill (Easy)](https://leetcode.com/problems/flood-fill/)

<p>
An <code>image</code> is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
</p><p>
Given a coordinate <code>(sr, sc)</code> representing the starting pixel (row and column) of the flood fill, and a pixel value <code>newColor</code>, "flood fill" the image.
</p><p>
To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on.  Replace the color of all of the aforementioned pixels with the newColor.
</p><p>
At the end, return the modified image.
</p>
<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
<b>Output:</b> [[2,2,2],[2,2,0],[2,0,1]]
<b>Explanation:</b> 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
</pre>
<p></p>

<p><b>Note:</b>
</p><li>The length of <code>image</code> and <code>image[0]</code> will be in the range <code>[1, 50]</code>.</li>
<li>The given starting pixel will satisfy <code>0 &lt;= sr &lt; image.length</code> and <code>0 &lt;= sc &lt; image[0].length</code>.</li>
<li>The value of each color in <code>image[i][j]</code> and <code>newColor</code> will be an integer in <code>[0, 65535]</code>.</li>
<p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Island Perimeter (Easy)](https://leetcode.com/problems/island-perimeter/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/flood-fill/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
private:
    int M, N, color, dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (sr < 0 || sr >= M || sc < 0 || sc >= N || image[sr][sc] != color) return;
        image[sr][sc] = newColor;
        for (auto dir : dirs) {
            dfs(image, sr + dir[0], sc + dir[1], newColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        color = image[sr][sc];
        if (color == newColor) return image;
        M = image.size();
        N = image[0].size();
        dfs(image, sr, sc, newColor);
        return image;
    }
};
```