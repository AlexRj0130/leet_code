#include <vector>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k <= 0) {
            return {};
        } 

        if (k == 1) {
            return nums;
        }

        vector<int> res;
        deque<int> window;
        for (int i = 0; i < nums.size(); ++i) {
            // 1.移除队列后部所有小于等于当前值的值。
            while (!window.empty() && nums[window.back()] <= nums[i]) {
                window.pop_back();
            }
            window.push_back(i);

            // 2.移除窗口外的值
            while (!window.empty() && window.front() <= (i - k)) {
                window.pop_front();
            }

            // 3.窗口达到大小时，记录窗口内的最大值
            if (i >= k - 1) {
                res.push_back(nums[window.front()]);
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    Solution sol;
    auto res = sol.maxSlidingWindow(nums, 3);
    return 0;
}

