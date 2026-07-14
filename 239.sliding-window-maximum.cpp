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
        deque<int> qWindow;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            while ((!qWindow.empty()) && nums[qWindow.back()] <= nums[i]) {
                qWindow.pop_back();
            }
            qWindow.push_back(i);

            if (i < k - 1) {
                continue;
            }

            int leftIndex = i - k + 1;
            while (qWindow.front() < leftIndex) {
                qWindow.pop_front();
            }

            res.push_back(nums[qWindow.front()]);
        }

        return res;
    }
private:

};
// @lc code=end

int main() {
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    Solution sol;
    auto res = sol.maxSlidingWindow(nums, 3);
    return 0;
}

