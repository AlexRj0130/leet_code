#include <vector>
#include <queue>

using namespace std;

/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        auto rQueue = initRottenQueue(grid);

        int freshCount = countFresh(grid);
        int rottenCount = 0;
        int rottenTimes = 0;
        while (!rQueue.empty()) {
            int count = rottenOneTime(grid, rQueue); 
            if (count != 0) {
                ++rottenTimes;
                rottenCount += count;
            }
        }

        if (freshCount == rottenCount) {
            return rottenTimes;
        }
        return -1;
    }
private:
    int rottenOneTime(vector<vector<int>>& grid, queue<pair<int, int>> &rQueue) {
        int res = 0;
        if (rQueue.empty()) {
            return res;
        }

        auto srcRotten = rQueue.front();
        int targetRottenVal = grid[srcRotten.first][srcRotten.second] + 1;

        while (!rQueue.empty()) {
            auto srcRotten = rQueue.front();
            int row = srcRotten.first, col = srcRotten.second;
            int rottenVal = grid[row][col] + 1;
            if (rottenVal != targetRottenVal) {
                break;
            }
            rQueue.pop();

            // top
            int targetRow = row - 1, targetCol = col;
            if (targetRow >= 0 && targetRow < grid.size()
                && targetCol >= 0 && targetCol < grid[targetRow].size()
                && grid[targetRow][targetCol] == 1) {
                grid[targetRow][targetCol] = rottenVal;
                rQueue.push({targetRow, targetCol});
                ++res;
            }

            // down
            targetRow = row + 1, targetCol = col;
            if (targetRow >= 0 && targetRow < grid.size()
                && targetCol >= 0 && targetCol < grid[targetRow].size()
                && grid[targetRow][targetCol] == 1) {
                grid[targetRow][targetCol] = rottenVal;
                rQueue.push({targetRow, targetCol});
                ++res;
            }

            // left
            targetRow = row, targetCol = col - 1;
            if (targetRow >= 0 && targetRow < grid.size()
                && targetCol >= 0 && targetCol < grid[targetRow].size()
                && grid[targetRow][targetCol] == 1) {
                grid[targetRow][targetCol] = rottenVal;
                rQueue.push({targetRow, targetCol});
                ++res;
            }

            // right
            targetRow = row, targetCol = col + 1;
            if (targetRow >= 0 && targetRow < grid.size()
                && targetCol >= 0 && targetCol < grid[targetRow].size()
                && grid[targetRow][targetCol] == 1) {
                grid[targetRow][targetCol] = rottenVal;
                rQueue.push({targetRow, targetCol});
                ++res;
            }
        }
        
        return res;
    }

    int countFresh(const vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    ++res;
                }
            }
        }

        return res;
    }

    queue<pair<int, int>> initRottenQueue(const vector<vector<int>>& grid) {
        queue<pair<int, int>> rQueue;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 2) {
                    rQueue.push({i, j});
                }
            }
        }

        return rQueue;
    }
};
// @lc code=end

