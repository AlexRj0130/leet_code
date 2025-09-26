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
        return binSearch(nums, target, 0, nums.size() - 1); 
    }

private:
    int binSearch(const vector<int>& nums, int target, int start, int end) {
        if (nums.size() <= 0 || start > end) {
            return -1;
        }

        if (start == end) {
            return nums[start] == target ? start : -1;
        }

        auto mid = (start + end) / 2;


        if (nums[start] <= nums[mid]) {
            if (target >= nums[start] && target <= nums[mid]) {
                return binSearch(nums, target, start, mid);
            }
            return binSearch(nums, target, mid+1, end);
        } else {
            if (target >= nums[mid + 1] && target <= nums[end]) {
                return binSearch(nums, target, mid + 1, end);
            }
            return binSearch(nums, target, start, mid);
        }
    }
};
// @lc code=end

