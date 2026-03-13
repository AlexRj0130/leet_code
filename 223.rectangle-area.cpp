#include <algorithm>

using namespace std;
/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int aw = max((ax2 - ax1), 0); 
        int ah = max((ay2 - ay1), 0);
        int bw = max((bx2 - bx1), 0);
        int bh = max((by2 - by1), 0);

        int cx1 = max(ax1, bx1);
        int cy1 = max(ay1, by1);
        int cx2 = min(ax2, bx2);
        int cy2 = min(ay2, by2);
        int cw = max((cx2 - cx1), 0);
        int ch = max((cy2 - cy1), 0);

        return aw * ah + bw * bh - cw * ch;
    }
};
// @lc code=end

