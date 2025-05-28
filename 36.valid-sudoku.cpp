#include <vector>
#include <array>
#include <unordered_set>
 
using namespace std;

/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9]; 
        unordered_set<char> col[9];
        unordered_set<char> block[9];
        
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j) {
                auto val = board[i][j];
                if (val == '.') {
                    continue;
                }

                int blockIndex = (i / 3) + (j / 3) * 3;
                if (row[i].count(val) || col[j].count(val) || block[blockIndex].count(val)) {
                    return false;
                }

                row[i].insert(val);
                col[j].insert(val);
                block[blockIndex].insert(val);
            }
        }
        return true;
    }
};
// @lc code=end

