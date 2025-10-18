#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 1) {
            return 0;
        } 

        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);
        for (int i = 1, j = height.size() - 2; i < height.size(); ++i, --j) {
            leftMax[i] = max(leftMax[i-1], height[i-1]);
            rightMax[j] = max(rightMax[j + 1], height[j+1]);
        }

        int res = 0;
        for (int i = 1; i < height.size() - 1; ++i) {
            int minTmp = min(leftMax[i], rightMax[i]);
            int resItem = minTmp - height[i];
            if (resItem > 0) {
                res += resItem;
            }
        }

        return res;
    }
};
// @lc code=end

