#include <vector>
#include <limits>

using namespace std;

/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1); // 这里调换顺序，是为了第 25 行代码一定有意义。
        } 

        int m = nums1.size(), n = nums2.size();
        int totalLeft = (m + n + 1) / 2; // 分割点一定要满足的要求，即分走所有数据的一半。
        int iMin = 0, iMax = m;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2; // 在 nums1 中尝试进行分割。
            int j = totalLeft - i; // 由于 m 一定小于等于 n，所以，totalLeft - i 一定大于等于 0。
            int nums1Left = (i <= 0 ? std::numeric_limits<int>::min() : nums1[i-1]);
            int nums1Right = (i >= m ? std::numeric_limits<int>::max() : nums1[i]);
            int nums2Left = (j <= 0 ? std::numeric_limits<int>::min() : nums2[j - 1]);
            int nums2Right = (j >= n ? std::numeric_limits<int>::max() : nums2[j]);

            if (nums1Left > nums2Right) {
                iMax = i - 1;
            } else if (nums2Left > nums1Right) {
                iMin = i + 1;
            } else {
                int maxLeft = max(nums1Left, nums2Left);
                int minRight = min(nums1Right, nums2Right);
                if ((m + n) % 2) {
                    return maxLeft;
                } else {
                    return (double(maxLeft) + double(minRight)) / 2;
                }
            }
        } 

        return -1;
    }
};
// @lc code=end

