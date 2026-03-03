#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int maxRow = grid.size();
        int maxCol = maxRow == 0 ? 0 : grid[0].size();
        if (maxRow <= 0 || maxCol <= 0) {
            return 0;
        }
        
        int res = 0;
        for (int i = 0; i < maxRow; ++i) {
            for (int j = 0; j < maxCol; ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    dfs(grid, i,j, maxRow, maxCol);
                }
            }
        }

        return res;
    }

private:
    void dfs(vector<vector<char>>& grid, int row, int col, const int maxRow, const int maxCol) {
        if (row < 0 || row >= maxRow || col < 0 || col >= maxCol) {
            return;
        }

        if (grid[row][col] != '1') {
            return;
        }
        grid[row][col] = '#';

        dfs(grid, row, col + 1, maxRow, maxCol);
        dfs(grid, row, col - 1, maxRow, maxCol);
        dfs(grid, row - 1, col, maxRow, maxCol);
        dfs(grid, row + 1, col, maxRow, maxCol);
    }
};
// @lc code=end

int main() {
    vector<vector<char>> grid;
    grid.push_back(vector<char>{'1', '1', '1', '1', '0'});
    grid.push_back(vector<char>{'1', '1', '0', '1', '0'});
    grid.push_back(vector<char>{'1', '1', '0', '0', '0'});
    grid.push_back(vector<char>{'0', '0', '0', '0', '0'});

    Solution sol;
    sol.numIslands(grid);

    return 0;
}

