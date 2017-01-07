class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> index;
        int maxArea = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!index.empty() && heights[index.top()] >= heights[i]) {
                int h = heights[index.top()];
                index.pop();
                int j = index.size() > 0 ? index.top() : -1;
                maxArea = max(maxArea, h * (i - j - 1));
            }
            index.push(i);
        }
        return maxArea;
    }
};