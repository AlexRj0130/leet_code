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
        int colSize = rowSize <= 0 ? 0 : matrix[0].size();

        int row = 0, col = colSize - 1;
        while (row < rowSize && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                ++row;
            } else {
                --col;
            }
        }

        return false;
    }
};
// @lc code=end

