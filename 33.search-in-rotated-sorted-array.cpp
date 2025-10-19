#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() <= 0) {
            return -1;
        } 

        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        } 

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[left] == target) {
                return left;
            }

            if (nums[right] == target) {
                return right;
            }

            if (nums[left] < nums[right]) {
                if (target < nums[left] || target > nums[right]) {
                    return -1;
                }

                if (target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
                continue;
            } else {
                if (nums[left] < nums[mid]) {
                    if (target >= nums[left] && target <= nums[mid]) {
                        right = mid;
                        continue;
                    }
                    left = mid + 1;
                } else {
                    if (target >= nums[mid] && target <= nums[right]) {
                        left = mid;
                        continue;
                    }
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
// @lc code=end

