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

        int res = 0; 
        int lMax = 0, rMax = 0;
        int lIndex = 0, rIndex = height.size() - 1;
        while (lIndex < rIndex) {
            if (height[lIndex] < height[rIndex]) {
                if (height[lIndex] >= lMax) {
                    lMax = height[lIndex];
                } else {
                    res += (lMax - height[lIndex]);
                }
                ++lIndex;
            } else {
                if (height[rIndex] >= rMax) {
                    rMax = height[rIndex];
                } else {
                    res += (rMax - height[rIndex]);
                }
                --rIndex;
            }
        }

        return res;
    }
};
// @lc code=end

