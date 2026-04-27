#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() <= 0) return {};
        if (matrix[0].size() <= 0) return {}; 

        int rowSize = matrix.size(), colSize = matrix[0].size();

        vector<int> res;
        vector<vector<bool>> recordFlag(rowSize, vector<bool>(colSize, true));

        int count = 0, totalCount = rowSize * colSize;
        int row = 0, col = 0;
        while (count < totalCount) {
            count += move(row, col, 0, 1, rowSize, colSize, recordFlag, matrix, res);
            col -= 1, row += 1;
            if (count >= totalCount) break;
            count += move(row, col, 1, 0, rowSize, colSize, recordFlag, matrix, res);
            row -= 1, col -= 1;
            if (count >= totalCount) break;
            count += move(row, col, 0, -1, rowSize, colSize, recordFlag, matrix, res);
            col += 1, row -= 1;
            if (count >= totalCount) break;
            count += move(row, col, -1, 0, rowSize, colSize, recordFlag, matrix, res);
            row += 1, col += 1;
            if (count >= totalCount) break;
        }
        return res;
    }
private:
    int move(int &row, int &col, const int rowStep, const int colStep, const int rowSize, const int colSize, vector<vector<bool>> & recordFlag, vector<vector<int>>& matrix, vector<int> & res) {
        int count = 0;
        while (row >= 0 && row < rowSize && col >= 0 && col < colSize && recordFlag[row][col]) {
            ++count;
            recordFlag[row][col] = false;
            res.push_back(matrix[row][col]);
            row += rowStep;
            col += colStep;
        }
        return count;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    Solution sol;
    auto res =  sol.spiralOrder(matrix);
    return 0;
}
