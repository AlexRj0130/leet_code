#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        initDpVec(m, n);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                mDpVec[i][j] = mDpVec[i - 1][j] + mDpVec[i][j - 1];
            }
        }
        return mDpVec[m-1][n-1];
    }

private:
    void initDpVec(int m, int n) {
        if (m <= 0 || n <= 0) {
            return;
        }

        mDpVec = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            mDpVec[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            mDpVec[0][j] = 1;
        }
    }
private:
    vector<vector<int>> mDpVec;
};
// @lc code=end

