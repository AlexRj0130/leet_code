#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        init(matrix); 

        for (int i = 1; i < mMatSizeRow; ++i) {
            for (int j = 1; j < mMatSizeCol; ++j) {
                if (matrix[i][j] == '0') {
                    mMatSquare[i][j] = 0;
                } else {
                    mMatSquare[i][j] = min({mMatSquare[i - 1][j], mMatSquare[i][j - 1], mMatSquare[i - 1][j - 1]}) + 1;
                    mRes = max(mMatSquare[i][j], mRes);
                }
            }
        }

        return mRes * mRes;
    }
private:
    void init(const vector<vector<char>>& matrix) {
        mMatSizeRow = matrix.size();
        mMatSizeCol = matrix[0].size();

        mMatSquare = vector<vector<int>>(mMatSizeRow, vector<int>(mMatSizeCol, 0));

        for (int i = 0; i < mMatSizeRow; ++i) {
            mMatSquare[i][0] = matrix[i][0] - '0';
            mRes = max(mRes, mMatSquare[i][0]);
        }

        for (int j = 0; j < mMatSizeCol; ++j) {
            mMatSquare[0][j] = matrix[0][j] - '0';
            mRes = max(mRes, mMatSquare[0][j]);
        }
    }

private:
    int mMatSizeRow{0};
    int mMatSizeCol{0};
    vector<vector<int>> mMatSquare;
    int mRes{0};
};
// @lc code=end

