// OJ: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, cnt = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (i >= k) sum -= arr[i - k];
            if (i + 1 >= k && sum / k >= threshold) ++cnt;
        }
        return cnt;
    }
};