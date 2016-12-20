class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> v;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                v.push_back(i + 1);
            }
        }
        return v;
    }
};

// Explanation: nums[i] should be at nums[nums[i] - 1].
// If it's not, swap nums[i] and nums[nums[i] - 1]
// So as to make nums[nums[i] - 1] be at its right place.
// It will end in two cases:
// 1. i == nums[i] - 1, i.e. nums[i] is at the right place
// 2. (nums[i] - 1) + 1 == nums[nums[i] - 1] where nums[i] != i + 1
// i.e. nums[i] and nums[nums[i] - 1] are no longer swappable.

// Original solution:
// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         for (int i = 0; i < nums.size();) {
//             if (nums[i] - 1 != i) {
//                 if (nums[nums[i] - 1] == nums[i]) {
//                     nums[i] = 0;
//                     ++i;
//                 } else {
//                     swap(nums[i], nums[nums[i] - 1]);
//                 }
//             } else {
//                 ++i;
//             }
//         }
//         vector<int> v;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (!nums[i]) {
//                 v.push_back(i + 1);
//             }
//         }
//         return v;
//     }
// };