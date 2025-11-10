#include <vector>
#include <string>

using namespace std;

/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() <= 0) {
            return true;
        } 

        if (board.size() <= 0 || board[0].size() <= 0) {
            return false;
        }

        int rowSize = board.size(), colSize = board[0].size();
        vector<vector<bool>> record(rowSize, vector<bool>(colSize, false));
        
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (dfs(board, record, i, j, word, 0)) {
                    return true;
                }
            }
        } 

        return false;
    }

private:
    bool dfs(const vector<vector<char>>& board, vector<vector<bool>> &record, int row, int col, const string &word, int index) {
        int rowSize = board.size(), colSize = board[0].size();
        int wordSize = word.size();

        if (index >= wordSize) {
            return true;
        }

        if (row < 0 || row >= rowSize || col < 0 || col >= colSize) {
            return false;
        }

        if (record[row][col]) {
            return false;
        }

        if (board[row][col] != word[index]) {
            return false;
        }

        record[row][col] = true;
        if (dfs(board, record, row + 1, col, word, index + 1)) {
            return true;
        } else if (dfs(board, record, row, col + 1, word, index + 1)) {
            return true;
        } else if (dfs(board, record, row - 1, col, word, index + 1)) {
            return true;
        } else if (dfs(board, record, row, col - 1, word, index + 1)) {
            return true;
        } else {
            record[row][col] = false;
            return false;
        }
    }
};
// @lc code=end

