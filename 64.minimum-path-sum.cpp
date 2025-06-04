#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        init(grid);

        for (int i = 1; i < mRow; ++i) {
            for (int j = 1; j < mCol; ++j) {
                grid[i][j] = min(grid[i][j] + grid[i - 1][j], grid[i][j] + grid[i][j - 1]);
            }
        }
        return grid[mRow - 1][mCol - 1];
    }
private:
    void init(vector<vector<int>>& grid) {
        mRow = grid.size();
        mCol = grid[0].size();

        for (int i = 1; i < mCol; ++i) {
            grid[0][i] += grid[0][i - 1];
        }
        
        for (int i = 1; i < mRow; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
    }
private:
    int mRow{0};
    int mCol{0};
};
// @lc code=end

int main() {
    vector<vector<int>> data;
    data.push_back({1, 3, 1});
    data.push_back({1, 5, 1});
    data.push_back({4, 2, 1});
    
    Solution sol;
    auto res = sol.minPathSum(data);
    return 0;
}

