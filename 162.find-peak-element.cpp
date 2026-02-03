#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        // 二分查找：不使用 left <= right，避免死循环
        while (left < right) {
            int mid = left + (right - left) / 2; // 避免溢出，等价于 (left+right)/2
            if (nums[mid] < nums[mid + 1]) {
                // 右侧有峰值，移动左边界
                left = mid + 1;
            } else {
                // 左侧（含mid）有峰值，移动右边界
                right = mid;
            }
        }
        // 最终 left == right，即为峰值索引
        return left;
    }
};
// @lc code=end

