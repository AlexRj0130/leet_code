#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m, j = nums1.size() - 1; i > 0; --i, --j) {
            nums1[j] = nums1[i - 1];
        }

        for (int i = 0, j = 0, k = 0; i < m || j < n; ++k) {
            if (i < m && j < n) {
                if (nums1[n+i] <= nums2[j]) {
                    nums1[k] = nums1[n+i];
                    ++i;
                } else {
                    nums1[k] = nums2[j++]; 
                }
            } else if (i < m) {
                nums1[k] = nums1[n+i];
                ++i;
            } else if (j < n) {
                nums1[k] = nums2[j++]; 
            }
        }
    }
};
// @lc code=end

