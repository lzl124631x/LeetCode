class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int N = height.size();
        for (int i = N - 1; i >= 0; --i) {
            if (s.empty() || height[i] > height[s.top()]) s.push(i);
        }
        int ans = 0;
        for (int i = 0; i < N - 1;) {
            int h = height[i];
            if (i == s.top()) {
                s.pop();
                h = height[s.top()];
            }
            int j = i + 1;
            while (j < N && height[j] < h) ans += h - height[j++];
            i = j;
        }
        return ans;
    }
};