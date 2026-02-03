#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        // 二分查找：缩小范围直到left == right
        while (left < right) {
            int mid = left + (right - left) / 2; // 避免(left+right)溢出
            if (nums[mid] > nums[right]) {
                // 最小值在mid右侧
                left = mid + 1;
            } else {
                // 最小值在mid左侧或就是mid
                right = mid;
            }
        }
        // 循环结束时left == right，即为最小值的索引
        return nums[left]; 
    }
};
// @lc code=end

