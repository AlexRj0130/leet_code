#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return; // 空矩阵直接返回
        int m = board.size(), n = board[0].size();
        
        // 步骤1：遍历四条边界，标记所有连通的O为#
        // 第一行和最后一行
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m-1][j] == 'O') dfs(board, m-1, j);
        }
        // 第一列和最后一列（排除已遍历的行首尾）
        for (int i = 1; i < m-1; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        
        // 步骤2：还原标记 + 替换被围绕的O
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '#') board[i][j] = 'O'; // 还原标记的O
                else if (board[i][j] == 'O') board[i][j] = 'X'; // 替换被围绕的O
            }
        }
    }
private:
    // DFS：将当前位置及连通的O标记为#
    void dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size(), n = board[0].size();
        // 边界检查 + 不是O则返回
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
        board[i][j] = '#'; // 标记为临时字符
        // 递归遍历上下左右四个方向
        dfs(board, i-1, j); // 上
        dfs(board, i+1, j); // 下
        dfs(board, i, j-1); // 左
        dfs(board, i, j+1); // 右
    }
};
// @lc code=end

