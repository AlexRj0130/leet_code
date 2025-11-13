#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size(); 
        if (rowSize <= 0) {
            return false;
        }

        int colSize = matrix[0].size();
        if (colSize <= 0) {
            return false;
        }

        int i = 0, j = colSize - 1;
        while (i < rowSize && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }

        return false;
    }
};
// @lc code=end

