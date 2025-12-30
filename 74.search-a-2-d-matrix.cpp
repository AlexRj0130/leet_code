#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m <= 0) return false; 

        int n = matrix[0].size();
        if (n <= 0) return false;

        int left = 0, right = m - 1, targetRow = -1, lastCol = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid][lastCol] >= target) {
                if (matrix[mid][lastCol] == target) {
                    return true;
                }
                targetRow = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (targetRow < 0) {
            return false;
        }

        left = 0, right = n - 1;
        int targetCol = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[targetRow][mid] >= target) {
                if (matrix[targetRow][mid] == target) {
                    return true;
                }
                targetCol = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return targetCol == -1 ? false : matrix[targetRow][targetCol] == target;
    }
};
// @lc code=end

