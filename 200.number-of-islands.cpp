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
        int rowSize = grid.size();
        if (rowSize <= 0) {
            return 0;
        }

        int colSize = grid[0].size();
        if (colSize <= 0) {
            return 0;
        }

        initGridMap(grid);

        int res = 1;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (markNext(gridMap, rowSize, colSize, i, j, res)) {
                    res = res+1;
                }
            }
        }
        
        return res - 1;
    }

private:
    bool markNext(vector<vector<int>>& grid, int rowSize, int colSize, int i, int j, int flag) {
        if (i >= rowSize || j >= colSize || i < 0 || j < 0) {
            return false;
        }

        if (grid[i][j] != -1) {
            return false;
        }

        grid[i][j] = flag;

        markNext(grid, rowSize, colSize, i - 1, j, flag); 
        markNext(grid, rowSize, colSize, i, j + 1, flag); 
        markNext(grid, rowSize, colSize, i + 1, j, flag);
        markNext(grid, rowSize, colSize, i, j - 1, flag);

        return true;
    }

    void initGridMap(const vector<vector<char>>& grid) {
        int rowSize = grid.size();
        if (rowSize <= 0) {
            return;
        }

        int colSize = grid[0].size();
        if (colSize <= 0) {
            return;
        } 


        for (int i = 0; i < rowSize; ++i) {
            vector<int> newRow; 
            for (int j = 0; j < colSize; ++j) {
                if (grid[i][j] == '1') {
                    newRow.push_back(-1);
                } else {
                    newRow.push_back(0);
                }
            }
            gridMap.push_back(newRow);
        }
    }

private:
    vector<vector<int>> gridMap;  
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

