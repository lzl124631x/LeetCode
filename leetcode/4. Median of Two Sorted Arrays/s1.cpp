// OJ: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author: github.com/lzl124631x
// Time: O(log(min(M, N)))
// Space: O(1)
// Ref: https://leetcode.com/problems/median-of-two-sorted-arrays/solution/
// Ref: https://youtu.be/LPFhl65R7ww
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int M = nums1.size(), N = nums2.size(), L = 0, R = M, K = (M + N + 1) / 2;
        while (true) {
            int i = (L + R) / 2, j = K - i;
            if (i < M && nums2[j - 1] > nums1[i]) L = i + 1;
            else if (i > L && nums1[i - 1] > nums2[j]) R = i - 1;
            else {
                int maxLeft = max(i ? nums1[i - 1] : INT_MIN, j ? nums2[j - 1] : INT_MIN);
                if ((M + N) % 2) return maxLeft;
                int minRight = min(i == M ? INT_MAX : nums1[i], j == N ? INT_MAX : nums2[j]);
                return (maxLeft + minRight) / 2.0;
            }
        }
    }
};