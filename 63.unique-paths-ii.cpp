#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        init(obstacleGrid);
        for (int i = 1; i < obstacleGrid.size(); ++i) {
            for (int j = 1; j < obstacleGrid[0].size(); ++j) {
                if (obstacleGrid[i][j] > 0) {
                    continue;
                }

                int sum = 0;
                if (obstacleGrid[i][j - 1] < 0) {
                    sum += obstacleGrid[i][j - 1];
                }
                if (obstacleGrid[i - 1][j] < 0) {
                    sum += obstacleGrid[i - 1][j];
                }
                obstacleGrid[i][j] = sum;
            }
        }

        int res = obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
        return res < 0 ? 0 - res : 0;
    }

private:
    void init(vector<vector<int>>& obstacleGrid) {
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            if (obstacleGrid[i][0] > 0) {
                break;
            }
            obstacleGrid[i][0] = -1;
        }

        for (int j = 0; j < obstacleGrid[0].size(); ++j) {
            if (obstacleGrid[0][j] > 0) {
                break;
            }
            obstacleGrid[0][j] = -1;
        }
    }
};
// @lc code=end

int main() {
    vector<vector<int>> data;
    data.push_back({0, 0, 0});
    data.push_back({0, 1, 0});
    data.push_back({0, 0, 0});

    Solution sol;
    auto res = sol.uniquePathsWithObstacles(data);
}

