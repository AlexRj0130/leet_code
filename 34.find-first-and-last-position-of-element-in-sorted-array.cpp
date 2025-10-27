#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() <= 0) {
            return {-1, -1};
        } 

        int resLeft = -1, resRight = -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int midVal = nums[mid];

            if (midVal >= target) {
                if (midVal == target) {
                    resLeft = mid;
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (resLeft == -1) {
            return {-1, -1};
        }

        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int midVal = nums[mid];

            if (midVal <= target) {
                if (midVal == target) {
                    resRight = mid;
                }
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return {resLeft, resRight};
    }
};
// @lc code=end

