#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        mMatSizeRow = matrix.size(); 
        mMatSizeCol = matrix[0].size();
        mDpMatSumVec = vector<vector<int>>(mMatSizeRow + 1, vector<int>(mMatSizeCol + 1, 0));

        for (int i = 1; i <= mMatSizeRow; ++i) {
            for (int j = 1; j <= mMatSizeCol; ++j) {
                mDpMatSumVec[i][j] = matrix[i - 1][j - 1] + 
                    mDpMatSumVec[i - 1][j] + mDpMatSumVec[i][j - 1] - 
                    mDpMatSumVec[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return mDpMatSumVec[row2 + 1][col2 + 1] - mDpMatSumVec[row1][col2 + 1] - mDpMatSumVec[row2 + 1][col1] + mDpMatSumVec[row1][col1];
    }
private:
    vector<vector<int>> mDpMatSumVec;
    int mMatSizeRow;
    int mMatSizeCol;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

