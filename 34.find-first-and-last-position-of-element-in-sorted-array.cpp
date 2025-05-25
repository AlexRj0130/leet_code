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
        auto left = binSearch(nums, target, true);
        auto right = binSearch(nums, target, false);
        return vector<int>{left, right};
    }
private:
    int binSearch(vector<int>& nums, int target, bool searchLeft) {
        int left = 0, right = nums.size() - 1;
        int res = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                res = mid;
                if (searchLeft) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target ) {
                left = mid + 1; 
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};
// @lc code=end

